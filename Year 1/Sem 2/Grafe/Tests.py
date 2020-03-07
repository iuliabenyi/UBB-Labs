'''
Created on Mar 27, 2019

@author: Iulia
'''

from Graph import Graph
from Controller import *
from Iterators.Vertices import *
from File import File
from Iterators.EdgesIterator import EdgesIterator

def test():
    tup = File.readInput("file.txt")
    graph = tup[0]
    edgeData = tup[1]
    ctrl = Controller(graph, edgeData)
    
    vertices = ctrl.nrVertices()
    
    itv = verticesIterator(vertices)
    assert(itv.valid())
    
    cont = 0
    while (itv.valid()):
        cont += 1
        e = itv.getCurrent()
        itv.next()     
        e = itv.getCurrent()
        assert(ctrl.existsVertex(e))
    assert(cont == ctrl.nrVertices())
    itv.first()
    assert(itv.valid())
    
    ################
    ite = EdgesIterator(graph.getInbound(3))
    assert(ite.valid())
    assert(ite.getCurrent() == 1)
    ite.next()
    assert(ite.valid())
    assert(ite.getCurrent() == 2)
    
test()
    