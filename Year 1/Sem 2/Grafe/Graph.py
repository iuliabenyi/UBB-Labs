'''
Created on Mar 14, 2019

@author: Iulia
'''

from collections import deque
import queue

class Graph:
    def __init__(self, vertices, edges, edgeData):
        self.__vertices = vertices
        self.__edges = edges
        self.__edgeData = edgeData
        
        self.__inbound = {}
        self.__outbound = {}
        
        for i in range(vertices):
            self.__inbound[i] = []
            self.__outbound[i] = [] # adjacency list
            
    def getVertices(self):
        '''
            Gets the number of vertices
            Output:
                - returns the number of vertices 
        '''
        return self.__vertices
    
    def getEdges(self):
        return self.__edges

    def getEdgeData(self):
        return self.__edgeData
            
    def addEdge(self, v1, v2):
        '''
            Adds an edge between 2 vertices
            Input:
                - v1: the first vertex
                - v2: the second vertex
        '''
        self.__inbound[v2].append(v1)
        self.__outbound[v1].append(v2)
        
    def existsVertex(self, v):
        '''
            Checks if a vertex exists
            Input:
                - v: the given vertex
            Output:
                - True if the vertex exists 
                - False otherwise 
        '''
        return v >= 0 and v <= self.__vertices
        
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
        if not self.existsVertex(v1) or not self.existsVertex(v2):
            return False
        return v2 in self.__outbound[v1]
    
    def inDegree(self, v):
        '''
            Gets the in degree of a given vertex
            Input:
                - v: the vertex
            Output:
                - the in degree of the vertex
        '''
        return len(self.__inbound[v])
    
    def outDegree(self, v):
        '''
            Gets the out degree of a given vertex
            Input:
                - v: the vertex
            Output:
                - the out degree of the vertex
        '''
        return len(self.__outbound[v])
    
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
        if self.isEdge(v1, v2):
            #self.__edges.pop((v1, v2))
            #self.__edges.removeEdge((v1, v2))
            self.__outbound[v1].remove(v2)
            self.__inbound[v2].remove(v1)
            return True
        return False
    
    def addVertex(self):
        '''
            Adds a vertex and modifies the inbound and outbound dictionaries
        '''
        self.__vertices += 1
        self.__inbound[self.__vertices - 1] = []
        self.__outbound[self.__vertices - 1] = []
        
    def removeVertex(self, v):
        '''
            Removes a vertex
            Input:
                - v: the vertex to be removed
        '''
        if v == self.__vertices - 1:
            self.__vertices -= 1
        else:
            for i in range(v - 1, self.__vertices - 1):
                self.__inbound[i] = self.__inbound[i + 1][:]
                self.__outbound[i] = self.__outbound[i + 1][:]
                
            self.__vertices -= 1
            
    def getInbound(self, v):
        '''
            Getter for the inbound list of a vertex
            Input:
                - v: the vertex
            Output:
                - the inbound list 
        '''
        return self.__inbound[v]
    
    def getOutbound(self, v):
        '''
            Getter for the outbound list of a vertex
            Input:
                - v: the vertex
            Output:
                - the outbound list 
        '''
        return self.__outbound[v]
    
    def setInbound(self, i, inbound):
        '''
            Setter for the inbound list of a vertex
        '''
        self.__inbound[i] = inbound[:]
        
    def setOutbound(self, i, outbound):
        '''
            Setter for the outbound list of a vertex
        '''
        self.__outbound[i] = outbound[:]

    def getCost(self, start, end):
        if not self.isEdge(start, end):
            return 0

        return self.__edgeData.getCost(start, end)
        
    
    def bfs(self, end, start):
        if end < 0 or end >= self.__vertices or start < 0 or start >= self.__vertices:
            return "Invalid start or end vertex"
        
        # maintain a queue of paths
        queue = []
        visited = set()
        # push the first path into the queue
        queue.append([end])
        while queue:
            # get the first path from the queue
            path = queue.pop(0)
            # get the last node from the path
            node = path[-1]
            # path found
            if node == start:
                return path
            # enumerate all adjacent nodes, construct a new path and push it into the queue
            elif node not in visited:
                for adjacent in self.__inbound[node]:
                    new_path = list(path)
                    new_path.append(adjacent)
                    queue.append(new_path)
                    
                visited.add(node)
        
        return "No path found"

    def dijkstra(self, source, dest):
        # 1. Mark all nodes unvisited and store them.
        # 2. Set the distance to zero for our initial node
        # and to infinity for other nodes.
        distances = {vertex: 9999 for vertex in range(self.__vertices)}
        previous_vertices = {
            vertex: None for vertex in range(self.__vertices)
        }
        distances[source] = 0
        vertices = [i for i in range(self.__vertices)]

        while vertices:
            # 3. Select the unvisited node with the smallest distance,
            # it's current node now.
            current_vertex = min(
                vertices, key=lambda vertex: distances[vertex])

            # 6. Stop, if the smallest distance
            # among the unvisited nodes is infinity.
            if distances[current_vertex] == 9999:
                break

            # 4. Find unvisited neighbors for the current node
            # and calculate their distances through the current node.
            for neighbour in self.__outbound[current_vertex]:
                cost = self.getCost(current_vertex, neighbour)
                alternative_route = distances[current_vertex] + cost

                # Compare the newly calculated distance to the assigned
                # and save the smaller one.
                if alternative_route < distances[neighbour]:
                    distances[neighbour] = alternative_route
                    previous_vertices[neighbour] = current_vertex

            # 5. Mark the current node as visited
            # and remove it from the unvisited set.
            vertices.remove(current_vertex)

        path, current_vertex = deque(), dest
        while previous_vertices[current_vertex] is not None:
            path.appendleft(current_vertex)
            current_vertex = previous_vertices[current_vertex]
        if path:
            path.appendleft(current_vertex)
        return path

    def topologicalSort(self):
        sorted = []
        q = queue.Queue()
        count = {}
        vertices = [i for i in range(self.__vertices)]
        for x in vertices:
            count[x] = self.inDegree(x)
            if count[x] == 0:
                q.put(x)
        while not q.empty():
            x = q.get()
            sorted.append(x)
            for y in self.getOutbound(x):
                count[y] = count[y]-1
                if count[y] == 0:
                    q.put(y)
        if len(sorted) < self.__vertices:
            sorted = None
        return sorted

    def highestCost(self, start, end):
        sorted = self.topologicalSort()
        path = [-1 for i in range(self.__vertices)]
        path[0] = start
        INF = 2000000
        distances = [-INF for i in range(self.__vertices)]
        distances[start] = 0
        if sorted != None:
            for i in sorted:
                if distances[i] == -INF:
                    continue

                for j in self.getOutbound(i):
                    if distances[j] < distances[i] + self.getCost(i, j):
                        distances[j] = distances[i] + self.getCost(i, j)
                        path[j] = i
            print("The highest cost: ", distances[end])
        else:
            print("The graph is not a DAG")