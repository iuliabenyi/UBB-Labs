'''
Created on Mar 14, 2019

@author: Iulia
'''

from UI import *
from File import *

def main():
    tup = File.readInput("file.txt")
    graph = tup[0]
    edgeData = tup[1]
    ui = UI(graph, edgeData)
    ui.run()
    
main()