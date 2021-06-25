#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"
#include <cmath>

const int EXTRA_SALARY = 500;    // an additional pay for
                                 // every worker he / she manages

class Manager : public Employee
{
public:
	inline Manager(long lBaseSalary, int nSizeInit);
	Manager(const Manager& rm);
	virtual ~Manager();
	const Manager& operator=(const Manager& rm);

	virtual bool setSalary(long lNewBaseSalary);
	
	bool addEmployee(const Employee& re);
	bool removeEmployee(int nIndex);
 
	      Employee* const getEmployee(int nIndex);
	const Employee* const getEmployee(int nIndex) const;

	inline int getSize() const;
	inline int getTop() const;
	bool isEmpty() const;
	bool isFull() const;

	virtual void print() const;
	virtual inline Employee* clone() const;

private:
	int nTop;
	int nSize;
	Employee** ptre;
};


Manager::Manager(long lBaseSalary, int nSizeInit)
: Employee(lBaseSalary), nTop(-1), nSize(abs(nSizeInit)), 
                                   ptre(new Employee*[nSize])
{}


int Manager::getSize() const
{
	return nSize;
}


int Manager::getTop() const
{
	return nTop;
}


Employee* Manager::clone() const
{
	return new Manager(*this);     // creation via
	                               // copy constructor
}

#endif
