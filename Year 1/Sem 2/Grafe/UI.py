'''
Created on Mar 14, 2019

@author: Iulia
'''

from Graph import Graph
from File import File
from Controller import Controller

class UI:
    def __init__(self, graph, edgeData):
        self.__ctrl = Controller(graph, edgeData)
    
    def menu(self):
        print("MENU:")
        print("\t1. The number of vertices")
        print("\t2. Parse the set of vertices")
        print("\t3. Find out if there is an edge between 2 vertices")
        print("\t4. Get the in degree of a vertex")
        print("\t5. Get the out degree of a vertex")
        print("\t6. Parse the set of outbound edges of a vertex")
        print("\t7. Parse the set of inbound edges of a vertex")
        print("\t8. Get the endpoints of an edge")
        print("\t9. Retrieve the information of an edge")
        print("\t10. Modify the information of an edge")
        print("\t11. Add an edge")
        print("\t12. Remove an edge")
        print("\t13. Add a vertex")
        print("\t14. Remove a vertex")
        print("\t15. Copy the graph")
        print("\t16. Print the path between 2 vertices using BFS")
        print("\t17. The lowest cost walk")
        print("\t18. The highest cost path")
        print("\t19. Verify DAG")
        print("\t0. Exit")
        
    def run(self):
        self.menu()
        while True:
            cmd = int(input("\nEnter a command: "))
            if cmd == 1:
                print("The number of vertices is: ", self.__ctrl.nrVertices())
            elif cmd == 2:
                print("See the tests!")
            elif cmd == 3:
                v1 = int(input("Give the start vertex: "))
                v2 = int(input("Give the end vertex: "))
                if self.__ctrl.isEdge(v1, v2):
                    print("There is an edge")
                else:
                    print("There isn't an edge")
            elif cmd == 4:
                v = int(input("Give the vertex: "))
                print("The in degree of the vertex {} is {}".format(v, self.__ctrl.inDegree(v)))
            elif cmd == 5:
                v = int(input("Give the vertex: "))
                print("The out degree of the vertex {} is {}".format(v, self.__ctrl.outDegree(v)))
            elif cmd == 6:
                print("See the tests!")
            elif cmd == 7:
                print("See the tests!")
            elif cmd == 8:
                ID = int(input("Give the edge's ID: "))
                res = self.__ctrl.endpointsOfEdge(ID)
                
                if res != -1:
                    print("The endpoints of the edge {} are {} and {}".format(ID, res[0], res[1]))
                else:
                    print("The edge doen't exist!")
            elif cmd == 9:
                ID = int(input("Give the edge's ID: "))
                res = self.__ctrl.edgeInfo(ID)
                
                if res != -1:
                    print("Edge information")
                    print("\t ID:", ID)
                    print("\t start vertex:", res[0])
                    print("\t end vertex:", res[1])
                    print("\t cost:", res[2])
                else: 
                    print("Edge doesn't exist!")
            elif cmd == 10:
                ID = int(input("Give the edge's ID: "))
                cost = int(input("Give the new cost: "))
                
                if self.__ctrl.modifyEdge(ID, cost) == 1:
                    print("Edge modified!")
                else:
                    print("Could not modify!")
            elif cmd == 11:
                v1 = int(input("Give the start vertex: "))
                v2 = int(input("Give the end vertex: "))
                cost = int(input("Give the edge's cost: "))
                ID = int(input("Give the edge's ID: "))
                if self.__ctrl.addEdge(v1, v2, cost, ID):
                    print("Edge added!")
                else:
                    print("Could not add edge!")
            elif cmd == 12:
                v1 = int(input("Give the start vertex: "))
                v2 = int(input("Give the end vertex: "))
                if self.__ctrl.removeEdge(v1, v2):
                    print("Edge removed!")
                else:
                    print("Could not remove edge!")
            elif cmd == 13:
                self.__ctrl.addVertex()
                print("Done!")
            elif cmd == 14:
                v = int(input("Give the vertex: "))
                if self.__ctrl.removeVertex(v):
                    print("Done!")
                else:
                    print("Could not remove vertex!")
            elif cmd == 15:
                print("See the code!")
            elif cmd == 16:
                start = int(input("From vertex: "))
                end = int(input("To vertex: "))
                print(self.__ctrl.bfs(end, start))
                #print(self.__ctrl.bfs(3, 2))
            elif cmd == 17:
                start = int(input("From vertex: "))
                end = int(input("To vertex: "))
                print(self.__ctrl.dijkstra(start, end))
            elif cmd == 18:
                start = int(input("From vertex: "))
                end = int(input("To vertex: "))
                self.__ctrl.highestCost(start, end)

            elif cmd == 19:
                print(self.__ctrl.topologicalSort())
            elif cmd == 0:
                return False
        
