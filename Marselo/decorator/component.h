#ifndef COMPONENT_H
#define COMPONENT_H


#include <iostream>
#include <fstream>
using namespace std;


class Component
{
public:
	virtual void show(ofstream& out)=0;
};


#endif