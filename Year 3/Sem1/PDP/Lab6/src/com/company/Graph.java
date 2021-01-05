package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Graph {
    private int[][] graph = new int[50][50];
    private String file;
    private int vertices;
    private int edges;

    Graph(String file) {
        this.file = file;
        this.vertices = 0;
        this.edges = 0;
    }

    void readGraph() throws FileNotFoundException {
        File file = new File(this.file);
        Scanner scanner = new Scanner(file);
        String firstLine = scanner.nextLine();
        String[] firstLineSplit = firstLine.split(" ");
        this.vertices = Integer.parseInt(firstLineSplit[0]);
        this.edges = Integer.parseInt(firstLineSplit[1]);

        while (scanner.hasNextLine()) {
            String pair = scanner.nextLine();
            String[] pairSplit = pair.split(" ");
            int x = Integer.parseInt(pairSplit[0]);
            int y = Integer.parseInt(pairSplit[1]);
            graph[x][y] = 1;
        }

        scanner.close();
    }

    int getVertices() {
        return vertices;
    }

    int[][] getGraph() {
        return graph;
    }
}
