/*
5.Write a C++ program to swap two values of same type using function template.
(20 Points)
*/

#include <iostream>
#include <string>

using namespace std;

// ------------------defining the function template------------------

template<typename T>
void swap(T* arg1, T* arg2){
  T temp = *arg1;
  *arg1 = *arg2;
  *arg2 = temp;
}
// ------------------------------------------------------------------

int main(){
  // behavior of swap function for integers
  int ia = 5;
  int ib = 10;
  cout << "ia: " << ia << " ib: " << ib << endl;
  swap(&ia,&ib);
  cout << "ia: " << ia << " ib: " << ib << endl;

  // behavior of swap function for floats
  float fa = 5.2;
  float fb = 10.6;
  cout << "fa: " << fa << " fb: " << fb << endl;
  swap(&fa,&fb);
  cout << "fa: " << fa << " fb: " << fb << endl;

  // behavior of swap function for strings
  string sa = "Bimalka";
  string sb = "Piyaruwan";
  cout << "sa: " << sa << " sb: " << sb << endl;
  swap(&sa,&sb);
  cout << "sa: " << sa << " sb: " << sb << endl;

  return 0;
}
