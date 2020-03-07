#include "SetIterator.h"

SetIterator::SetIterator(const Set & set) : set{ set }
{
	currentIndex = 0;
}

void SetIterator::first()
{
	currentIndex = 0;
}

void SetIterator::next()
{
	if (!valid())
		throw exception();

	++currentIndex;
}

bool SetIterator::valid() const
{
	return currentIndex >= 0 && currentIndex < set.size();
}

TElem SetIterator::getCurrent() const
{
	if (!valid())
		throw new exception();
	else
		return set.da.getElement(currentIndex);
}

void SetIterator::previous()
{
	if (currentIndex == -1)
		throw exception();

	currentIndex -= 1;
}