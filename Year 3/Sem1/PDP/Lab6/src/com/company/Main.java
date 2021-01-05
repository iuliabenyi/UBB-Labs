package com.company;

import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) throws FileNotFoundException, InterruptedException {
        String fileName = "C:\\Users\\HP\\Desktop\\UBB Labs\\Year 3\\Sem1\\PDP\\Lab6\\src\\com\\company\\graph";

        Graph graphB = new Graph(fileName);
        graphB.readGraph();
        Controller controllerB = new Controller(graphB);
        long startTime1 = System.currentTimeMillis();
        controllerB.backTracking(controllerB.getSol(), 0, graphB.getVertices());
        long endTime1 = System.currentTimeMillis();

        Graph graphT = new Graph(fileName);
        graphT.readGraph();
        Controller controllerT = new Controller(graphT);
        long startTime2 = System.currentTimeMillis();
        controllerT.threadBackTracking(controllerT.getSol(), 0, graphB.getVertices());
        long endTime2 = System.currentTimeMillis();

        System.out.println("Simple");
        if (!controllerB.getHasSol()) {
            System.out.println("Hamiltonian cycle does not exists");
        } else {
            System.out.println("Hamiltonian cycle is: " + controllerB.printSolution());
        }
        System.out.println("Threaded");
        if (!controllerT.getHasSol()) {
            System.out.println("Hamiltonian cycle does not exists");
        } else {
            System.out.println("Hamiltonian cycle is: " + controllerT.printSolution());
        }

        System.out.println("\nPerformance for simple backtracking: " + (endTime1 - startTime1) + " ms");
        System.out.println("Performance for thread backtracking: " + (endTime2 - startTime2) + " ms");
    }

}
