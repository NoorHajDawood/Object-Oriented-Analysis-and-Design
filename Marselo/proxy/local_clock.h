#ifndef LOCAL_CLOCK_H
#define LOCAL_CLOCK_H


#include "system_clock.h"
#include <string.h>

class LocalClock : public Clock
{
public:
	LocalClock();
	inline virtual string getTime() const ;
	void update();

private:
	SystemClock* psc;
	char str[10];
};


LocalClock::LocalClock()
{
	static SystemClock sc;
	psc = &sc;
	update();
}


string LocalClock::getTime() const 
{
	return str;
}


void LocalClock::update()
{
	psc->update();
	strcpy(str, psc->getTime().data());
}


#endif