#include "MultiMapIterator.h"

MultiMapIterator::MultiMapIterator(const MultiMap & c) : c{ c }
{
	head = c.head;
	iteratorNode = c.head;
}

void MultiMapIterator::first()
{
	//teta(1)
	iteratorNode = head;
}

void MultiMapIterator::next()
{
	//teta(1)
	if (!valid())
		throw exception();

	iteratorNode = iteratorNode->next;
}

bool MultiMapIterator::valid() const
{
	//teta(1)
	return iteratorNode != NULL;
}

TElem MultiMapIterator::getCurrent() const
{
	//teta(1)
	if (!valid())
		throw exception();

	return iteratorNode->info;
}
