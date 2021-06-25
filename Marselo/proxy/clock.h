#ifndef CLOCK_H
#define CLOCK_H


#include <iostream>
using namespace std;


class Clock
{
public:
	virtual string getTime() const =0;
};


#endif