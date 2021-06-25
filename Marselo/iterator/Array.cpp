// open questions:
// 1. What modifications should be done by the iterator
//    to support both const and non-const array?
// 2. Should iterator be able to modify
//    a) the array structure?
//    b) the array elements?

#include <new>
#include <cstring>
#include "array.h"

using namespace std;

IntArray::IntArray(int nSizeInit)
	: nSize(nSizeInit), pnData(new int[getSize()])
{}

IntArray::IntArray(const IntArray & iaSource)
	: nSize(iaSource.getSize()),
	  pnData(new int[getSize()])
{ memcpy(pnData, iaSource.getData(), getSize()); }

IntArray::~IntArray(void)
{ delete [] pnData; }

void IntArray::copyFrom(const IntArray & iaSource)
{
	this->~IntArray();
	new (this) IntArray(iaSource);
}

void IntIterator::goNext(void)
{
	if (hasNext())
		++nCurrent;
}

void IntIterator::goPrevious(void)
{
	if (hasPrevious())
		--nCurrent;
}
