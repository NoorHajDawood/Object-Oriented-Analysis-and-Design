#include "manager.h"

int main()
{
	Manager manager1(4000, 11);

	Employee employee1(4000),         // the long and winding code...
		     employee2(4100), 
			 employee3(3800), 
			 employee4(5000), 
			 employee5(5500);

	manager1.addEmployee(employee1);
	manager1.addEmployee(employee2);
	manager1.addEmployee(employee3);
	manager1.addEmployee(employee4);
	manager1.addEmployee(employee5);
	manager1.addEmployee(employee1);   // oh - not good...
	manager1.print();

	Manager manager2(6000, 10);
	manager2.addEmployee(employee1);
	manager2.addEmployee(manager1);    // did you notice?
	manager2.addEmployee(employee2);
	manager2.addEmployee(employee3);
	manager2.getEmployee(0)->setSalary(4500);
	manager2.print();

	return 0;
}


/********** output ***********

Manager: Id:0 Salary:6500. Manages 5 Workers:
-----------------------------
1. Employee: Id:1 Salary:4000
2. Employee: Id:2 Salary:4100
3. Employee: Id:3 Salary:3800
4. Employee: Id:4 Salary:5000
5. Employee: Id:5 Salary:5500
-----------------------------
Manager: Id:6 Salary:8000. Manages 4 Workers:
-----------------------------
1. Employee: Id:1 Salary:4500
2. Manager: Id:0 Salary:6500. Manages 5 Workers:
-----------------------------
1. Employee: Id:1 Salary:4500
2. Employee: Id:2 Salary:4100
3. Employee: Id:3 Salary:3800
4. Employee: Id:4 Salary:5000
5. Employee: Id:5 Salary:5500
-----------------------------
3. Employee: Id:2 Salary:4100
4. Employee: Id:3 Salary:3800
-----------------------------

******************************/