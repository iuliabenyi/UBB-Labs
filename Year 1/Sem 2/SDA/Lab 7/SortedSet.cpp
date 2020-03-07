
#include "SortedSet.h"


BSTNode *SortedSet::getMinimum(BSTNode *startingRoot) {
	BSTNode *currentNode = root;
	BSTNode *minNode = root;

	while (currentNode != NULL) {
		minNode = currentNode;
		currentNode = currentNode->getLeftSon();
	}
	return minNode;
}

BSTNode *SortedSet::getMaximum(BSTNode *startingRoot) {
	BSTNode *currentNode = root;
	BSTNode *maxNode = root;

	while (currentNode != NULL) {
		maxNode = currentNode;
		currentNode = currentNode->getRightSon();
	}
	return maxNode;
}

BSTNode *SortedSet::removeRecursively(BSTNode *node, TComp e, bool &removed) {
	if (node == NULL) {
		return node;
	}

	if (e == node->getValue()) {
		removed = true;
		if (node->getLeftSon() == NULL) {
			BSTNode* rightSon = node->getRightSon();
			delete node;
			return rightSon;
		}
		else if (node->getRightSon() == NULL) {
			BSTNode* leftSon = node->getLeftSon();
			delete node;
			return leftSon;
		}
		else {
			BSTNode *maxNode = getMaximum(node->getLeftSon());
			node->setValue(maxNode->getValue());
			node->setLeftSon(removeRecursively(node->getLeftSon(), maxNode->getValue(), removed));
		}
	}
	else if (rel(e, node->getValue())) {
		node->setLeftSon(removeRecursively(node->getLeftSon(), e, removed));
	}
	else {
		node->setRightSon(removeRecursively(node->getRightSon(), e, removed));
	}
	return node;
}

SortedSet::SortedSet(Relation r) : root{ NULL }, numberOfElements{ 0 }, rel{ r } {
}

bool SortedSet::add(TComp e) {
	BSTNode *current = root;
	BSTNode *parent = NULL;

	while (current != NULL) {
		parent = current;
		if (e == current->getValue()) {
			return false;
		}
		else if (rel(e, current->getValue())) {
			current = current->getLeftSon();
		}
		else {
			current = current->getRightSon();
		}
	}

	BSTNode *newNode = new BSTNode{ e };
	if (root == NULL) {
		root = newNode;
	}
	else if (rel(e, parent->getValue())) {
		parent->setLeftSon(newNode);
	}
	else {
		parent->setRightSon(newNode);
	}
	++numberOfElements;
	return true;
}

bool SortedSet::remove(TComp e) {
	bool removed = false;
	root = removeRecursively(root, e, removed);
	if (removed)
		--numberOfElements;
	return removed;
}

bool SortedSet::search(TComp elem) const {
	BSTNode *current = root;

	while (current != NULL) {
		if (current->getValue() == elem) {
			return true;
		}
		else if (rel(elem, current->getValue())) {
			current = current->getLeftSon();
		}
		else {
			current = current->getRightSon();
		}
	}
	return false;
}

int SortedSet::size() const {
	return numberOfElements;
}

bool SortedSet::isEmpty() const {
	return numberOfElements == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}

SortedSet::~SortedSet() {
	postOrderDeletion(root);
}

void SortedSet::postOrderDeletion(BSTNode *node) {
	if (node == NULL)
		return;
	if (node->isLeaf()) {
		delete node;
		return;
	}

	if (node->getLeftSon() != NULL)
		postOrderDeletion(node->getLeftSon());
	if (node->getRightSon() != NULL)
		postOrderDeletion(node->getRightSon());
	delete node;
}
