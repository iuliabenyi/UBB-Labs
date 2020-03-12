# -*- coding: utf-8 -*-
"""
Created on Sat Mar  7 16:33:11 2020

@author: Iulia
"""

class State:
    def __init__(self, size):
        #self.table = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
        self.table = []
        for i in range(size):
            self.table += [[0]*size]
        self.size = size
        
    def __str__(self):
        res = ""
        for i in self.table:
            for j in i:
                res += str(j)
                res += ' '
            res += '\n'
        return res
        
    def checkRow(self, row, col):
        #check the left side of the row
        for i in range(self.size):
            if self.table[row][i] == 1:
                return False
        return True
    def checkCol(self, row, col):
        #check col
        for i in range(self.size):
            if self.table[i][col] == 1:
                return False
        return True
    def checkMainDiag(self, row, col):
        #check main diagonal
        #if row != self.size-1 and col != self.size-1:
        #if row != 0 and col != 0:
        if self.table[row - 1][col - 1] == 1:
            #print("MAIN DIAG NO ADD")
            return False
        #print("TRUE MAIN" + " " + str(row) + " " + str(col))
        return True
    def checkMainDiag2(self, row, col):
        if row != self.size - 1 and col != self.size-1:
            if self.table[row+1][col+1] == 1:
                return False
        return True
    def checkSecondDiag(self, row, col):
        #check the secondary diagonal
        #if row != self.size-1:
        if row != 0 and col != self.size - 1:
            if self.table[row-1][col+1] == 1:
                #print("SEONDARY DIAG NO ADD")
                return False
        #print("TRUE SECOND" + " " + str(row) + " " + str(col))
        return True   
    def checkSecondDiag2(self, row, col):
        if row != self.size - 1:
            if self.table[row+1][col-1] == 1:
                return False
        return True 