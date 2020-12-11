package controller;

import domain.Block;
import domain.PPM;

import java.io.IOException;
import java.util.List;

public class Encoder {
    private PPM img;
    private Operations ops;
    private List<Block> quantY;
    private List<Block> quantU;
    private List<Block> quantV;

    public Encoder(PPM img) throws IOException {
        this.img = img;
        this.ops = new Operations();
    }

    public void encodeFirst() throws IOException {
        this.img.readPPM();
        this.img.generateRGB();
        this.img.RGB_YUV();
    }

    public List<Block> getYBlocks() {
        return ops.matrix_block(this.img, this.img.getY(), "Y");
    }

    public List<Block> getUBlocks() {
        return ops.matrix_block(this.img, this.img.getU(), "U");
    }

    public List<Block> getVBlocks() {
        return ops.matrix_block(this.img, this.img.getV(), "V");
    }

    public void encodeSecond(List<Block> yBlocks, List<Block> uBlocks, List<Block> vBlocks) {
        List<Block> decompressedU = ops.block_matrix(uBlocks);
        List<Block> decompressedV = ops.block_matrix(vBlocks);

        List<Block> Ysub128 = ops.sub128(yBlocks);
        List<Block> Usub128 = ops.sub128(decompressedU);
        List<Block> Vsub128 = ops.sub128(decompressedV);

        List<Block> yDCT = ops.forwardDCT(Ysub128);
        List<Block> uDCT = ops.forwardDCT(Usub128);
        List<Block> vDCT = ops.forwardDCT(Vsub128);

        this.quantY = ops.quantizationPhase(yDCT);
        this.quantU = ops.quantizationPhase(uDCT);
        this.quantV = ops.quantizationPhase(vDCT);
    }

    public List<Block> getQuantY() { return quantY; }

    public List<Block> getQuantU() {
        return quantU;
    }

    public List<Block> getQuantV() {
        return quantV;
    }
}
