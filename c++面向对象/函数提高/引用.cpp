#include<iostream>
using namespace std;

int main(){
    int a = 10;
    cout<<"a ��ֵΪ"<< a << endl;
    int &b = a;
    cout<<"b ��ֵ"<< a << endl;
    b = 20;
    cout<<"a ���ĺ��ֵΪ"<< a << endl;
}