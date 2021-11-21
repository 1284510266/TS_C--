#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

struct person
{
    int age;
    int sex;
    string name;
    string address;
    string phone;
};

struct Addressbooks{
    struct person personArray[MAX];
    int size;
};
void showMenu()
{
    cout<< "1,添加联系人" << endl;
    cout<< "2,显示联系人" << endl;
    cout<< "3,删除联系人" << endl;
    cout<< "4,查找联系人" << endl;
    cout<< "5,修改联系人" << endl;
    cout<< "6,清空联系人" << endl;
    cout<< "0,退出通讯录" << endl;
}
void addPerson(Addressbooks *adds)
{
    //先判断通讯录是否满
    if(adds->size == MAX){
        cout<< "通讯录已满"<<endl;
        return;
    }else{
        //姓名
        string name;
        cout<<"请输入一个姓名"<<endl;
        cin>>name;
        adds->personArray[adds->size].name = name;
        //性别
        int sex;
        cout<< "请输入性别：1代表男；2代表女"<<endl;
        while(true){
            cin>>sex;
            if(sex == 1 || sex == 2){
                adds->personArray[adds->size].sex = sex;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }
        //年龄
        cout<<"请输入年龄"<<endl;
        int age;
        cin>>age;
        adds->personArray[adds->size].age = age;
        //地址
        cout<< "请输入地址"<<endl;
        string address;
        cin>>address;
        adds->personArray[adds->size].address = address;
        //电话
        cout<< "请输入电话"<<endl;
        string phone;
        cin>>phone;
        adds->personArray[adds->size].phone = phone;
        //更新人数
        adds->size++;
        cout<<"添加成功"<<endl;
        //在添加成功之后，可以执行一个清屏操作。
    }
    system("pause");
    system("cls");
}
//显示联系人
void showPerson(Addressbooks *adds){
    if(adds->size == 0){
        cout<<"当前记录为空"<<endl;
    }else{
        for(int i = 0; i < adds->size;i++){
            cout<<"姓名："<<adds->personArray[i].name<<endl;
            cout<<"性别："<<adds->personArray[i].sex<<endl;
            cout<<"年龄："<<adds->personArray[i].age<<endl;
            cout<<"电话："<<adds->personArray[i].phone<<endl;
            cout<<"住址："<<adds->personArray[i].address<<endl;
        }
    }    
    system("pause");
    system("cls");
}
int main()
{
    Addressbooks adds;
    adds.size = 0;

    int num = 0;
    while(true){
        showMenu();
        cin >> num ;
        switch (num)
        {
        case 0://退出通讯录
            cout << "欢迎您下次使用" <<endl;
            system("pause");
            return 0;
            break;
        case 1://添加
            addPerson(&adds);
            break;
        case 2://显示
            showPerson(&adds);
            break;
        case 3://
            break;
        case 4://
            break;
        case 5://
            break;
        case 6://
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}