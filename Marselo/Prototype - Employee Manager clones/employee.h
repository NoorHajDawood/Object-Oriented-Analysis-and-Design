#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "counter.h"
#include "error.h"


const int MIN_SALARY = 3200;


class Employee
{
public:
	inline explicit Employee(long lSalaryInit);
	inline virtual ~Employee();

	virtual bool setSalary(long lNewSalary);

	inline int getId() const;
	inline long getSalary() const;

	virtual void print() const;
	virtual inline Employee* clone() const;

private:
	int  nId;
	long lSalary;
	static Counter counter;  // used here to 
	                         // to generate 
	                         // unique ID(s)
	
	long validateSalary(long lSalary); 
};


Employee::Employee(long lSalaryInit)
: nId(counter.getValue()), lSalary(validateSalary(lSalaryInit))
{
	counter.increment();
}


Employee::~Employee()
{}


int Employee::getId() const
{
	return nId;
}


long Employee::getSalary() const
{
	return lSalary;
}


Employee* Employee::clone() const
{
	return new Employee(lSalary);    // another option is
	                                 // creation via
	                                 // copy constructor:
	                                 // new Employee(*this)
}


#endif