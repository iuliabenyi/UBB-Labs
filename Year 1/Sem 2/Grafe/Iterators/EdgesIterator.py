'''
Created on Mar 27, 2019

@author: Iulia
'''

class EdgesIterator:
    def __init__(self, edges):
        self.__edges = edges
        self.__current = 0
    
    def valid(self):
        if self.__current < len(self.__edges):
            return True
        return False
    
    def getCurrent(self):
        if self.valid() == True:
            return self.__edges[self.__current]
        return False
    
    def next(self):
        if not self.valid():
            return False
        self.__current += 1
    
    def first(self):
        self.__current = 0
        