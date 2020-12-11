package domain;
import java.util.Arrays;

public class Block {
    private String type;
    private int size;
    private int xCoordinate;
    private int yCoordinate;
    private int initialWidth;
    private int initialHeight;
    private double[][] block;
    private int[][] intsBlock;

    public Block(int size, String type){
        this.size = size;
        this.type = type;
        this.block = new double[size][size];
        this.intsBlock = new int[size][size];
    }

    @Override
    public String toString() {
        return "Block{" +
                "blockType='" + type + '\'' +
                ", xCoordinate=" + xCoordinate +
                ", yCoordinate=" + yCoordinate +
                ", block=" + Arrays.deepToString(block) +
                '}';
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int getXCoordinate() {
        return xCoordinate;
    }

    public void setXCoordinate(int xCoordinate) {
        this.xCoordinate = xCoordinate;
    }

    public int getYCoordinate() {
        return yCoordinate;
    }

    public void setYCoordinate(int yCoordinate) {
        this.yCoordinate = yCoordinate;
    }

    public int getInitialWidth() {
        return initialWidth;
    }

    public void setInitialWidth(int initialWidth) {
        this.initialWidth = initialWidth;
    }

    public int getInitialHeight() {
        return initialHeight;
    }

    public void setInitialHeight(int initialHeight) {
        this.initialHeight = initialHeight;
    }

    public double[][] getBlock() {
        return block;
    }

    public void setBlock(double[][] block) {
        this.block = block;
    }

    public int[][] getIntsBlock() {
        return intsBlock;
    }

    public void setIntsBlock(int[][] intsBlock) {
        this.intsBlock = intsBlock;
    }
}
