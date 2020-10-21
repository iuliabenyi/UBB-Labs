class Node:
    def __init__(self, val = None):
        self.val = val
        self.next = None



class LinkedList:
    def __init__(self, head=None):
        self.head = head

    def lookup(self, val):
        indx = 1
        currNode = self.head
        while currNode is not None:
            if currNode.val == val:
                return indx
            else:
                #go further
                currNode = currNode.next 
                indx += 1
        return 0

    def put(self, val):
        newNode = Node(val)
        newNode.next = None
        if self.head is None:
            self.head = newNode
            return 1
        else:
            indx = 1
            currNode = self.head
            while currNode.next is not None:
                currNode = currNode.next
                indx += 1
            currNode.next = newNode
            return indx + 1
        return 0


    def display(self):
        currNode = self.head
        while currNode is not None:
            if currNode.next is not None:
                print( str(currNode.val) + " -> ", end = "")
            else:
                #the last one
                print(str(currNode.val))
            currNode = currNode.next
