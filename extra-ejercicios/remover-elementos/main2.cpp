#include <iostream>
using namespace std;

class A {
public:
    int x;
    A(int x) { this->x = x; };

    virtual ~A() {
        cout << "Se destruye A" << endl;
    };
};

class B : public A {
public:
    B(int x): A(x) {
    }

    ~B() { cout << "Se destruye B" << endl; };
};

class C : public A {
public:
    C(int x): A(x) {
    }

    ~C() { cout << "Se destruye C" << endl; };
};

int main() {
    A *arrayA[10];

    for (int i = 0; i < 10; i++) {
        if (i % 3 == 2) {
            arrayA[i] = new C(i + 3);
        } else if (i % 3 == 0) {
            arrayA[i] = new B(i * 3);
        } else {
            arrayA[i] = new A(i * 3);
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << arrayA[i]->x << endl;
        delete(arrayA[i]);
    }
    return 0;
}
