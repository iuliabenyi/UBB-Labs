#pragma once

typedef int TElem;

struct Node {
	int data;
	TElem info;
	Node *next;
};

class SLL
{
public:
	SLL();
	~SLL();
	/*
	int size() const;
	bool isEmpty() const;
	TElem getElement(int pos) const;
	TElem getElement(int pos) const;
	*/


private:
	Node *head;

};

