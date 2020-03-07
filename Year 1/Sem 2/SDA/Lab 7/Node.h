#pragma once

typedef int TComp;

class BSTNode {
private:
	TComp value;
	BSTNode *leftSon;
	BSTNode *rightSon;

public:
	BSTNode(int value = 0, BSTNode *leftSon = 0, BSTNode *rightSon = 0);
	TComp getValue() const;
	void setValue(TComp value);
	BSTNode *getLeftSon() const;
	void setLeftSon(BSTNode *leftSon);
	BSTNode *getRightSon() const;
	void setRightSon(BSTNode *rightSon);
	bool isLeaf();
};

