package com.company;

import com.company.controller.MultiplyPolynomials;

import java.util.Random;
import java.util.concurrent.ExecutionException;

public class Main {

    public static void main(String[] args) throws InterruptedException, ExecutionException {
        int noThreads = 10;
        int degree = 64;

        int[] A = new int[degree];
        int[] B = new int[degree];

        int min = 1;
        int max = 100;

        Random random = new Random();
        for (int i = 0; i < degree; i++) {
            A[i] = random.nextInt(max - min) + min;
            B[i] = random.nextInt(max - min) + min;
        }

        int m = A.length;
        int n = B.length;

        MultiplyPolynomials multiplyPolynomials = new MultiplyPolynomials();

        System.out.println("First polynomial:");
        multiplyPolynomials.printPoly(A, m);
        System.out.println("\n\nSecond polynomial:");
        multiplyPolynomials.printPoly(B, n);

        long startTime1 = System.currentTimeMillis();
        regularSeq(A, B);
        long endTime1 = System.currentTimeMillis();

        long startTime2 = System.currentTimeMillis();
        KaratsubaSeq(A, B);
        long endTime2 = System.currentTimeMillis();

        long startTime3 = System.currentTimeMillis();
        regularThreads(A, B, noThreads);
        long endTime3 = System.currentTimeMillis();

        long startTime4 = System.currentTimeMillis();
        karatsubaThreads(A, B);
        long endTime4 = System.currentTimeMillis();

        System.out.println("\n\nPerformance for polynomials with " + degree + " coefficients: ");
        System.out.println("(1) Regular algorithm - sequential form: " + (endTime1 - startTime1) + " ms");
        System.out.println("(2) The Karatsuba algorithm - sequential form: " + (endTime2 - startTime2) + " ms");
        System.out.println("(3) Regular algorithm - parallelize form: " + (endTime3 - startTime3) + " ms");
        System.out.println("(4) The Karatsuba algorithm - parallelize form: " + (endTime4 - startTime4) + " ms");
    }

    private static void regularSeq(int[] A, int[] B) {
        MultiplyPolynomials multiplyPolynomials = new MultiplyPolynomials();
        int[] prodRegularSeq = multiplyPolynomials.regularSeq(A, B);

        System.out.println("\n\nAfter regular algorithm - sequential form the product polynomial is:");
        multiplyPolynomials.printPoly(prodRegularSeq, A.length + B.length - 1);
        System.out.println("\n");
    }

    private static void KaratsubaSeq(int[] A, int[] B) {
        MultiplyPolynomials multiplyPolynomials = new MultiplyPolynomials();
        int[] prodKaratsubaSeq = multiplyPolynomials.KaratsubaSeq(A, B);

        System.out.println("\n\nAfter the Karatsuba algorithm - sequential form the product polynomial is:");
        multiplyPolynomials.printPoly(prodKaratsubaSeq, A.length + B.length - 1);
        System.out.println("\n");
    }

    private static void regularThreads(int[] A, int[] B, int noThreads) throws InterruptedException {
        MultiplyPolynomials multiplyPolynomials = new MultiplyPolynomials();
        int[] prodRegularParal = multiplyPolynomials.regularParal(A, B, noThreads);

        System.out.println("\n\nAfter the regular algorithm - threads the product polynomial is:");
        multiplyPolynomials.printPoly(prodRegularParal, A.length + B.length - 1);
        System.out.println("\n");
    }

    private static void karatsubaThreads(int[] A, int[] B) throws ExecutionException, InterruptedException {
        MultiplyPolynomials multiplyPolynomials = new MultiplyPolynomials();
        int[] prodKaratsubaParal = multiplyPolynomials.KaratsubaParal(A, B, 0);

        System.out.println("\n\nAfter the Karatsuba algorithm - threads the product polynomial is:");
        multiplyPolynomials.printPoly(prodKaratsubaParal, A.length + B.length - 1);
        System.out.println("\n");
    }

}
