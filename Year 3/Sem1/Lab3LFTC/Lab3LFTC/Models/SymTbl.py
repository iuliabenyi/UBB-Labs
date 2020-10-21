from LinkedList import *

class SymTbl:
    def __init__(self, cap=50):
        self.cap = cap
        self.dict = {}
        self.size = 0
        for x in range(1,cap+1):
            self.dict[x] = LinkedList()

    def hashF(self, key):
        m = self.cap
        s = 0
        for c in key:
            s = s + ord(c)
        hVal = s % m + 1
        return hVal

    def lookup(self, val):
        val = str(val)
        for k in self.dict.keys():
            foundVal = self.dict[k].lookup(val)
            if foundVal != 0:
                return k, foundVal
        return 0

    def put(self, key):
        self.size += 1
        indx = self.hashF(key)
        self.dict[indx].put(key)
        return indx

    def display(self):
        for k in self.dict.keys():
            if self.dict[k] is not None:
                print("ID :", str(k), ": ")
                self.dict[k].display()
