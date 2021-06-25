#ifndef SYSTEMCLOAK_H
#define SYSTEMCLOAK_H

#include "cloak.h"

class SystemClock
{
public:
	static Clock getInstance();
	inline ~SystemClock();

private:
	static Clock* clk;
	
	SystemClock();   	
	           
};


#endif