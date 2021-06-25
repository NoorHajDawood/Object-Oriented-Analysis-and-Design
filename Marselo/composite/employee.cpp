#include "employee.h"
#include "error.h"
#include <iostream>
using namespace std;

Counter Employee::counter;  // static data
                            // initialization


bool Employee::setSalary(long lNewSalary)
{
	if(lNewSalary < MIN_SALARY)
		return false;

	lSalary = lNewSalary;
	return true;
}


long Employee::validateSalary(long lSalary)
{
	if(lSalary < MIN_SALARY)
	{
		error("Salary can't be less than MIN_SALARY");
	}
	return lSalary;
}

 
void Employee::print() const
{
	cout<<"Employee: Id:"<<nId
		<<     " Salary:"<<lSalary
		<<endl;
}