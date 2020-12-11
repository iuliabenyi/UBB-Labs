package com.company;

public class Product {
    private int size;
    private int nrThreads;
    private int currThread;
    private int[][] A;
    private int[][] B;
    private int[][] product;

    public Product(int size, int nrThreads, int[][] a, int[][] b) {
        this.size = size;
        this.nrThreads = nrThreads;
        this.currThread = 0;
        A = a;
        B = b;
        this.product = new int[size][size];
    }

    public void multiplyTask(int row, int col) {
        for (int i = 0; i < this.size; i++)
            this.product[row][col] += A[row][i] * B[i][col];
    }

    public Runnable task1 = () -> {
        int pos = this.currThread;
        this.currThread++;
        for (int row = pos * size / nrThreads; row < (pos + 1) * size / nrThreads; row++) {
            for (int col = 0; col < size; col++) //0, size
                multiplyTask(row, col);
        }
    };

    public Runnable task2 = () -> {
        int pos = this.currThread;
        this.currThread++;
        for (int row = 0; row < size; row++)
            for (int col = pos * size / nrThreads; col < (pos + 1) * size / nrThreads; col++) {
                multiplyTask(row, col);
            }
    };

    public Runnable task3 = () -> {
        int pos = this.currThread;
        this.currThread++;
        for(int idx = 0; idx < size * size; idx++){
            if(idx % nrThreads == pos)
                multiplyTask(idx/size, idx%size);
        }

    };

    public void printM(){
        for(int i = 0; i< size; i++)
        {
            for(int j = 0; j< size; j++)
                System.out.print(product[i][j] + " ");
            System.out.print("\n");
        }
    }

}
