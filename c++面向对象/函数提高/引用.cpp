#include<iostream>
using namespace std;

int main(){
    int a = 10;
    cout<<"a 的值为"<< a << endl;
    int &b = a;
    cout<<"b 的值"<< a << endl;
    b = 20;
    cout<<"a 更改后的值为"<< a << endl;
}