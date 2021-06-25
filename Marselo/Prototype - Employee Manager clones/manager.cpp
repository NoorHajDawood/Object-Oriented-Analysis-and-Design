#include "manager.h"
#include <iostream>
using namespace std;


Manager::Manager(const Manager& rm)
: Employee(rm.getSalary()),
  nTop(rm.getTop()), nSize(rm.getSize()), ptre(new Employee*[nSize])
{
	for(int i=0; i<=nTop; ++i)
	{
		ptre[i] = rm.getEmployee(i)->clone();    // Dynamically
		                                         // allocate
	                                             // a unique copy
	}                                            // of every worker

}


Manager::~Manager()
{
	for(int i=0; i<=nTop; ++i)                   // free'em all
	{                                            // allocated items

		delete ptre[i];                          // virtualy using
		                                         // Employee::~Employee
		                                         // or
		                                         // Manager::~Manager
	}

	delete[]ptre;                                // free the array
	                                             // of pointers
}


const Manager& Manager::operator=(const Manager& rm)
{
	if(this == &rm)
		return *this;

	this->~Manager();
	new(this) Manager(rm);

	return *this;
}


bool Manager::setSalary(long lNewBaseSalary)
{
	return Employee::setSalary(lNewBaseSalary +
		                      (nTop + 1) * EXTRA_SALARY);
}


bool Manager::addEmployee(const Employee& re)
{
	if(isFull())
		return false;

	for(int i=0; i<=nTop; ++i)
	{
		if(ptre[i]->getId() == re.getId())       // was this worker
		{                                        // added already?
			return false;
		}
	}

	ptre[++nTop] = re.clone();                   // Dynamically
	                                             // allocate
	                                             // a unique copy

	                                             // update salary
	Employee::setSalary(getSalary() + EXTRA_SALARY);
	return true;
}


bool Manager::removeEmployee(int nIndex)
{
	if(isEmpty())
		return false;

	if(nIndex < 0 || nIndex > nTop)
		return false;

	delete ptre[nIndex];                         // free the
	                                             // allocated
	                                             // memmory

	for(int i=nIndex; i<nTop; ++i)
	{
		ptre[i] = ptre[i+1];
	}
	--nTop;
	                                             // update salary
	Employee::setSalary(getSalary() - EXTRA_SALARY);
	return true;
}


Employee* const Manager::getEmployee(int nIndex)
{
	if(nIndex < 0 || nIndex > nTop)
		return 0;

	return ptre[nIndex];
}


const Employee* const Manager::getEmployee(int nIndex) const
{
	if(nIndex < 0 || nIndex > nTop)
		return 0;

	return ptre[nIndex];
}


bool Manager::isEmpty() const
{
	return nTop == -1;
}


bool Manager::isFull() const
{
	return nTop+1 == nSize;
}


void Manager::print() const
{
	cout<<"Manager: Id:" <<getId()
		<<" Salary:"     <<getSalary()
		<<". Manages "   <<nTop + 1
        <<" Workers"
		<<endl

        <<"-----------------------------"<<endl;

	for(int i=0; i<=nTop; ++i)
	{
		cout<<i+1<<". ";
		ptre[i]->print();    // Manager::print or
		                     // Employee::print?
	                         // depends on the type
	}                        // of the pointed object

	cout<<"-----------------------------"<<endl;
}
