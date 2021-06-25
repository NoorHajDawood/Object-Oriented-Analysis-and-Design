#include "employee.h"

using namespace std;

int main(int argc, char const *argv[])
{
    {
        Employee e1("2020", 2222, 4444), e2("2199", 1929, 49129), e3("0489", 4202, 40221);
        ofstream out("emps.bin", ios::binary | ios::out);
        if (!out.is_open())
        {
            cerr << "Couldn't open emps.bin";
            return -1;
        }
        e1.save(out);
        e2.save(out);
        e3.save(out);
        out.close();
    }

    {
        CacheMemory<string, Employee> cachedMem;
        ifstream in("emps.bin", ios::binary | ios::in);
        if (!in.is_open())
        {
            cerr << "Couldn't open emps.bin";
            return -1;
        }
        int counter = 0;
        while (!in.eof())
        {
            Employee e;
            e.load(in);
            cachedMem.add(e.getId(), e);
        }
        in.close();

        Employee e;
        e = *cachedMem.get("2020");
        cout << e << endl;

        e = *cachedMem.get("2199");
        cout << e << endl;

        e = *cachedMem.get("0489");
        cout << e << endl;
    }

    return 0;
}
