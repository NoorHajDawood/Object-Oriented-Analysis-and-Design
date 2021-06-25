#ifndef SYSTEM_CLOCK_H
#define SYSTEM_CLOCK_H


#include "clock.h"
#include <ctime>


class SystemClock : public Clock
{
public:
	inline SystemClock();
	inline virtual string getTime() const ;
	inline void update();

private:
	char str[10];
};


SystemClock::SystemClock()
{
	update();
}


string SystemClock::getTime() const 
{
	return str;
}


void SystemClock::update()
{
	_strtime(str);
}


#endif