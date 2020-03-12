# -*- coding: utf-8 -*-
"""
Created on Sat Mar  7 16:33:21 2020

@author: Iulia
"""

from State import State
import copy

class Problem:
    def __init__(self, size):
        self.initialState = State(size)
        
    def __str__(self):
        return str(self.initialState)
    
    def setValue(self, i, j, k):
        self.initialState.table[i][j] = k
    
    def expand(self):
        #returns a list of the states
        nextStates = []
        for i in range(self.initialState.size):
            for j in range(self.initialState.size):
                    if self.initialState.checkSecondDiag2(i,j) and self.initialState.checkMainDiag2(i, j) and self.initialState.checkRow(i, j) and self.initialState.checkCol(i,j) and self.initialState.checkMainDiag(i,j) and self.initialState.checkSecondDiag(i,j) and self.initialState.table[i][j] == 0:
                        nextState = copy.deepcopy(self)
                        nextState.setValue(i, j, 1)
                        nextStates.append(nextState)
                        #print(nextState)
        return nextStates
    
    def completed(self):
        for i in range(self.initialState.size):
            ok = 0
            for j in range(self.initialState.size):
                if self.initialState.table[i][j] == 1:
                    ok = 1
            if ok == 0:
                return False
        return True
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                