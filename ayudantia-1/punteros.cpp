#include <iostream>

using namespace std;

int main(int argc, char**argv)
{
    int vector[5];
    int *p1, *p2, *p3, *p4, *p5;

    p1 = &vector[4];
    *p1 = 10;
    p2 = p1 - 1;
    *p2 = *p1- 5+ p1;
    *(p1-1) = 5;
    p4 = p2;
    *p4 = vector[2] + *p1 + *p2;
    vector[3] = *(p1-p4);

    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
    cout << *p4 << endl;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;

    

    return 0;
}