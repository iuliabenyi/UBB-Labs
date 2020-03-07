'''
Created on Mar 14, 2019

@author: Iulia
'''
from Edges import Edges
from Graph import Graph


class File:
    @staticmethod
    def readInput(fileName):
        with open(fileName, 'r') as f:
            line = f.readline().split()
            n = int(line[0]) # vertices
            m = int(line[1]) # edges

            edgeData = Edges()
            graph = Graph(n, m, edgeData)

            edgeID = 0
            #print(f.readlines())
            for line in f.readlines():
                line = line.split()
                graph.addEdge(int(line[0]), int(line[1]))
                edgeData.addEdge(int(line[0]), int(line[1]), int(line[2]), edgeID)
                edgeID += 1

            return graph, edgeData
