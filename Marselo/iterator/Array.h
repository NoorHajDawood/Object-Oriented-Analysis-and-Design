#ifndef __ARRAY_H__
#define __ARRAY_H__

class IntIterator;

class IntArray
{
public:
	explicit IntArray(int nSizeInit);
	IntArray(const IntArray & iaSource);
	~IntArray(void);
	inline const IntArray & operator=(const IntArray & iaSource);
	       void  copyFrom(const IntArray & iaSource);

	inline int   getSize(void) const;

	inline const int & elementAt (int nIndex) const;
	inline       int & elementAt (int nIndex);
	inline const int & operator[](int nIndex) const;
	inline       int & operator[](int nIndex);

	inline IntIterator getIterator(void);

private:
	const int nSize;
	int  *pnData;

	inline int * getData(void) const; // private getter for inner use
};

class IntIterator
{
	friend IntIterator IntArray::getIterator(void);

public:
	void goNext(void);
	inline IntIterator operator++(void);
	inline IntIterator operator++(int);

	void goPrevious(void);
	inline IntIterator operator--(void);
	inline IntIterator operator--(int);

	inline void goFirst(void);
	inline void goLast(void);

	inline int & getCurrent(void);
	inline int & operator*(void);

	inline bool hasPrevious(void);
	inline bool hasNext(void);

private:
	int * const pnData;
	const int  nSize;
		  int  nCurrent;
	inline IntIterator(int * const pnDataInit, int nSizeInit);
};


int * IntArray::getData(void) const // private getter for inner use
{ return pnData; }

int IntArray::getSize(void) const
{ return nSize; }

const IntArray & IntArray::operator=(const IntArray & iaSource)
{
	copyFrom(iaSource);
	return *this;
}

const int & IntArray::elementAt(int nIndex) const
{
	// sanity checks were omitted for clarity
	return pnData[nIndex];
}

int & IntArray::elementAt(int nIndex)
{ return pnData[nIndex]; }

const int & IntArray::operator[](int nIndex) const
{ return (const_cast<IntArray *>(this))->elementAt(nIndex); }

int & IntArray::operator[](int nIndex) 
{ return elementAt(nIndex); }

IntIterator IntArray::getIterator(void)
{ return IntIterator(getData(), getSize()); }

IntIterator::IntIterator(int * const pnDataInit, int nSizeInit)
	: pnData(pnDataInit), nSize(nSizeInit), nCurrent(0)
{}

int & IntIterator::getCurrent(void) 
{ return pnData[nCurrent]; }

int & IntIterator::operator*(void)
{ return getCurrent(); }

bool IntIterator::hasPrevious(void) 
{ return nCurrent>0; }

bool IntIterator::hasNext(void) 
{ return nCurrent<nSize-1; }

inline IntIterator IntIterator::operator++(void)
{ 
	goNext(); 
	return *this;
}

inline IntIterator IntIterator::operator++(int)
{ 
	IntIterator iiBefore(*this);
	goNext();
	return iiBefore;
}

inline IntIterator IntIterator::operator--(void)
{ 
	goPrevious(); 
	return *this;
}

inline IntIterator IntIterator::operator--(int)
{ 
	IntIterator iiBefore(*this);
	goPrevious();
	return iiBefore;
}

#endif