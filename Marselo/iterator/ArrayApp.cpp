#include <iostream>
#include "array.h"

using std::cout;
using std::endl;

int main(void)
{
	IntArray a(10);

	for (int nCurrent=0; nCurrent<a.getSize(); ++nCurrent)
		a[nCurrent] = nCurrent;

	for (IntIterator i = a.getIterator();
		 i.hasNext();
		 i.goNext())
		cout << i.getCurrent() << endl;

	for (IntIterator i2 = a.getIterator();
		 i2.hasNext();
		 ++i2)
		cout << *i2 << endl;
		 
	return 0;
}