/*
Given the string "A string", print the index, pointer position and
the first letter on the 1st line. Update the pointer to pointer +2.
Then, print the new index, pointer position and the letter on the 2nd
line . Similarly, print the index, pointer position & letters 'r' and
'g' using pointer operations on the following lines.
(20 Points)
*/

#include<iostream>
using namespace std;

int main(){

  // givenString stores the base address of char array
  char givenString[] = "A string";
  // variable to hold the pointer to the letter
  char* chrptr = givenString;

  cout << "Index : " << chrptr-givenString << ", letter : " << *chrptr << '\n';
  chrptr+=2; // incrementing pointer
  cout << "Index : " << chrptr-givenString << ", letter : " << *chrptr << '\n';
  chrptr+=2; // incrementing pointer
  cout << "Index : " << chrptr-givenString << ", letter : " << *chrptr << '\n';
  chrptr+=3; // incrementing pointer
  cout << "Index : " << chrptr-givenString << ", letter : " << *chrptr << '\n';
}
