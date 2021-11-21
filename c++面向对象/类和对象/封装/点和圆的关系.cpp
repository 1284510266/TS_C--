#include<iostream>
using namespace std;
#include"point.h"
#include"circle.h"
// class Point{
// public:
//     void set_x(int x){
//         p_x = x;
//     }
//     int get_x(){
//         return p_x;
//     }
//     void set_y(int y){
//         p_y = y;
//     }
//     int get_y(){
//         return p_y;
//     }

// private:
//     int p_x;
//     int p_y;
// };

// class Circle{
// public:
//     void set_R(int R){
//         C_R = R;
//     }
//     int get_R(){
//         return C_R;
//     }
//     void set_center(Point center){
//         C_center = center;
//     }
//     Point get_center(){
//         return C_center;
//     }
// private:
//     int C_R;
//     Point C_center;
// };
void isInCircle(Circle &c,Point &p){
    int distance = (c.get_center().get_x()-p.get_x()) *  (c.get_center().get_x()-p.get_x()) + 
                    (c.get_center().get_y() - p.get_y()) * (c.get_center().get_y() - p.get_y());
    int r_distance = c.get_R() * c.get_R();

    if(distance == r_distance){
        cout<< "点在圆上"<<endl;
    }else if(distance > r_distance){
        cout<< "点在园外"<<endl;
    }else
        cout<< "点在圆内"<<endl;
}
int main(){
    Circle c;
    Point center;
    center.set_x(10);
    center.set_y(0);
    c.set_R(10);
    c.set_center(center);
    
    Point p;
    p.set_x(10);
    p.set_y(10);

    isInCircle(c,p);

}