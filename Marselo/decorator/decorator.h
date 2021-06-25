#ifndef DECORATOR_H
#define DECORATOR_H


#include "component.h"


class Decorator : public Component
{
public:
	inline Decorator(Component& rcInit);
	inline virtual void show(ofstream& out)=0;

private:
	Component& rc;
};


Decorator::Decorator(Component& rcInit)
: rc(rcInit)
{}


void Decorator::show(ofstream& out)
{
	rc.show(out);
}


#endif