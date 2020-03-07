#include "MultiMapIterator.h"

MultiMapIterator::MultiMapIterator(const MultiMap& c) : c{ c }, currIndex{ 0 }
{
	first();
}

void MultiMapIterator::first()
{
	currIndex = 0;
	while (c.T[currIndex].first == 0 && c.T[currIndex].second == 0)
		++currIndex;
}

void MultiMapIterator::next()
{
	++currIndex;
	while (c.T[currIndex].first == 0 && c.T[currIndex].second == 0)
		++currIndex;
}

bool MultiMapIterator::valid() const
{
	if (currIndex >= c.m || (c.T[currIndex].first == 0 && c.T[currIndex].second == 0))
		return false;

	return true;
}

TElem MultiMapIterator::getCurrent() const
{
	return c.T[currIndex];
}
