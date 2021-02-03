import java.awt.image.BufferedImage;
import java.io.Serializable;

/*
 * Represents a linear line as detected by the hough transform.
 * This line is represented by an angle theta and a radius from the centre.
 */
class HLine implements Serializable {
    private double theta;
    private double r;

    HLine(double theta, double r) {
        this.theta = theta; // the resulted angle
        this.r = r; // the resulted radius from the centre
    }

    void drawLine(BufferedImage image, int color) {
        // image height and width
        int height = image.getHeight();
        int width = image.getWidth();

        // diagonal length of the image
        int houghHeight = (int) (Math.sqrt(2) * Math.max(height, width)) / 2;

        // Find image center coordinates
        float centerX = (float) width / 2;
        float centerY = (float) height / 2;

        // find sin and cos of theta
        double sinTheta = Math.sin(theta);
        double cosTheta = Math.cos(theta);

        // theta >= pi/4 and theta <= 3pi/4
        // between 45 and 135 degrees, the lines are more vertical than horizontal
        // outside 45 and 135 degrees, the lines are more horizontal than vertical
        if (theta >= 45 && theta <= 135) {
            // Draw vertical lines
            for (int y = 0; y < height; y++) {
                int x = (int) ((((r - houghHeight) - ((y - centerY) * sinTheta)) / cosTheta) + centerX);
                if (x < width && x >= 0) {
                    image.setRGB(x, y, color);
                }
            }
        } else {
            // Draw horizontal lines
            for (int x = 0; x < width; x++) {
                int y = (int) ((((r - houghHeight) - ((x - centerX) * cosTheta)) / sinTheta) + centerY);
                if (y < height && y >= 0) {
                    image.setRGB(x, y, color);
                }
            }
        }
    }

    @Override
    public String toString() {
        return "Line with " +
                "theta=" + theta +
                "; r=" + r ;
    }
}
