#include <iostream>
using namespace std;

class Singleton{
public:
  // declaration of static member function
  /*
static methods are the only methods that can be called
without creating an object!
  */
  static Singleton *getInstance();

private:
  Singleton() {} // private constructor
  static Singleton* instance; // Static variable
};

//invoke the static members using the class name and the scope
// resolution operator
Singleton* Singleton::instance = 0;

// method definition
Singleton* Singleton::getInstance(){
  if(!instance){
    instance = new Singleton();
    cout << "getInstance(): First instance\n";
    return instance;
  }else{
    cout << "getInstance(): Previous instance\n";
    return instance;
  }
}

int main(){
  // instance variable can only be accessed by the member function
  Singleton *s1 = Singleton::getInstance(); // new object is created

  Singleton *s2 = Singleton::getInstance();// no new object is created.

  //Singleton * s3 = new Singleton();
  //error: ‘Singleton::Singleton()’ is private within this context

  cout << "Are objects the same? " << (s1==s2) << '\n';
  return 0;
}
