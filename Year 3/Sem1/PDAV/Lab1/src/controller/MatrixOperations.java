package controller;

public class MatrixOperations {

    static int[][] multiplication(int[][] A, double[][] B) {
        int[][] res = new int[8][8];
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                res[i][j] = (int) (A[i][j] * B[i][j]);
        return res;
    }

    static int[][] division(int[][] A, double[][] B) {
        int[][] res = new int[8][8];
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++) {
                res[i][j] = (int) (A[i][j] / B[i][j]);
            }
        return res;
    }
}
