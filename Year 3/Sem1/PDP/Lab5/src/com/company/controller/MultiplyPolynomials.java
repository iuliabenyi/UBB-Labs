package com.company.controller;

import java.util.concurrent.*;

public class MultiplyPolynomials {
    public int[] regularSeq(int[] A, int[] B) {
        int m = A.length;
        int n = B.length;
        int[] prod = new int[m + n - 1];
        // Initialize all entries in prod[] as 0
        for (int i = 0; i < m + n - 1; i++) {
            prod[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prod[i + j] += A[i] * B[j];
            }
        }

        return prod;
    }

    public int[] KaratsubaSeq(int[] A, int[] B) {
        int[] prod = new int[2 * A.length];
        //polynomial has one coefficient
        if (A.length == 1) {
            prod[0] = A[0] * B[0];
            return prod;
        }

        int halfSize = A.length / 2;

        int[] AFirst = new int[halfSize];
        int[] ASecond = new int[halfSize];
        int[] BFirst = new int[halfSize];
        int[] BSecond = new int[halfSize];
        int[] ASum = new int[halfSize];
        int[] BSum = new int[halfSize];

        for (int halfSizeIndx = 0; halfSizeIndx < halfSize; ++halfSizeIndx) {
            AFirst[halfSizeIndx] = A[halfSizeIndx];
            ASecond[halfSizeIndx] = A[halfSizeIndx + halfSize];
            ASum[halfSizeIndx] = AFirst[halfSizeIndx] + ASecond[halfSizeIndx];
            BFirst[halfSizeIndx] = B[halfSizeIndx];
            BSecond[halfSizeIndx] = B[halfSizeIndx + halfSize];
            BSum[halfSizeIndx] = BFirst[halfSizeIndx] + BSecond[halfSizeIndx];
        }

        int[] prodFirst = KaratsubaSeq(AFirst, BFirst);
        int[] prodSecond = KaratsubaSeq(ASecond, BSecond);
        int[] prodSum = KaratsubaSeq(ASum, BSum);

        int[] productDifference3 = new int[A.length];
        for (int halfSizeIndex = 0; halfSizeIndex < A.length; ++halfSizeIndex) {
            productDifference3[halfSizeIndex] = prodSum[halfSizeIndex] - prodFirst[halfSizeIndex] - prodSecond[halfSizeIndex];
        }

        //Assemble the product from the low, middle and high parts. Start with the low and high parts of the product.
        for (int halfSizeIndex = 0, middleOffset = A.length / 2; halfSizeIndex < A.length; ++halfSizeIndex) {
            prod[halfSizeIndex] += prodFirst[halfSizeIndex];
            prod[halfSizeIndex + A.length] += prodSecond[halfSizeIndex];
            prod[halfSizeIndex + middleOffset] += productDifference3[halfSizeIndex];
        }
        return prod;
    }

    public int[] regularParal(int[] A, int[] B, int noThreads) throws InterruptedException {
        int m = A.length;
        int n = B.length;
        int[] product = new int[m + n - 1];
        ThreadPoolExecutor executor = (ThreadPoolExecutor) Executors.newFixedThreadPool(noThreads);

        int step = product.length / noThreads;
        if (step == 0) {
            step = 1;
        }
        int end;
        for (int i = 0; i < product.length; i += step) {
            end = i + step;
            MultiplicationTask task = new MultiplicationTask(i, end, A, B, product);
            executor.execute(task);
        }
        executor.shutdown();
        executor.awaitTermination(50, TimeUnit.SECONDS);
        return product;
    }

    public int[] KaratsubaParal(int[] A, int[] B, int depth) throws InterruptedException, ExecutionException {
        int[] product = new int[2 * A.length];
        if (A.length < 2 || B.length < 2) {
            return KaratsubaSeq(A, B);
        }
        int halfArraySize = A.length / 2;

        int[] ALow = new int[halfArraySize];
        int[] AHigh = new int[halfArraySize];
        int[] BLow = new int[halfArraySize];
        int[] BHigh = new int[halfArraySize];
        int[] ALowHigh = new int[halfArraySize];
        int[] BLowHigh = new int[halfArraySize];

        for (int halfSizeIndex = 0; halfSizeIndex < halfArraySize; ++halfSizeIndex) {
            ALow[halfSizeIndex] = A[halfSizeIndex];
            AHigh[halfSizeIndex] = A[halfSizeIndex + halfArraySize];
            ALowHigh[halfSizeIndex] = ALow[halfSizeIndex] + AHigh[halfSizeIndex];

            BLow[halfSizeIndex] = B[halfSizeIndex];
            BHigh[halfSizeIndex] = B[halfSizeIndex + halfArraySize];
            BLowHigh[halfSizeIndex] = BLow[halfSizeIndex] + BHigh[halfSizeIndex];
        }

        int[] productLow, productHigh, productLowHigh;

        if(depth <= 3){
            ThreadPoolExecutor executor = (ThreadPoolExecutor) Executors.newCachedThreadPool();
            Callable<int[]> task1 = () -> KaratsubaParal(ALow, BLow, depth+1);
            Callable<int[]> task2 = () -> KaratsubaParal(AHigh, BHigh, depth+1);
            Callable<int[]> task3 = () -> KaratsubaParal(ALowHigh, BLowHigh, depth+1);
            Future<int[]> f1 = executor.submit(task1);
            Future<int[]> f2 = executor.submit(task2);
            Future<int[]> f3 = executor.submit(task3);
            executor.shutdown();
            productLow = f1.get();
            productHigh = f2.get();
            productLowHigh = f3.get();
            executor.awaitTermination(50, TimeUnit.SECONDS);
        }
        else {

            productLow = KaratsubaSeq(ALow, BLow);
            productHigh = KaratsubaSeq(AHigh, BHigh);
            productLowHigh = KaratsubaSeq(ALowHigh, BLowHigh);
        }
        // the same as before but with threads




        int[] productMiddle = new int[A.length];
        for (int halfSizeIndex = 0; halfSizeIndex < A.length; ++halfSizeIndex) {
            productMiddle[halfSizeIndex] = productLowHigh[halfSizeIndex] - productLow[halfSizeIndex] - productHigh[halfSizeIndex];
        }
        for (int halfSizeIndex = 0, middleOffset = A.length / 2; halfSizeIndex < A.length; ++halfSizeIndex) {
            product[halfSizeIndex] += productLow[halfSizeIndex];
            product[halfSizeIndex + A.length] += productHigh[halfSizeIndex];
            product[halfSizeIndex + middleOffset] += productMiddle[halfSizeIndex];
        }

        return product;
    }

    public void printPoly(int[] poly, int n)
    {
        for (int i = 0; i < n; i++) {
            System.out.print(poly[i]);
            if (i != 0) {
                System.out.print("x^" + i);
            }
            if (i != n - 1) {
                System.out.print(" + ");
            }
        }
    }
}
