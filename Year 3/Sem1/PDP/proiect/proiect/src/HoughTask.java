import java.awt.image.BufferedImage;


public class HoughTask implements Runnable {
    private BufferedImage image;
    private int x;

    HoughTask(int x, BufferedImage image) {
        this.x = x;
        this.image = image;
    }

    @Override
    public void run() {
        for (int y = 0; y < image.getHeight(); y++) {
            HoughTransform.addPoint(x, y, image);
        }
    }
}
