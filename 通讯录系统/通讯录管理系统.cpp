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
    cout<< "1,�����ϵ��" << endl;
    cout<< "2,��ʾ��ϵ��" << endl;
    cout<< "3,ɾ����ϵ��" << endl;
    cout<< "4,������ϵ��" << endl;
    cout<< "5,�޸���ϵ��" << endl;
    cout<< "6,�����ϵ��" << endl;
    cout<< "0,�˳�ͨѶ¼" << endl;
}
void addPerson(Addressbooks *adds)
{
    //���ж�ͨѶ¼�Ƿ���
    if(adds->size == MAX){
        cout<< "ͨѶ¼����"<<endl;
        return;
    }else{
        //����
        string name;
        cout<<"������һ������"<<endl;
        cin>>name;
        adds->personArray[adds->size].name = name;
        //�Ա�
        int sex;
        cout<< "�������Ա�1�����У�2����Ů"<<endl;
        while(true){
            cin>>sex;
            if(sex == 1 || sex == 2){
                adds->personArray[adds->size].sex = sex;
                break;
            }
            cout<<"������������������"<<endl;
        }
        //����
        cout<<"����������"<<endl;
        int age;
        cin>>age;
        adds->personArray[adds->size].age = age;
        //��ַ
        cout<< "�������ַ"<<endl;
        string address;
        cin>>address;
        adds->personArray[adds->size].address = address;
        //�绰
        cout<< "������绰"<<endl;
        string phone;
        cin>>phone;
        adds->personArray[adds->size].phone = phone;
        //��������
        adds->size++;
        cout<<"��ӳɹ�"<<endl;
        //����ӳɹ�֮�󣬿���ִ��һ������������
    }
    system("pause");
    system("cls");
}
//��ʾ��ϵ��
void showPerson(Addressbooks *adds){
    if(adds->size == 0){
        cout<<"��ǰ��¼Ϊ��"<<endl;
    }else{
        for(int i = 0; i < adds->size;i++){
            cout<<"������"<<adds->personArray[i].name<<endl;
            cout<<"�Ա�"<<adds->personArray[i].sex<<endl;
            cout<<"���䣺"<<adds->personArray[i].age<<endl;
            cout<<"�绰��"<<adds->personArray[i].phone<<endl;
            cout<<"סַ��"<<adds->personArray[i].address<<endl;
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
        case 0://�˳�ͨѶ¼
            cout << "��ӭ���´�ʹ��" <<endl;
            system("pause");
            return 0;
            break;
        case 1://���
            addPerson(&adds);
            break;
        case 2://��ʾ
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