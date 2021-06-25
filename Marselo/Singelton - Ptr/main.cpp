#include "systemcloak.h"
#include <iostream>
using namespace std;

int main()
{
	Clock clk1(2,59,33), clk2(2,44), clk3;

	//SystemClock sclk;     // no can do!
	                        // cannot access 
	                        // constructor


	clk3 = SystemClock::getInstance();
	
	cout<<clk3.getHours()   <<':'
		<<clk3.getMinutes() <<':'
		<<clk3.getSeconds() <<endl; 

	return 0;
}