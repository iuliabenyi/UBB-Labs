'''
Created on Mar 27, 2019

@author: Iulia
'''

from Graph import *

class verticesIterator:
    def __init__(self, vertices):
        self.__vertices = vertices
        #self.__vertices = Graph.getVertices()
        self.__current = 0
    
    def valid(self):
        #print(self.__vertices)
        if self.__current < self.__vertices:
            return True
        return False
    
    def getCurrent(self):
        if self.valid() == True:
            #print("AAA:", self.__vertices)
            return self.__current
        return False
    
    def next(self):
        if not self.valid():
            return False
        self.__current += 1
    
    def first(self):
        self.__current = 0
        
        