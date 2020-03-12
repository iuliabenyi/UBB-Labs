# -*- coding: utf-8 -*-
"""
Created on Sat Mar  7 16:33:36 2020

@author: Iulia
"""

class UI:
    def __init__(self, controller):
        self.controller = controller
    def menu(self):
        #print("1. DFS\n2. Greedy")
        inpt = 1
        while inpt != 0:
            inpt = int(input("1. DFS\n2. Greedy\n3. DFS2\n0. Exit\nEnter input: "))
            if inpt == 1:
                print("\nDFS")
                queue = self.controller.dfs2()
                print(queue)
            elif inpt == 2:
                print("\nGreedy")
                #print(self.controller.greedy())
                queue = self.controller.greedy()
                print(queue)
            elif inpt != 0:
                print("Wrong input")