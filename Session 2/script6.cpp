#include<iostream>
#include<string>
using namespace std;

// define a function to print the months inside the array
void printMonths(string array[], int length){
  for(int i=0; i<length; i++) {
    cout << array[i] << endl;
  }
}

int main(){
  string array[12] = {"January", "February", "March", "April",
              "May", "June", "July", "August","September",
              "October", "November", "December"};
  printMonths(array, 12); // calling the defined function
}
