#include "systemcloak.h"

Clock* SystemClock::clk = 0;


Clock SystemClock::getInstance()
{
	if(!clk)
		clk = new Clock(8,0,0);

	return *clk;
}