#include <iostream>
using namespace std;

struct Base {
    virtual void virtualFunction () {
        cout << "Base\n";
    }
};

struct Derived : Base 	{
    void virtualFunction () override {
        cout << "Derived\n";
    }
};

int main () {
    Base b;
    Derived d;

    cout << "Vrtual function call through reference\n";
    Base& br = b; // reference to the object b
    Base& dr = d; // reference to the object d
    br.virtualFunction (); // prints base
    dr.virtualFunction (); // prints derived

    cout << "virtual function call through pointer\n";
    Base* bp = &b; // pointer to the b, using address of b
    Base* dp = &d; // pointer to the d, using address of d
    bp->virtualFunction (); // prints base
    dp->virtualFunction (); // prints derived

    cout << "non-virtual fucntion call\n";
    br.Base::virtualFunction (); // prints base
    dr.Base::virtualFunction (); // prints base

    return 0;

}