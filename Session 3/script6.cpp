/*
6.Write a C++ program to create a simple calculator using class template.
 You should be able to perform addition, subtraction, multiplication,
 and division of given two values.
(20 Points)
*/
#include <iostream>
#include <string>

using namespace std;

// --------------------------define the class template--------------------------

template<typename T>
class Calculator{
  private:
    T a, b;
  public:
    Calculator(T arg1, T arg2) : a(arg1), b(arg2) {} // intialization of calculator
    T add() {return (a + b);}
    T subtract() {return (a - b);}
    T multiply() {return (a * b);}
    T divide(){
      if( b == 0 ) {
         throw runtime_error("Division by zero condition!\n");
      }
      else return (a/b);
    }
};
// -----------------------------------------------------------------------------
int main(){
  Calculator<int> intCalculator(5,-1);
  cout << "Addition: " << intCalculator.add() << endl;
  cout << "Subtraction: " << intCalculator.subtract() << endl;
  cout << "Multiplication: " << intCalculator.multiply() << endl;
  cout << "Division: " << intCalculator.divide() << endl;
}
