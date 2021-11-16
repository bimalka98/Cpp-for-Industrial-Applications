#include<iostream>
using namespace std;

int main(){
  // cout << "Running" << endl;
  // int arr[] = {1,2,3};
  // cout << arr << endl;
  // cout << &arr[2] << endl;

  // dynamic arras allocations
  // int size;
  // cin >> size;
  // int* arr = new int[size];
  // arr[0] = 5;

  // int aiData[3][3] = {1,2,3,4,5,6,7,8,9};
  // cout << **aiData << endl;
  // cout << *(*aiData+1) << endl;
  // cout << **(aiData+1) << endl;
  // ications/Session 3$ ./main.out
  // 1
  // 2
  // 4
  int *p = nullptr;
  int &r = *p;
  cout << r << endl;
}
