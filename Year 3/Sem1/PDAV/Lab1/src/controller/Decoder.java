package controller;

import domain.Block;
import domain.PPM;

import java.io.IOException;
import java.util.List;

public class Decoder {
    private PPM img;
    private Operations ops = new Operations();
    private List<Block> yBlocks;
    private List<Block> uBlocks;
    private List<Block> vBlocks;
    double[][] y;
    double[][] u;
    double[][] v;

    public Decoder(List<Block> yBlocks, List<Block> uBlocks, List<Block> vBlocks) {
        this.yBlocks = yBlocks;
        this.uBlocks = uBlocks;
        this.vBlocks = vBlocks;
    }

    public void decode() {
        List<Block> dequantY = ops.deQuantizationPhase(yBlocks);
        List<Block> dequantU = ops.deQuantizationPhase(uBlocks);
        List<Block> dequantV = ops.deQuantizationPhase(vBlocks);

        List<Block> yDCT = ops.inverseDCT(dequantY);
        List<Block> uDCT = ops.inverseDCT(dequantU);
        List<Block> vDCT = ops.inverseDCT(dequantV);

        List<Block> Yadd128 = ops.add128(yDCT);
        List<Block> Uadd128 = ops.add128(uDCT);
        List<Block> Vadd128 = ops.add128(vDCT);

        //List<Block> decompressedU = operations.blocksToMatrices(uBlocks);
        //List<Block> decompressedV = operations.blocksToMatrices(vBlocks);
        y = ops.reconstructMatrix(Yadd128);
        u = ops.reconstructMatrix(Uadd128);
        v = ops.reconstructMatrix(Vadd128);
    }

    public void createDecodedImage(String format, int maxVal, int width, int height) throws IOException {
        PPM img = new PPM();
        img.setFile("images/decoded-nt-P3.ppm");
        img.setFormat(format);
        img.setMaxVal(maxVal);
        img.setWidth(width);
        img.setHeight(height);
        img.setY(y);
        img.setU(u);
        img.setV(v);
        img = img.YUV_RGB();
        img.writePPM();
    }
}
