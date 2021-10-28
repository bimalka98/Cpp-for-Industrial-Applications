#include<iostream>
using namespace std;

void swapInts(int* a, int* b){
  int temp = *a; 
  *a = *b;
  *b = temp;
}

int main(){
  int num1 = 10;
  int num2 = 20;

  cout << "Before swapping" << endl;
  cout << "1st Number : " << num1 << endl;
  cout << "2nd Number : " << num2 << endl;

  swapInts(&num1, &num2);
  cout << "After swapping" << endl;
  cout << "1st Number : " << num1 << endl;
  cout << "2nd Number : " << num2 << endl;

}
