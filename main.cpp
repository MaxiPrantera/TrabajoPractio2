
#include<iostream>
#include "Complejo.h"
using namespace std;

int main()
{
Complejo a, b(2,3) , c(b);
cout<<"a vale"<<endl;
std::cout<<a.getReal()<<" "<< a.getImag()<<endl;

cout<<" b vale"<<endl;
std::cout<<b.getReal()<<" "<< b.getImag()<<endl;

cout<<"c vale"<<endl;
std::cout<<c.getReal()<<" "<<c.getImag()<<endl;

cout<<"a=b+c"<<endl;
a=b+c;

cout<<" a vale"<<endl;
std::cout<<a.getReal()<<" "<< a.getImag()<<endl;

cout<<"suma el complejo b y el real 5"<<endl;
a=b + 5;
std::cout<<a.getReal()<<" "<< a.getImag()<<endl;




return 0;}
