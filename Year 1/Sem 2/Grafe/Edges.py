'''
Created on Mar 14, 2019

@author: Iulia
'''

class Edges:
    def __init__(self):
        self.__data = {}
    
    def addEdge(self, v1, v2, cost, ID):
        '''
            Adds properties to an edge 
            Input:
                - v1: the start vertex
                - v2: the end vertex
                - cost: the edge's cost 
                - ID: the edge's ID
            Output:
                - Adds the given properties to the edge
        '''
        edgeTup = (v1, v2)

        if edgeTup not in self.__data.keys():
            self.__data[edgeTup] = [ID, cost]
            return True
        return False
            
    def endpoints(self, edgeID):
        '''
            Finds the endpoints of an edge 
            Input:
                - edgeID: the edge's ID
            Output:
                - a tuple of the endpoints
                - -1 if the key doesn't exist in the dictionary
        '''
        for key in self.__data.keys():
            if self.__data[key][0] == edgeID:
                return key[0], key[1]

        return -1
    
    def edgeInfo(self, edgeID):
        '''
            Gets the info of a given edge 
            Input:
                - edgeID: the edge's ID
            Output:
                - a tuple that contains the start vertex, the end vertex and the cost of the edge 
                - -1 if the edge doesn't exist
        '''
        for key in self.__data.keys():
            if self.__data[key][0] == edgeID:
                v1 = key[0]
                v2 = key[1]
                cost = self.__data[(v1, v2)][1]
                return v1, v2, cost
                

        return -1
    
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
        
        for value in self.__data.values():
            if value[0] == edgeID:
                value[1] = cost
                return 1

        return -1


    
    def removeEdge(self, edgeTup):
        '''
            Removes an edge 
            Input:
                - edgeTup: a tuple that contains the endpoints of the edge 
            Output:
                - True if the edge was removed 
                - False otherwise 
        '''
        if edgeTup in self.__data.keys():
            self.__data.pop(edgeTup)
            return True
            
        return False
   
    def removeVertexReenum(self, v):
        '''
            Makes the reindexing of the vertices after a vertex was removed
            Input:
                - v: the vertex that is removed 
        '''
        newData = {}
        for tup in self.__data.keys():
            v1 = tup[0]
            v2 = tup[1]
            
            if v1 == v or v2 == v:
                continue
            
            if v1 > v:
                v1 -= 1
            
            if v2 > v:
                v2 -= 1
                                
            newTuple = (v1, v2)
            newData[newTuple] = self.__data[tup]
            
        self.__data = newData
        
    def setData(self, data):
        '''
            Setter for the dictionary of the class
        '''
        self.__data = data
        
    def getData(self):
        '''
            Getter for the dictionary of the class
        '''
        return self.__data

    def getCost(self, start, end):
        return self.__data[(start, end)][1]

    def setCost(self, start, end, newCost):
        self.__data[(start, end)][1] = newCost