#ifndef CLOAK_H
#define CLOAK_H

class Clock
{
public:
	inline Clock(int nHoursInit=0, int nMinutesInit=0, int nSecondsInit=0);
	
	inline int getHours();
	inline int getMinutes();
	inline int getSeconds();
	
private:
	int nHours,
		nMinutes,
		nSeconds;
};

Clock::Clock(int nHoursInit, int nMinutesInit, int nSecondsInit)
{
	nHours   = nHoursInit;
	nMinutes = nMinutesInit;
	nSeconds = nSecondsInit;
}


int Clock::getHours()
{
	return nHours;
}

int Clock::getMinutes()
{
	return nMinutes;
}

int Clock::getSeconds()
{
	return nSeconds;
}

#endif