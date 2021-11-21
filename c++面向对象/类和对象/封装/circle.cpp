#include"circle.h"
void Circle::set_R(int R){
    C_R = R;
}
int Circle::get_R(){
    return C_R;
}
void Circle::set_center(Point center){
    C_center = center;
}
Point Circle::get_center(){
    return C_center;
}
