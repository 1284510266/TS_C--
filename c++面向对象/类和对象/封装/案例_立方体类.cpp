#include<iostream>
using namespace std;

//1��ȫ�ֺ���

class Cube{
public:
    //获取长�?�高
    void set_L(int L){
        C_length = L;
    }  
    int get_L(){
        return C_length;
    }

    void set_W(int W){
         C_width = W;
    }
    int get_W(){
        return C_width;
    }

    void set_H(int H){
         C_highth = H;
    }
    int get_H(){
        return C_highth;
    }
    //��������
    int s(){
        return 2 * C_length * C_width + 2 * C_length * C_highth + 2 * C_width * C_highth;
    }
    int v(){
        return C_highth * C_length * C_width;
    }
    //��Ա�����ж�
    bool isSameByClass(Cube &c){
        if(C_highth == c.get_H() && C_length == c.get_L() && C_width == c.get_W())
            return true;
        return false;
    }
private:
    int C_length;
    int C_width;
    int C_highth;
};
bool isSame(Cube &c1,Cube &c2){
    if(c1.get_H() == c2.get_H() && c1.get_L() == c2.get_L() && c1.get_W() == c2.get_W()){
        return true;
    }
    return false;
}
int main(){
    Cube c1;
    c1.set_H(10);
    c1.set_L(10);
    c1.set_W(10);
    cout<<"���"<<c1.s()<<endl;
    cout<<"���"<<c1.v()<<endl;

    Cube c2;
    c2.set_H(10);
    c2.set_L(10);
    c2.set_W(10);

    //�ж��Ƿ����
    bool result = isSame(c1,c2);
    if(result)
        cout<<"c1��c2���"<<endl;
    else 
        cout<<"c1��c2�����"<<endl;
        
    
    result = c1.isSameByClass(c2);
    if(result)
        cout<<"c1��c2���"<<endl;
    else 
        cout<<"c1��c2�����"<<endl;
}