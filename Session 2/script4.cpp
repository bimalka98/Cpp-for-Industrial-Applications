/*
Write a program to demonstrate the behavior of pointers.
The expected output should be similar to the above.
*/

#include<iostream>
using namespace std;

int main(){
  int* ab;
  int m = 29;

  cout << "Address of m : " << &m << '\n';
  cout << "Value of m : " << m << "\n\n";

  ab = &m; // Now ab is assigned with the address of m.
  cout << "Address of pointer ab : " << &ab << '\n';
  cout << "contents of pointer ab : " << *ab << "\n\n"; // using dereference operator

  m = 34; // the Value of m assigned to 34 now
  cout << "Address of pointer ab : " << &ab << '\n';
  cout << "contents of pointer ab : " << *ab << "\n\n"; // using dereference operator

  *ab = 7; // the pointer variable ab is assigned the Value 7 now.
  cout << "Address of m : " << ab << '\n';
  cout << "Value of m : " << *ab << "\n\n"; // using dereference operator

}
