import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Vector;


public class Main {
    static final int threshold = 30;
    static final int numberOfThreads = 5;

    // The size of the neighbourhood in which to search for other local maxima
    static final int neighbourhoodSize = 4;

    // How many discrete values of theta shall we check
    static final int maxTheta = 180;

    public static void main(String[] args) throws Exception {
        String fileNameInputImage = "images/box.png";
        houghThreads(fileNameInputImage);
    }



    static void houghThreads(String fileNameInputImage) throws InterruptedException, IOException {
        long startThreads = System.currentTimeMillis();

        // Read image
        BufferedImage image = ImageIO.read(new File(fileNameInputImage));

        // Create a hough transform object with the right dimensions
        HoughTransform houghTransform = new HoughTransform(image.getWidth(), image.getHeight(), image);
        houghTransform.initialise();

        // Add the points from the image in the space and construct the accumulator
        houghTransform.addPoints();

        // Add image from hough space
        Vector<HLine> lines = HoughTransform.getLines();

        // Draw the lines
        drawLines(image, lines);
        long endThreads = System.currentTimeMillis();
        System.out.println("Thread performance: " + (endThreads - startThreads));
    }

    private static void drawLines(BufferedImage image, Vector<HLine> lines) throws IOException {
        for (int j = 0; j < lines.size(); j++) {
            HLine line = lines.elementAt(j);
            line.drawLine(image, Color.BLUE.getRGB());
        }

        ImageIO.write(image, "PNG", new File("images/houghTransform.png"));
    }
}
