#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
public:
	inline Counter();
	inline int  getValue() const;
	inline void increment();
	inline void decrement();
	inline void reset();

private:
	int nValue;
};


Counter::Counter()
: nValue(0)
{}


int Counter::getValue() const
{
	return nValue;
}


void Counter::increment()
{
	++nValue;
}


void Counter::decrement()
{
	--nValue;
}


void Counter::reset()
{
	nValue = 0;
}


#endif