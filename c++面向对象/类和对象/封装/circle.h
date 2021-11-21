#pragma once
#include<iostream>
using namespace std;
#include "point.h"
class Circle{
public:
    void set_R(int R);
    int get_R();
    void set_center(Point center);
    Point get_center();
 
private:
    int C_R;
    Point C_center;
};