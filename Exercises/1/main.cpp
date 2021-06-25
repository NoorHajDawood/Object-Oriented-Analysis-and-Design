#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include "Student.h"
#include <string>

#define SIZE 8
using namespace std;

Student test[] = {  Student(10,90),
                    Student(7,85),
                    Student(12,65),
                    Student(6,100),
                    Student(20,95),
                    Student(4,80),
                    Student(1, 97),
                    Student(15,75)};


int main(int argc, const char * argv[])
{
	cout << "******************************" << endl;
	cout << "**********STACK DATA**********" << endl;
	std::stack<Student> s;
	for (int i = 0; i < SIZE; ++i)
		s.push(test[i]);

	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

	cout << "******************************" << endl;
	cout << "*********VECTOR DATA**********" << endl;

	std::vector<Student> v;
	for (int i = 0; i < SIZE; ++i)
		v.push_back(test[i]);



	auto it_v = v.begin();//We can use Auto keyword
	while(it_v != v.end())
		cout << *(it_v++) << endl;


	//std::sort(v.begin(), v.end(), CompareByAge());
	//std::vector<Student>::iterator it_v1 = v.begin();//We can use Auto keyword
	//while (it_v1 != v.end())
	//	cout << *(it_v1++) << endl;

	/*Sort with Lambda function*/
	std::sort(v.begin(), v.end(), [](const Student& s1, const Student& s2) {return s1.getAvg() < s2.getAvg();});
	std::vector<Student>::iterator it_v2 = v.begin();//We can use Auto keyword
	while (it_v2 != v.end())
		cout << *(it_v2++) << endl;


	cout << "******************************" << endl;
	cout << "************MAP DATA**********" << endl;

	std::map<int, Student> m;
	for (int i = 0; i < SIZE; ++i)
		m[i] = test[i];


	std::map<string, Student> m1;
	m1["Studen1"] = test[0];
	m1["Studen1"] = test[1];


	std::map<int, Student>::iterator it_m = m.begin();//We can use Auto keyword
	while (it_m != m.end())
		cout << (it_m++)->second << endl;


	auto entry = m.find(10);
	if (entry == m.end())
		cout << "NOT FOUND" << endl;


	cout << "FOUND Student #5: " << entry->second << endl;

	cin.get();
    return 0;
}
