# Multiple Choice Questions

1. What is Inheritance in C++? <br>
a) Wrapping of data into a single class <br>
<span style="color:green">**b) Deriving new classes from existing classes** </span> <br>
c) Overloading of classes <br>
d) Classes with same names <br>


2. How many specifiers are used to derive a class? <br>
a) 1 <br>
b) 2 <br>
<span style="color:green">**c) 3** <br></span>
d) 4 <br>



3. Which specifier makes all the data members and functions of base class inaccessible by the derived class? <br>
<span style="color:green">**a) private**</span> <br>
b) protected <br>
c) public <br>
d) both private and protected <br>


4. If a class is derived privately from a base class then ______________________________ <br>
a) no members of the base class is inherited <br>
b) all members are accessible by the derived class <br>
<span style="color:green">**c) all the members are inherited by the class but are hidden and cannot be accessible** </span><br>
d) no derivation of the class gives an error <br>


5. What will be the output of the following C++ code? <br>
```
#include <iostream>
#include <string>
using namespace std;
class A
{
	int a, b;
	float d;
   public:
	void change(int i){
		a = i;
	}
	void value_of_a(){
		cout<<a;
	}
};
 
class B: private A
{
 
};
 
int main(int argc, char const *argv[])
{
	B b;
	cout<<sizeof(B);
	return 0;
}
```
a) 8 <br>
<span style="color:green">**b) 12**</span> <br>
c) Error <br>
d) Segmentation fault <br>


6. What will be the output of the following C++ code? <br>
```
#include <iostream>
#include <string>
using namespace std;
class A
{
	float d;
    public:
	int a;
	void change(int i){
		a = i;
	}
	void value_of_a(){
		cout<<a;
	}
};
 
class B: public A
{
	int a = 15;
    public:
	void print(){
		cout<<a;
	}
};
 
int main(int argc, char const *argv[])
{
	B b;
	b.change(10);
	b.print();
	b.value_of_a();
 
	return 0;
}
```
a) 1010 <br>
<span style="color:green">**b) 1510**</span> <br>
c) 1515 <br>
d) 5110 <br>


7. What will be the output of the following C++ code? <br>
```
#include <iostream>
#include <string>
using namespace std;
class A
{
	float d;
   public:
	A(){
		cout<<"Constructor of class A\n";
	}
};
 
class B: public A
{
	int a = 15;
    public:
	B(){
		cout<<"Constructor of class B\n";
	}
};
 
int main(int argc, char const *argv[])
{
	B b;
	return 0;
}
```
<span style="color:green">**a)
Constructor of class A <br>
Constructor of class B**</span> <br>
b) Constructor of class A <br>
c) Constructor of class B <br>
d)Constructor of class B <br>
Constructor of class A <br>
  
 
8. What is a virtual function in C++? <br>
a) Any member function of a class <br>
b) All functions that are derived from the base class <br>
c) All the members that are accessing base class data members <br>
<span style="color:green">**d) All the functions which are declared in the base class and is re-defined/overridden by the derived class**</span> <br>


9. Which is the correct syntax of declaring a virtual function? <br>
<span style="color:green">**a) virtual int func();**</span> <br>
b) virtual int func(){}; <br>
c) inline virtual func(); <br>
d) inline virtual func(){}; <br>


10. What will be the output of the following C++ code? <br>
```
#include <iostream>
#include <string>
using namespace std;
class A{
	float d;
   public:
	virtual void func(){
		cout<<"Hello this is class A\n";
	}
};
 
class B: public A{
	int a = 15;
public:
	void func(){
		cout<<"Hello this is class B\n";
	}
};
 
int main(int argc, char const *argv[])
{
	B b;
	b.func();
	return 0;
}
```
<span style="color:green">**a) Hello this is class B**</span> <br>
b) Hello this is class A <br>
c) Error <br>
d) Segmentation fault <br>


11. What will be the output of the following C++ code? <br>
```
#include <iostream>
#include <string>
using namespace std;
class A
{
	float d;
     public:
	virtual void func(){
		cout<<"Hello this is class A\n";
	}
};
 
class B: public A
{
	int a = 15;
   public:
	void func(){
		cout<<"Hello this is class B\n";
	}
};
 
int main(int argc, char const *argv[])
{
	A *a;
	a->func();
	return 0;
}
```
a) Hello this is class A <br>
b) Hello this is class B <br>
c) Error <br>
<span style="color:green">**d) Segmentation Fault**</span> <br>


12. What will be the output of the following C++ code? <br>
```
#include <iostream>
#include <string>
using namespace std;
class A
{
	float d;
   public:
	virtual void func(){
		cout<<"Hello this is class A\n";
	}
};
 
class B: public A
{
	int a = 15;
   public:
	void func(){
		cout<<"Hello this is class B\n";
	}
};
 
int main(int argc, char const *argv[])
{
	A *a = new A();
	B b;
	a = &b;
	a->func();
	return 0;
}
```
a) Hello this is class A <br>
<span style="color:green">**b) Hello this is class B**</span> <br>
c) Error <br>
d) Segmentation Fault <br>


13. Which statement is incorrect about virtual function. <br>
a) They are used to achieve runtime polymorphism <br>
<span style="color:green">**b) They are used to hide objects**</span> <br>
c) Each virtual function declaration starts with the virtual keyword <br>
d) All of the mentioned <br>


14. The concept of deciding which function to invoke during runtime is called ______________________ <br>
a) late binding <br>
b) dynamic linkage <br>
c) static binding <br>
<span style="color:green">**d) both late binding and dynamic linkage**</span> <br>


15. What is a pure virtual function? <br>
a) A virtual function defined inside the base class <br>
<span style="color:green">**b) A virtual function that has no definition relative to the base class**</span> <br>
c) A virtual function that is defined inside the derived class <br>
d) Any function that is made virtual <br>

