import controller.Decoder;
import controller.Encoder;
import domain.PPM;

import domain.Block;
import java.io.IOException;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        PPM ppm = new PPM("images/nt-P3.ppm");
        Encoder encoder = new Encoder(ppm);
        encoder.encodeFirst();

        List<Block> yBlocks = encoder.getYBlocks();
        List<Block> uBlocks = encoder.getUBlocks();
        List<Block> vBlocks = encoder.getVBlocks();

        encoder.encodeSecond(yBlocks, uBlocks, vBlocks);

        List<Block> yBlocksQuantized = encoder.getQuantY();
        List<Block> uBlocksQuantized = encoder.getQuantU();
        List<Block> vBlocksQuantized = encoder.getQuantV();

        //Decoder decoder = new Decoder(yBlocks, uBlocks, vBlocks);
        Decoder decoder = new Decoder(yBlocksQuantized, uBlocksQuantized, vBlocksQuantized);
        decoder.decode();
        decoder.createDecodedImage(ppm.getFormat(), ppm.getMaxVal(), ppm.getWidth(), ppm.getHeight());
    }
}
