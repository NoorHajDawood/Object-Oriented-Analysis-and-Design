#include <iostream>
#include "pointers.h"
#include <memory>

using namespace std;

int main()
{
	
	std::unique_ptr<int> p1(new int(6));
	std::unique_ptr<int> p2(std::move(p1));
	std::unique_ptr<int> p3(std::move(p2));

	char ch = (char)121;

	if (nullptr != p1)
		cout << "p1 = " << *p1 << endl;

	if (nullptr != p2)
		cout << "p2 = " << *p2 << endl;

	if (nullptr != p3)
		cout << "p3 = " << *p3 << endl;

	{
		std::shared_ptr<int> s1(new int(6));
		std::shared_ptr<int> s2(s1);
		std::shared_ptr<int> s3 = s2;

		if (nullptr != s1)
			cout << "s1 = " << *s1 << endl;

		if (nullptr != s2)
			cout << "s2 = " << *s2 << endl;

		if (nullptr != s3)
			cout << "s3 = " << *s3 << endl;

		{
			std::shared_ptr<int> s4 = s3;
		}
	}

}


