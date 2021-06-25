#include "employee.h"

void Employee::load(istream &in)
{
    int len;
    char* buffer;
    in.read((char*)&len, sizeof(len));
    buffer = new char[len+1];
    buffer[len] = 0;
    in.read(buffer, len);
    id = buffer;
    delete[] buffer;
    in.read((char*)&salary, sizeof(salary));
    in.read((char*)&seniority, sizeof(seniority));
}

void Employee::save(ostream &out)
{
    int len = id.length();
    out.write((char*)&len, sizeof(len));
    out.write(id.c_str(), len);
    out.write((char*)&salary, sizeof(salary));
    out.write((char*)&seniority, sizeof(seniority));
}