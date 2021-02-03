import java.awt.image.BufferedImage;
import java.io.Serializable;
import java.util.Vector;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;


class HoughTransform extends Thread implements Serializable {
    // Using maxTheta, work out the step 
    private static final double thetaStep = Math.PI / Main.maxTheta;

    private static int width, height;
    private static BufferedImage image;
    private static int[][] houghArray;
    private static float centerX, centerY; // the coordinates of the centre of the image
    private static int houghHeight;
    private static int doubleHeight;
    private static int numberOfPoints; // visible drawn points in the image

    // Cache of values of sin and cos for different theta values
    private static double[] sinCache;
    private static double[] cosCache;

    HoughTransform(int width, int height, BufferedImage image) {
        this.width = width;
        this.height = height;
        this.image = image;
    }

    void initialise() {
        // maximum height of the hough array
        houghHeight = (int) (Math.sqrt(2) * Math.max(height, width)) / 2;

        // Double the height of the hough array to cope with negative r values 
        doubleHeight = 2 * houghHeight;

        // Create the hough array / accumulation array
        houghArray = new int[Main.maxTheta][doubleHeight];

        // center of the image
        centerX = (float) width / 2;
        centerY = (float) height / 2;

        numberOfPoints = 0;

        sinCache = new double[Main.maxTheta];
        cosCache = new double[Main.maxTheta];
        for (int t = 0; t < Main.maxTheta; t++) {
            double realTheta = t * thetaStep;
            sinCache[t] = Math.sin(realTheta);
            cosCache[t] = Math.cos(realTheta);
        }
    }

    void addPoints() throws InterruptedException {
        // Find edge points and update the hough array
        ExecutorService executor = Executors.newFixedThreadPool(Main.numberOfThreads);
        for (int x = 0; x < image.getWidth(); x++) {
            HoughTask task = new HoughTask(x, image);
            executor.submit(task);
        }
        executor.shutdown();
        executor.awaitTermination(50, TimeUnit.SECONDS);
    }

    static void addPoint(int x, int y, BufferedImage image) {
        // Find non-black pixels
        //urss 0xff0000
        if ((image.getRGB(x, y) & 0x000000ff) == 0) {
            return;
        }

        // Go through each value of theta 
        for (int t = 0; t < Main.maxTheta; t++) {
            //Calculate r for each theta
            int r = (int) (((x - centerX) * cosCache[t]) + ((y - centerY) * sinCache[t]));

            // this copes with negative values of r 
            r += houghHeight;

            if (r < 0 || r >= doubleHeight) continue;

            // Increment the hough array / increase value in the accumulator for (theta, r)
            houghArray[t][r]++;
        }
        numberOfPoints++;
    }

    /**
     * Once points have been added in some way this method extracts the lines and returns them as a Vector
     * of HoughLine objects, which can be used to draw the result
     */
    static Vector<HLine> getLines() {
        // Initialise the vector
        Vector<HLine> lines = new Vector<HLine>(0);

        // Only proceed if the hough array is not empty
        if (numberOfPoints == 0) return lines;

        // Search for local peaks above threshold to drawLine
        // we search the peak for each theta
        for (int t = 0; t < Main.maxTheta; t++) {
            loop:
            for (int r = Main.neighbourhoodSize; r < doubleHeight - Main.neighbourhoodSize; r++) {
                // Only consider points above threshold
                if (houghArray[t][r] > Main.threshold) {
                    int peak = houghArray[t][r];

                    // Check that this peak is indeed the local maxima (check the neighbourhood
                    for (int dx = -Main.neighbourhoodSize; dx <= Main.neighbourhoodSize; dx++) {
                        for (int dy = -Main.neighbourhoodSize; dy <= Main.neighbourhoodSize; dy++) {
                            int dt = t + dx;
                            int dr = r + dy;
                            if (dt < 0) dt = dt + Main.maxTheta;
                            else if (dt >= Main.maxTheta) dt = dt - Main.maxTheta;
                            if (houghArray[dt][dr] > peak) {
                                // found a bigger point nearby, skip
                                continue loop;
                            }
                        }
                    }

                    // Calculate the true value of theta
                    double theta = t * thetaStep;

                    // Add the line to the vector
                    lines.add(new HLine(theta, r));
                }
            }
        }
        return lines;
    }

} 
 
