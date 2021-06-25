#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "../part B/cached_map.h"

using namespace std;

class Employee
{
public:
    Employee(const string& id = "", const int &salary = 0, const int &seniority = 0) : id(id), salary(salary), seniority(seniority){}
    ~Employee(){}

    void load(istream &in);
    void save(ostream &out);

    string getId() const { return id; }
    int getSalary() const { return salary; }
    int getSeniority() const { return seniority; }

    friend ostream &operator <<(ostream &out, const Employee &e)
    {
        return out << e.id << endl << e.salary << endl << e.seniority << endl;
    }
private:
    string id;
    int salary;
    int seniority;    
};