#include <iostream>
#include <iostream>
#include <string>
using namespace std;
class A{
	private:
		int data;
	public:
		A(int i){ data = i;} 	//自定义的构造函数
		A(const A & a);  			//拷贝构造函数 
		int getdata(){return data;} 
};
//拷贝构造函数 
A::A(const A & a){
	this->data = a.data;
	cout <<"拷贝构造函数执行完毕"<<endl;
}
//参数是对象，值传递，调用拷贝构造函数
int getdata1(A a){
	return a.getdata();
}
//参数是引用，引用传递，不调用拷贝构造函数 
int getdata2(A &a){
	return a.getdata();
} 
//返回值是对象类型，会调用拷贝构造函数
 A getA1(){
 	A a(0);
 	return a;
 } 
 //返回值是引用类型，会调用拷贝构造函数，因为函数体内生成的对象是临时的，离开函数就消失
 A& getA2(){
 	A a(0);
 	return a;
 } 
 int main(){
    A a1(1);  
    A b1(a1);           		//用a1初始化b1，调用拷贝构造函数  
    A c1=a1;            		//用a1初始化c1，调用拷贝构造函数  
    int i=getdata1(a1);        	//函数形参是类的对象，调用拷贝构造函数  
    int j=getdata2(a1);      	//函数形参类型是引用，不调用拷贝构造函数  
    A d1=getA1();       		//调用拷贝构造函数  
    A e1=getA2();     			//调用拷贝构造函数  
    return 0;  
}  