'''
Created on Mar 19, 2019

@author: Iulia
'''
# -*- coding: utf-8 -*-


"""
Created on Tue Feb 19 15:48:58 2019

@author: Zsu
"""


class Bag:

    # creates a new, empty Bag
    #teta(1)
    def __init__(self):
        self.__bag = []
        self.__freq = []

    # adds a new element to the Bag
    #O(n)
    def add(self, e):
        
        if e in self.__bag:
            indx = self.__bag.index(e)
            self.__freq[indx] += 1
        else:
            self.__bag.append(e)
            self.__freq.append(1)

    # removes one occurrence of an element from a Bag
    # returns True if an element was actually removed (the Bag contained the element e), or False if nothing was removed
    #O(n)
    def remove(self, e):
        if e not in self.__bag:
            return False
        indx = self.__bag.index(e)
        if self.__freq[indx] > 1:
            self.__freq[indx] -= 1
        else:
            self.__freq.pop(indx)
            self.__bag.pop(indx)
        return True
        
        '''
        if e in self.__bag:
            for e in self.__freq:
                self.__freq[e] = 0
            return True
        return False'''

    # searches for an element e in the Bag
    # returns True if the Bag contains the element, False otherwise
    #O(n)
    def search(self, e):
        if e in self.__bag:
            return True
        return False

    # counts and returns the number of times the element e appears in the bag
    #O(n)
    def nrOccurrences(self, e):
        if e in self.__bag:
            indx = self.__bag.index(e)
            return self.__freq[indx]
        return 0

    # returns the size of the Bag (the number of elements)
    #teta(n)
    def size(self):
        ctr = 0
        for e in self.__freq:
            ctr += e
        return ctr

    # returns True if the Bag is empty, False otherwise
    #O(1)
    def isEmpty(self):
        return self.__bag == []

    # returns a BagIterator for the Bag
    # teta(1)
    def iterator(self):
        return BagIterator(self)


class BagIterator:

    #creates an iterator for the Bag b, set to the first element of the bag, or invalid if the Bag is empty
    #teta(1)
    def __init__(self, b):
        self.__bag = b
        self.__currE = 0
        self.__currF = 0

    # returns True if the iterator is valid
    #O(1)
    def valid(self):
        if self.__currE < len(self.__bag._Bag__bag):
            return True
        return False

    # returns the current element from the iterator.
    # throws ValueError if the iterator is not valid
    # O(1)
    def getCurrent(self):
        if self.valid() == True:
            return self.__bag._Bag__bag[self.__currE]
        else:
            raise ValueError

    # moves the iterator to the next element
    #throws ValueError if the iterator is not valid
    # O(1)
    def next(self):
        if not self.valid():
            raise ValueError
        self.__currF += 1
        if self.__currF == self.__bag._Bag__freq[self.__currE]:
            self.__currE += 1
            self.__currF = 0

    # sets the iterator to the first element from the Bag
    # O(1)
    def first(self):
        self.__currE = 0
        self.__currF = 0