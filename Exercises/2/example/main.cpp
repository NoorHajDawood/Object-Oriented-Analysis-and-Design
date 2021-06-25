#include <iostream>
#include <memory>
#include "classes.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

	{
		vector<shared_ptr<Person>> persons;
		vector<Person*> ptrPersons;

		Pos p(0, 0);
		persons.push_back(shared_ptr<Person>(new Person("Jony", p, true)));
		ptrPersons.push_back(new Person("Jony", p, true));
	}


	vector<shared_ptr<Person>> persons;
	Pos pos(0, 0);
	for (int i = 0; i < 10; ++i)
	{
		pos.x = (float)i * 5 / 2;
		pos.y = (float)i * 8 / 3;
		persons.push_back(shared_ptr<Person>(new Person("person" , pos, i % 2 == 0)));
	}

	vector<unique_ptr<Police>> police;
	for (int i = 0; i < 5; ++i)
	{
		pos.x = (float)i * 7 / 3;
		pos.y = (float)i * 8 / 3;
		police.push_back(unique_ptr<Police>(new Police(pos)));
	}


	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	for (int x : v)
	{
		cout << x << endl;
	}

	
	for(auto& p: police)
	{
		for (auto& person : persons)
		{
			if (p->x() > person->x() && person->infected())
			{
				p->writeTicket();
			}
		}
	}
	for (auto& p : police)
		cout << p->tickets() << endl;
	
	cin.get();
	return 0;
}