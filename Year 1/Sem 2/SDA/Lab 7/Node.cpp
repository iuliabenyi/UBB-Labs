#include "Node.h"

BSTNode::BSTNode(int value, BSTNode *leftSon, BSTNode *rightSon) : value{ value }, leftSon{ leftSon }, rightSon{ rightSon } {}

TComp BSTNode::getValue() const {
	return value;
}

void BSTNode::setValue(TComp value) {
	BSTNode::value = value;
}

BSTNode *BSTNode::getLeftSon() const {
	return leftSon;
}

void BSTNode::setLeftSon(BSTNode *leftSon) {
	BSTNode::leftSon = leftSon;
}

BSTNode *BSTNode::getRightSon() const {
	return rightSon;
}

void BSTNode::setRightSon(BSTNode *rightSon) {
	BSTNode::rightSon = rightSon;
}

bool BSTNode::isLeaf() {
	return leftSon == 0 && rightSon == 0;
}
