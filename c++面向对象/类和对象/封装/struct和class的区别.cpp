#include<iostream>
using namespace std;

class C1{
    int a = 10;
};
struct C2{
    int b = 20;
};
int main(){
    C1  c1;
    //c1.a;//不可访问
    C2 c2;
    cout<<c2.b<<endl;
}