package com.company.controller;

public class MultiplicationTask implements Runnable {
    private int start;
    private int end;
    private int[] A, B, res;

    public MultiplicationTask(int start, int end, int[] A, int[] B, int[] res) {
        this.start = start;
        this.end = end;
        this.A = A;
        this.B = B;
        this.res = res;
    }

    @Override
    public void run() {
        for (int i = start; i < end; i++) {
            // No more elements to calculate
            if (i > res.length) {
                return;
            }
            // Find all the pairs that we add to obtain the value of a result coefficient
            for (int j = 0; j <= i; j++) {
                if (j < A.length && (i - j) < B.length) {
                    int value = A[j] * B[i - j];
                    res[i] += value;
                }
            }
        }
    }
}

