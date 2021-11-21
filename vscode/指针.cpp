#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p;
    p = &a;
    cout << &a <<endl;
    cout << p << endl;
    cout <<"ÄãºÃ"<<endl;
    cout << "sizeof(int *)" << sizeof(p) <<endl;
}