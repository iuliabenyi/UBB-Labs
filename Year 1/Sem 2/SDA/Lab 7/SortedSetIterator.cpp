
#include <stdexcept>
#include "SortedSetIterator.h"

SortedSetIterator::SortedSetIterator(const SortedSet &set) : set{ set }, currentNode{ NULL }, stack{ std::stack<BSTNode*>{} } {
	first();
}

void SortedSetIterator::first() {
	currentNode = set.root;
	stack = std::stack<BSTNode*>{};
	while (currentNode != NULL) {
		stack.push(currentNode);
		currentNode = currentNode->getLeftSon();
	}

	if (stack.empty() == false) {
		currentNode = stack.top();
	}
	else {
		currentNode = NULL;
	}
}

void SortedSetIterator::next() {
	if (!valid())
		throw std::runtime_error("");

	BSTNode* node = stack.top();
	stack.pop();

	if (node->getRightSon() != NULL) {
		node = node->getRightSon();
		while (node != NULL) {
			stack.push(node);
			node = node->getLeftSon();
		}
	}

	if (stack.empty() == false) {
		currentNode = stack.top();
	}
	else {
		currentNode = NULL;
	}
}

bool SortedSetIterator::valid() const {
	return currentNode != NULL;
}

TComp SortedSetIterator::getCurrent() const {
	if (!valid())
		throw std::runtime_error("");
	return currentNode->getValue();
}
