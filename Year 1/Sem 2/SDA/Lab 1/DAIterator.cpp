#include "DAIterator.h"

DAIterator::DAIterator(const DynamicArray& da) : da{ da }
{
	currentIndex = 0;
}

void DAIterator::first()
{
	this->currentIndex = 0;
}

class NotValidException : public exception
{
	virtual const char* what() const throw()
	{
		return "Not valid!";
	}
};

void DAIterator::next()
{
	try
	{
		if (!valid())
		{
			throw new NotValidException();
		}

		++currentIndex;
	}
	catch (exception &e)
	{
		cout << e.what();
	}
	
}

bool DAIterator::valid() const
{
	return currentIndex < da.size();
}

TElem DAIterator::getCurrent() const
{
	try
	{
		if (!valid())
			throw new NotValidException();
		else
			return da.getElement(currentIndex);
	}
	catch (exception &e)
	{
		cout << e.what();
	}
	
}
