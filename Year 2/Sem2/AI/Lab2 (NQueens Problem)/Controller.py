# -*- coding: utf-8 -*-
"""
Created on Sat Mar  7 16:33:29 2020

@author: Iulia
"""

from Problem import Problem

class Controller:
    def __init__(self, size):
        self.instance = Problem(size)
        
    def __str__(self):
        return str(self.instance)
    
    def dfs2(self):
        stack = [self.instance]
        while len(stack) != 0:
            currState = stack.pop()
            if currState.completed() is True:
                return currState
            stack = stack + currState.expand()
    
    def greedy(self):
        queue = [self.instance]
        while len(queue) != 0:
            currState = queue.pop(0)
            if currState.completed() is True:
                return currState
            nextStates = currState.expand()
            #     check if some of the next states are already in the queue
            for nextState in nextStates:
                notAdd = False
                for states in queue:
                   # print("in for states in queue")
                    if nextState == states:
                        notAdd = True
                        break
                if not notAdd:
                    queue.append(nextState)
        return queue

                    