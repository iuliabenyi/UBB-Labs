package com.company;

import java.util.ArrayList;
import java.util.List;

public class Controller {
    private final int lvl = 5;
    private Graph graph;
    private List<Integer> sol = new ArrayList<>();
    private boolean hasSol = false;

    Controller(Graph graph) {
        this.graph = graph;
        this.sol.add(0); // start
    }

    private boolean exists(int el, List<Integer> sol) {
        for (Integer x: sol) {
            if (x == el) {
                return true;
            }
        }
        return false;
    }

    private boolean isSol(List<Integer> sol, int n) {
        int[][] G = graph.getGraph();
        return sol.size() == n && G[sol.get(sol.size() - 1)][0] == 1; // edge with the starting node
    }

    void backTracking(List<Integer> sol, int k, int n) {
        int[][] G = graph.getGraph();
        if (isSol(sol, n)) {
            hasSol = true;
        } else {
            for(int i = 0; i < n; i++) {
                if(G[sol.get(k)][i] == 1 && !exists(i, sol)) {
                    sol.add(i);
                    backTracking(sol, k + 1, n);
                    sol.add(-1);
                }
            }
        }
    }

    void threadBackTracking(List<Integer> solution, int k, int n) throws InterruptedException {
        int[][] G = graph.getGraph();
        if (isSol(solution, n)) {
            hasSol = true;
        } else {
            for(int i = 0; i < n; i++) {
                if(G[solution.get(k)][i] == 1 && !exists(i, solution)) {
                    solution.add(i);

                    Thread thread = new Thread();
                    boolean init = false;
                    if (k < lvl) {
                        threadBackTracking(solution, k + 1, n);
                        solution.add(-1);
                    } else {
                        thread = new Thread(() -> backTracking(solution, k + 1, n));
                        init = true;
                    }

                    if (init) {
                        thread.join();
                    }
                }
            }
        }
    }

    List<Integer> getSol() {
        return sol;
    }

    boolean getHasSol() {
        return hasSol;
    }

    List<Integer> printSolution() {
        List<Integer> result = new ArrayList<>();
        for (Integer i: this.sol) {
            if (i != -1)
                result.add(i);
        }
        return result;
    }
}
