#include "error.h"

#include <iostream>
using namespace std;

void error(const char* const strErr)
{
	cerr<<strErr<<endl;
	exit(1);
}