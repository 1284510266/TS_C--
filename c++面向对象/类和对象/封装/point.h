#pragma once
#include <iostream>
using namespace std;

class Point{
public:
    void set_x(int x);

    int get_x();

    void set_y(int y);
    
    int get_y();
private:
    int p_x;
    int p_y;
};
