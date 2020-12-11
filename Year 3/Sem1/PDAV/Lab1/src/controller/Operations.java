package controller;

import domain.Block;
import domain.PPM;

import java.util.ArrayList;
import java.util.List;

class Operations {
    // Quantization matrix
    private double[][] Q = {
            {6, 4, 4, 6, 10, 16, 20, 24},
            {5, 5, 6, 8, 10, 23, 24, 22},
            {6, 5, 6, 10, 16, 23, 28, 22},
            {6, 7, 9, 12, 20, 35, 32, 25},
            {7, 9, 15, 22, 27, 44, 41, 31},
            {10, 14, 22, 26, 32, 42, 45, 37},
            {20, 26, 31, 35, 41, 48, 48, 40},
            {29, 37, 38, 39, 45, 40, 41, 40}
    };

    private double[][] matrix8x8(int x, int y, double[][] YMatrix) {
        double[][] res = new double[8][8];
        for(int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                res[i][j] = YMatrix[x + i][y + j];
            }
        }
        return res;
    }

    private double[][] matrix4x4(int x, int y, double[][] UVMatrix){
        double[][] subMatrix = this.matrix8x8(x, y, UVMatrix);
        double[][] res = new double[4][4];
        int line = 0;
        int column = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                res[i][j] = (subMatrix[line][column] +
                        subMatrix[line + 1][column] +
                        subMatrix[line][column + 1] +
                        subMatrix[line + 1][column + 1]) / 4.0;
                column += 2;
            }
            line += 2;
            column = 0;
        }
        return res;
    }
    List<Block> matrix_block(PPM image, double[][] matrix, String type){
        List<Block> blocks = new ArrayList<>();
        for(int i = 0; i < image.getHeight(); i = i + 8) {
            for (int j = 0; j < image.getWidth(); j = j + 8) {
                double[][] elems;
                int size;
                if (type.equals("Y")) {
                    size = 8;
                    elems = matrix8x8(i, j, matrix);
                } else {
                    size = 4;
                    elems = matrix4x4(i, j, matrix);
                }
                Block block = new Block(size, type);
                block.setInitialHeight(image.getHeight());
                block.setInitialWidth(image.getWidth());
                block.setBlock(elems);
                block.setXCoordinate(i);
                block.setYCoordinate(j);
                blocks.add(block);
            }
        }
        return blocks;
    }

    List<Block> block_matrix(List<Block> blocks) {
        List<Block> blocksToMatrices = new ArrayList<>();
        blocks.forEach(block -> blocksToMatrices.add(matrix8x8(block)));
        return blocksToMatrices;
    }

    private Block matrix8x8(Block initialBlock){
        Block newBlock = new Block(8, initialBlock.getType());
        newBlock.setInitialWidth(initialBlock.getInitialWidth());
        newBlock.setInitialHeight(initialBlock.getInitialHeight());
        newBlock.setXCoordinate(initialBlock.getXCoordinate());
        newBlock.setYCoordinate(initialBlock.getYCoordinate());
        newBlock.setXCoordinate(initialBlock.getXCoordinate());
        newBlock.setYCoordinate(initialBlock.getYCoordinate());
        double[][] elems = new double[8][8];
        double[][] oldMatrix = initialBlock.getBlock();
        int line = 0;
        int column = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                elems[line][column] = oldMatrix[i][j];
                elems[line + 1][column] = oldMatrix[i][j];
                elems[line][column + 1] = oldMatrix[i][j];
                elems[line + 1][column + 1] = oldMatrix[i][j];
                column += 2;
            }
            column = 0;
            line += 2;
        }
        newBlock.setBlock(elems);
        return newBlock;
    }

    double[][] reconstructMatrix(List<Block> blocks) {
        double[][] elems = new double[blocks.get(0).getInitialHeight()][blocks.get(0).getInitialWidth()];
        for(Block block: blocks){
            int line = 0;
            int column = 0;
            for(int i = block.getXCoordinate(); i < block.getXCoordinate() + 8; i++) {
                for(int j = block.getYCoordinate(); j < block.getYCoordinate() + 8; j++) {
                    elems[i][j] = block.getBlock()[line][column];
                    column++;
                }
                column=0;
                line++;
            }
        }
        return elems;
    }

    List<Block> sub128(List<Block> encoded) {
        for (Block block: encoded) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    block.getBlock()[i][j] -= 128.0;
                }
            }
        }
        return encoded;
    }

    List<Block> forwardDCT(List<Block> encoded) {
        for (Block block: encoded)
            block.setIntsBlock(DCT(block.getBlock()));
        return encoded;
    }

    private int[][] DCT(double[][] matrix) {
        int[][] G = new int[8][8];
        double constant = (double) 1 / 4;
        for (int u = 0; u < 8; u++)
            for (int v = 0; v < 8; v++)
            {
                G[u][v] = (int) (constant * alpha(u) * alpha(v) * outerSum(matrix, u, v));
            }

        return G;
    }

    private double alpha(int value) {
        return value > 0 ? 1 : (1 / Math.sqrt(2.0));
    }

    private double outerSum(double[][] matrix, int u, int v) {
        double sum = 0.0;
        for (int x = 0; x < 8; x++)
            sum += innerSum(matrix, u, v, x);
        return sum;
    }

    private double innerSum(double[][] matrix, int u, int v, int x) {
        double sum = 0.0;
        for (int y = 0; y < 8; y++)
            sum += product(matrix[x][y], x, y, u, v);
        return sum;
    }

    private double product(double matrixValue, int x, int y, int u, int v) {
        double cosU = Math.cos(
                ((2 * x + 1) * u * Math.PI) / 16
        );

        double cosV = Math.cos(
                ((2 * y + 1) * v * Math.PI) / 16
        );

        return matrixValue * cosU * cosV;
    }

    List<Block> quantizationPhase(List<Block> encoded) {
        for (Block block: encoded)
            block.setIntsBlock(MatrixOperations.division(block.getIntsBlock(), Q));
        return encoded;
    }

    List<Block> deQuantizationPhase(List<Block> encoded) {
        for (Block block: encoded)
            block.setIntsBlock(MatrixOperations.multiplication(block.getIntsBlock(), Q));
        return encoded;
    }

    List<Block> inverseDCT(List<Block> encoded) {
        for (Block block: encoded)
            block.setIntsBlock(iDCT(block.getIntsBlock()));
        return encoded;
    }

    private int[][] iDCT(int[][] matrix) {
        int[][] f = new int[8][8];
        double constant = (double) 1 / 4;

        for (int x = 0; x < 8; x++)
            for (int y = 0; y < 8; y++)
            {
                f[x][y] = (int) (constant * iOuterSum(matrix, x, y));
            }

        return f;
    }

    private double iOuterSum(int[][] matrix, int x, int y) {
        double sum = 0.0;
        for (int u = 0; u < 8; u++)
            sum += iInnerSum(matrix, x, y, u);
        return sum;
    }

    private double iInnerSum(int[][] matrix, int x, int y, int u) {
        double sum = 0.0;
        for (int v = 0; v < 8; v++)
            sum += iProduct(matrix[u][v], x, y, u, v);
        return sum;
    }

    private double iProduct(double matrixValue, int x, int y, int u, int v) {
        double cosU = Math.cos(
                ((2 * x + 1) * u * Math.PI) / 16
        );

        double cosV = Math.cos(
                ((2 * y + 1) * v * Math.PI) / 16
        );

        return alpha(u) * alpha(v) * matrixValue * cosU * cosV;
    }

    List<Block> add128(List<Block> encoded) {
        for (Block block: encoded) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    block.getBlock()[i][j] += 128.0;
                }
            }
        }
        return encoded;
    }
}
