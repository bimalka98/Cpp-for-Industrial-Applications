#include <iostream>
using namespace std;

class Shape {
protected:
    int width, height;
public:
    Shape (int a = 0, int b = 0) { // constructor
        width = a; height = b;
    }
    virtual int area () { // simple fucntion to display the results
        cout << "Shape clas area | Base class | :" << '\n';
        return 0;
    }
};

class Rectangle : public Shape { // Derived class from class shape
public:
    Rectangle (int a = 0, int b = 0): Shape(a,b){ } //ctor
    int area () { // simple fucntion to display the results
        cout << "Rectangle class area | Derived class | :" << '\n';
        return ( width * height );
    }
};

class Triangle : public Shape { // Derived class from class shape
public:
    Triangle (int a = 0, int b = 0): Shape(a,b) {} //ctor
    int area () { // simple fucntion to display the results
        cout << "Triangle class area | Derived class | :" << '\n';
        return ( width * height/2 );
    }
};

/*
int main () {
    Shape* shape; // Pointer object of type shape
    Rectangle rec (10, 7); // Rectange object
    Triangle tri (10, 5); // Triangle object
    shape = &rec; // store the address of Rectange
    cout << shape->area () << '\n';// call rectange area using this pointer
    shape = &tri; // store the address of triangle
    cout << shape->area () << '\n'; // call triangle area using this pointer
    return 0;
}
*/
