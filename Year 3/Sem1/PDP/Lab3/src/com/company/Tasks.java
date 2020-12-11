package com.company;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Tasks {
    private int size;
    private int nrThreads;
    private int[][] A;
    private int[][] B;

    public Tasks(int size, int nrThreads, int[][] a, int[][] b) {
        this.size = size;
        this.nrThreads = nrThreads;
        A = a;
        B = b;
    }

    public void simpleTask1() throws InterruptedException, IOException {
        Product product = new Product(size, nrThreads, A, B);
        long start = System.currentTimeMillis();
        List<Thread> threadList = new ArrayList<>();

        for (int i = 0; i < nrThreads; i++) {
            threadList.add(new Thread(product.task1));
        }

        for (Thread thread : threadList)
            thread.start();

        for (Thread thread : threadList)
            thread.join();

        long end = System.currentTimeMillis();

        printResult("Task 1 simple threads\nTime: " + (end - start) +
                "\nSize: " + size +
                "\nThreads: " + nrThreads +
                "\n\n");

    }

    public void simpleTask2() throws InterruptedException, IOException {
        Product product = new Product(size, nrThreads, A, B);
        long start = System.currentTimeMillis();
        List<Thread> threadList = new ArrayList<>();

        for (int i = 0; i < nrThreads; i++) {
            threadList.add(new Thread(product.task2));
        }

        for (Thread thread : threadList)
            thread.start();

        for (Thread thread : threadList)
            thread.join();

        long end = System.currentTimeMillis();

        printResult("Task 2 simple threads\nTime: " + (end - start) +
                "\nSize: " + size +
                "\nThreads: " + nrThreads +
                "\n\n");


    }

    public void simpleTask3() throws InterruptedException, IOException {
        Product product = new Product(size, nrThreads, A, B);
        long start = System.currentTimeMillis();
        List<Thread> threadList = new ArrayList<>();

        for (int i = 0; i < nrThreads; i++) {
            threadList.add(new Thread(product.task3));
        }

        for (Thread thread : threadList)
            thread.start();

        for (Thread thread : threadList)
            thread.join();

        long end = System.currentTimeMillis();

        printResult("Task 3 simple threads\nTime: " + (end - start) +
                "\nSize: " + size +
                "\nThreads: " + nrThreads +
                "\n\n");
        product.printM();
    }


    public void poolTask1() throws IOException, InterruptedException {
        Product product = new Product(size, nrThreads, A, B);
        ExecutorService executorService = Executors.newFixedThreadPool(nrThreads);
        long start = System.currentTimeMillis();
        executorService.execute(product.task1);
        executorService.shutdown();
        executorService.awaitTermination(1, TimeUnit.MINUTES);
        long end = System.currentTimeMillis();

        printResult("Task 1 thread pool\nTime: " + (end - start) +
                "\nSize: " + size +
                "\nThreads: " + nrThreads +
                "\n\n");
    }

    public void poolTask2() throws IOException, InterruptedException {
        Product product = new Product(size, nrThreads, A, B);
        ExecutorService executorService = Executors.newFixedThreadPool(nrThreads);
        long start = System.currentTimeMillis();
        executorService.execute(product.task2);
        executorService.shutdown();
        executorService.awaitTermination(1, TimeUnit.MINUTES);
        long end = System.currentTimeMillis();

        printResult("Task 2 thread pool\nTime: " + (end - start) +
                "\nSize: " + size +
                "\nThreads: " + nrThreads +
                "\n\n");
    }

    public void poolTask3() throws IOException, InterruptedException {
        Product product = new Product(size, nrThreads, A, B);
        ExecutorService executorService = Executors.newFixedThreadPool(nrThreads);
        long start = System.currentTimeMillis();
        executorService.execute(product.task3);
        executorService.shutdown();
        executorService.awaitTermination(1, TimeUnit.MINUTES);
        long end = System.currentTimeMillis();

        printResult("Task 3 thread pool\nTime: " + (end - start) +
                "\nSize: " + size +
                "\nThreads: " + nrThreads +
                "\n\n");
    }


    public static void printResult(String output) throws IOException {
        BufferedWriter writer = new BufferedWriter(
                new FileWriter("output.txt", true));
        writer.write(output);
        writer.close();
    }
}
