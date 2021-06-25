#include "local_clock.h"
#include <windows.h>


int main()
{
	LocalClock lc;


	cout << lc.getTime().data() << endl;     Sleep(10000);
	cout << lc.getTime().data() << endl;     Sleep(10000);

	lc.update();

	cout << lc.getTime().data() << endl;     Sleep(10000);
	cout << lc.getTime().data() << endl;


	return 0;
}



/**** output ****

14:13:00
14:13:00
14:13:20
14:13:20

*****************/