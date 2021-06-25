#include "manager.h"

int main()
{
	Manager manager1(4000, 11);

	manager1.addEmployee(Employee(4000));
	manager1.addEmployee(Employee(4100));
	manager1.addEmployee(Employee(3800));
	manager1.addEmployee(Employee(5000));
	manager1.addEmployee(Employee(5500));
	manager1.print();

	Manager manager2(6000, 10);
	manager2.addEmployee(Employee(4000));
	manager2.addEmployee(manager1);  
	manager2.addEmployee(Employee(3800));
	manager2.addEmployee(*(manager1.getEmployee(4)));
	manager2.getEmployee(0)->setSalary(4500);
	manager2.print();

	return 0;
}


/********** output ***********
******************************
** notice the jumps in IDs: **
** could you explain those? **
******************************

Manager: Id:0 Salary:6500. Manages 5 Workers
-----------------------------
1. Employee: Id:2 Salary:4000
2. Employee: Id:4 Salary:4100
3. Employee: Id:6 Salary:3800
4. Employee: Id:8 Salary:5000
5. Employee: Id:10 Salary:5500
-----------------------------
Manager: Id:11 Salary:8000. Manages 4 Workers
-----------------------------
1. Employee: Id:13 Salary:4500
2. Manager: Id:14 Salary:6500. Manages 5 Workers
-----------------------------
1. Employee: Id:15 Salary:4000
2. Employee: Id:16 Salary:4100
3. Employee: Id:17 Salary:3800
4. Employee: Id:18 Salary:5000
5. Employee: Id:19 Salary:5500
-----------------------------
3. Employee: Id:21 Salary:3800
4. Employee: Id:22 Salary:5500
-----------------------------

******************************/