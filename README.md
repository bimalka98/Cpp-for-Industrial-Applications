# "C++ Concepts for Industrial Applications" by Synopsys

## *Concepts covered in the sessions*
  
- OOP concepts
- Pointers and References
- Templates
- Estimating the memory footprint
- Software Design
- Multi-level build systems
- Applications of Data Structures and Algorithms

---

## *Editor and Compiler configuration*

### Method 1

| |Configuration|
| :------------ | :---------- |
|Editor 1      | Atom (with TabNine Package installed)  |
|Editor 2|Visual Studio Code(with C/C++ and TabNine Packages installed)|
|Compiler |g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 in WSL(Windows Subsystem for Linux)|



> Atom TabNine client is an advanced AI based auto-completer for all programming languages

> VS code C/C++ extension with IntelliSense, debugging, and code browsing

> g++ command is a GNU c++ compiler invocation command, which is used for preprocessing, compilation, assembly and linking of source code to generate an executable file.

**Compilation and Execution**

* `main.cpp` - Contains the Code
* `main.out` - Executable file generated by the compiler

Run following commands in the Linux Shell opened in the same directory as the `main.cpp`

```

:~$ g++ -Wall -o main.out -std=c++0x main.cpp                      //compilation
:~$ ./main.out                                                     //Execution

```

### Method 2

Visual Studio with the add-on ***Desktop development with C++***
