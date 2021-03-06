// class A is privately inherited. Therefore, the mul() function of class 'A' cannot be accessed by the object of class B. 
// It can only be accessed by the member function of class B.

#include <iostream>  
using namespace std;  
class A  
{  
    int a = 4;  
    int b = 5;  
    public:  
    int mul()  
    {  
        int c = a*b;  
        return c;  
    }     
};  
  
class B : private A  
{  
    public:  
    void display()  
    {  
        int result = mul();  
        std::cout <<"Multiplication of a and b is : "<<result<< std::endl;  
    }  
};  
int main()  
{  
   B b;  
   b.display();  
  
    return 0;  
} 
//output : Multiplication of a and b is : 20 