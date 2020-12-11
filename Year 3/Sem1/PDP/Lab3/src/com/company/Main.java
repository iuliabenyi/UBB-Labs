package com.company;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        int nrThreads = 2;

        int size = 3;
        int[][] A = new int[size][size];
        int[][] B = new int[size][size];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                A[i][j] = (int) (1 + Math.random() * 10);
                B[i][j] = (int) (1 + Math.random() * 10);
            }
        }
        for(int i = 0; i< size; i++)
        {
            for(int j = 0; j< size; j++)
                System.out.print(A[i][j] + " ");
            System.out.print("\n");
        }
        for(int i = 0; i< size; i++)
        {
            for(int j = 0; j< size; j++)
                System.out.print(B[i][j] + " ");
            System.out.print("\n");
        }



        Tasks tasks = new Tasks(size, nrThreads, A, B);

//        tasks.simpleTask1();
  //      tasks.simpleTask2();
        tasks.simpleTask3();

        tasks.printResult("\n\n");

    //    tasks.poolTask1();
      //  tasks.poolTask2();
        tasks.poolTask3();

        tasks.printResult("\n\n");
    }
}
