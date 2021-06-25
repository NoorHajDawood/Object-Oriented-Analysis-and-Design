#ifndef RESIZE_DECORATOR_H
#define RESIZE_DECORATOR_H


#include "decorator.h"


class ResizeDecorator : public Decorator
{
public:
	inline ResizeDecorator(Component& rcInit, bool makeBiggerInit);
	virtual void show(ofstream& out);

private:
	bool makeBigger;
};


ResizeDecorator::ResizeDecorator(Component& rcInit, bool makeBiggerInit)
: Decorator(rcInit), makeBigger(makeBiggerInit)
{}


void ResizeDecorator::show(ofstream& out)
{
	out<< "<BIG>";
	
	Decorator::show(out);
	
	out<< "</BIG>";
}


#endif