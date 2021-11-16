/*
7.Write a specialized member function to perform addition for
string datatype.
(20 Points)
*/

#include <iostream>
#include <string>

using namespace std;

// --------------------------define the class template--------------------------

template<typename T>
class Addition{
private:
  T a,b;
public:
  Addition(T arg1, T arg2): a(arg1), b(arg2) {} //constructor
  T add(); // addition function declaration
};

//------------------------------------------------------------------------------

// Non-specialized add member function definition
template<typename T>
T Addition<T>::add(){
  cout << "Arithmetic Addition: ";
  return (a +b);
}

// specializing add member function to add strings
template<>
string Addition<string>::add(){
  cout << "Specialized Member Function to add strings: ";
  return (a + b);
}

int main(){
  Addition<int> intAdd(5,9);
  cout << intAdd.add() << endl;
  Addition<string> strAdd("Bim","alka");
  cout << strAdd.add() << endl;
}
