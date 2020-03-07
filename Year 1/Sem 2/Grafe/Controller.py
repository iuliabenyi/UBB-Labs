'''
Created on Mar 14, 2019

@author: Iulia
'''

from Iterators.Vertices import *
from Graph import * 
from Edges import *

class Controller:
    def __init__(self, graph, edgeData):
        self.__graph = graph
        self.__edgeData = edgeData
        
    def nrVertices(self):
        '''
            Gets the number of vertices
            Output:
                - returns the number of vertices 
        '''
        return self.__graph.getVertices()
    
    def isEdge(self, v1, v2):
        '''
            Checks is there is an edge between 2 vertices 
            Input:
                - v1: the start vertex
                - v2: the end vertex
            Output:
                - True if there is an edge between v1 and v2 
                - False otherwise
        '''
        if self.__graph.isEdge(v1, v2):
            return True 
        return False
    
    def inDegree(self, v):
        '''
            Gets the in degree of a given vertex
            Input:
                - v: the vertex
            Output:
                - the in degree of the vertex
        '''
        return self.__graph.inDegree(v)
    
    def outDegree(self, v):
        '''
            Gets the out degree of a given vertex
            Input:
                - v: the vertex
            Output:
                - the out degree of the vertex
        '''
        return self.__graph.outDegree(v)
    
    def endpointsOfEdge(self, edgeID):
        '''
            Gets the endpoints of an edge
            Input:
                - edgeID: the edge's ID
            Output:
                - the endpoints of the given edge 
        '''
        #check if ID exists 
        return self.__edgeData.endpoints(edgeID)
    
    def edgeInfo(self, edgeID):
        '''
            Gets the info of a given edge 
            Input:
                - edgeID: the edge's ID
            Output:
                - a tuple that contains the start vertex, the end vertex and the cost of the edge 
                - -1 if the edge doesn't exist
        '''
        return self.__edgeData.edgeInfo(edgeID)
    
    def modifyEdge(self, edgeID, cost):
        '''
            Modifies n edge's info 
            Input:
                - edgeID: the edge's ID
                - v1: the start vertex
                - v2: the end vertex
                - cost: the edge's cost
            Output:
                - 1 if the edge was modified 
                - -1 otherwise 
        '''
        return self.__edgeData.modifyEdge(edgeID, cost)
    
    def existsVertex(self, v):
        '''
            Checks if a vertex exists 
            Input: 
                - v: the given vertex
            Output:
                - True if the vertex exists 
                - False otherwise 
        '''
        return self.__graph.existsVertex(v)
    
    def verticesIterator(self):
        '''
            An iterator for the vertices
        '''
        return verticesIterator(self)
    
    def addEdge(self, v1, v2, cost, ID):
        '''
            Adds an edge
            Input:    
                - v1: the start vertex
                - v2: the end vertex
                - cost: the edge's cost 
                - ID: the edge's ID
            Output:
                - True if the edge was added 
                - False otherwise 
        '''
        self.__graph.addEdge(v1, v2)
        if self.__edgeData.addEdge(v1, v2, cost, ID):
            return True
        return False
    
    def removeEdge(self, v1, v2):
        '''
            Removes an edge 
            Input:
                - v1: the start vertex
                - v2: the end vertex
            Output:    
                - True if the edge was removed
                - False otherwise 
        '''
        return self.__graph.removeEdge(v1, v2) and self.__edgeData.removeEdge((v1, v2))
    
    def addVertex(self):
        '''
            Adds a vertex
        '''
        return self.__graph.addVertex()
    
    def removeVertex(self, v):
        '''
            Removes a vertex 
            Input:    
                - v: the vertex to be removed
            Output:    
                - True if the vertex was removed
                - False otherwise
        '''
        if not self.__graph.existsVertex(v):
            return False
        
        self.__graph.removeVertex(v)
        self.__edgeData.removeVertexReenum(v)
        return True
    
    def copyGraph(self):
        '''
            Makes a copy of the graph 
            Output:
                - g: the new graph
                - e: the new set of edges
        '''
        g = Graph(self.__graph.getVertices(), self.__graph.getEdges(), self.__graph.getEdgeData())
        for i in range(0, self.__graph.getVertices()):
            g.setInbound(i, self.__graph.getInbound(i))
            g.setOutbound(i, self.__graph.getOutbound(i))
            
        e = Edges()
        e.setData(self.__edgeData.getData())
        #self.__edgeData.setCost(0, 3, 5)
        
        return g, e
    '''
    def copyGraphNegative(self):
        
            """
            Makes a copy of the graph
            Output:
                - g: the new graph
                - e: the new set of edges"""
        
        g = Graph(self.__graph.getVertices(), self.__graph.getEdges(), self.__graph.getEdgeData())
        for i in range(0, self.__graph.getVertices()):
            g.setInbound(i, self.__graph.getInbound(i))
            g.setOutbound(i, self.__graph.getOutbound(i))
            for j in self.__graph.getOutbound(i):
                self.__edgeData.setCost(i, j, self.__edgeData.getCost(i, j) * (-1))

        e = Edges()
        e.setData(self.__edgeData.getData())
        # self.__edgeData.setCost(0, 3, 5)

        return g, e '''
    
    def bfs(self, start, end):
        return self.__graph.bfs(start, end)

    def dijkstra(self, start, end):
        return self.__graph.dijkstra(start, end)

    def topologicalSort(self):
        return self.__graph.topologicalSort()

    def highestCost(self, start, end):
        self.__graph.highestCost(start, end)