// #include <jni.h>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#define PI 3.14159265358979323846
#define NegativeNumberMove 2
#define FactorialNumberMove 2

using namespace std;

string SinResult(string str);
string CosResult(string str);
string TanResult(string str);
string LgResult(string str);
string LnResult(string str);
string RadicalResult(string str);
int FactorialResult(int n);
bool  opAisBiggerThanOpB(string opA,string opB);
bool  IsANumber(const char str);
bool IsAInteger(string str);
bool IsNumber(string str);

string InfixToPostFix(string str) {
    queue<string> result;  // 后缀表达式的输出栈
    stack<string> symbol; // 后缀表达式的符号栈
    std::vector<string> OutStr_;
    string CToJava, InStr_;
    int position, size_ ,count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 's' || str[i] == 'c' || str[i] == 't' ||
            (str[i] == 'l' && str[i + 1] == 'g') || (str[i] == 'l' && str[i + 1] == 'n')) {
            position = str.find(")", i);  // 返回数组下标
            InStr_ = str.substr(i, position - i + 1); // 第二个参数是长度。
            switch (str[i]) {
                case 's':
                    OutStr_.push_back(SinResult(InStr_));
                    break;
                case 'c':
                    OutStr_.push_back(CosResult(InStr_));
                    break;
                case 't':
                    OutStr_.push_back(TanResult(InStr_));
                    break;
                case 'l':
                    if (str[i + 1] == 'g') {
                        OutStr_.push_back(LgResult(InStr_));
                    } else {
                        OutStr_.push_back(LnResult(InStr_));
                    }
            }
            i = position;
        }
        // maybe not include a ( )
        if (str[i] == '$') {
            if (str[i + 1] == '(') {
                position = str.find(")", i);
                InStr_ = str.substr(i, position - i + 1);
            } else {
                int j = i + 1;
                while (IsANumber(str[j])) {
                    j++;
                }
                position = j - 1; // 定位到最后一位数字
                InStr_ = str.substr(i, position - i + 1);
            }
            OutStr_.push_back(RadicalResult(InStr_));
            i = position;
        }
        // x!
        if (str[i] == '!' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' ||
            str[i] == '^' || str[i] == '(' || str[i] == ')') {
            switch (str[i]) {
                case '!':
                    OutStr_.push_back("!");
                    break;
                case '+':
                    OutStr_.push_back("+");
                    break;
                case '-':
                    OutStr_.push_back("-");
                    break;
                case '*':
                    OutStr_.push_back("*");
                    break;
                case '/':
                    OutStr_.push_back("/");
                    break;
                case '^':
                    OutStr_.push_back("^");
                    break;
                case '(':
                    OutStr_.push_back("(");
                    break;
                case ')':
                    OutStr_.push_back(")");
                    break;
            }
            i++;
        }
        // normal number get_in  OutStr_
        if (IsANumber(str[i])) {
            while (IsANumber(str[i])) {
                count++;
                cout<<"d"<<endl;
            }
            InStr_ = str.substr(i, count);
            OutStr_.push_back(InStr_);
        }
    }
    /*
     * after the for loop , the string OutStr_ will only have + - * / ^ ! ( )
     * the priority is the same order ,from left to right, higher
     */
    size_ = OutStr_.size();
    //negative number
    int i = 0;
    string NativeNumber = "";
    for(i = 1;i < size_;i++){
        if(OutStr_.at(i) == "-" && OutStr_.at(i-1) == "("){
            int j = i;
            while(OutStr_.at(j) != ")"){
                NativeNumber += OutStr_.at(j);
                j++;
            }
            OutStr_.insert(OutStr_.begin()+i-1,NativeNumber);
            OutStr_.erase(OutStr_.begin()+i,OutStr_.begin()+NativeNumber.size()+i+NegativeNumberMove);
        }
    }
    i = 0;
    //eliminate !
    while(i < size_){
        if(OutStr_.at(i) == "!"){
            if(i == 0 || !IsAInteger(OutStr_.at(i-1))){
                OutStr_.push_back("出错");
                // return "出错";
            }else {
                    int SToInteger = std::stoi(OutStr_.at(i-1));
                    OutStr_.insert(OutStr_.begin()+i-1,to_string(FactorialResult(SToInteger)));
                    OutStr_.erase(OutStr_.begin()+i,OutStr_.begin()+i+FactorialNumberMove); // gu tou bu gu wei
                    i--; // a new element is coming to i position;
            }
        }
        i++;
    }
    // check for error

    for(i = 0;i < size_; i++){
        if(OutStr_.at(i) == "出错"){
            return "出错";
        }
    }
    // Infix To PostFix
    for(i = 0;i <size_;i++){
        if(IsNumber(OutStr_.at(i))){
            result.push(OutStr_.at(i));
        }else{
            while(OutStr_.at(i) != ")"){
                if (symbol.empty() || OutStr_.at(i) == "(" || opAisBiggerThanOpB(OutStr_.at(i), symbol.top())) {
                    symbol.push(OutStr_.at(i));
                }else{
                    while (!opAisBiggerThanOpB(OutStr_.at(i),symbol.top()) && !symbol.empty() && (symbol.top() != "(")){
                            result.push(symbol.top());
                            symbol.pop();
                    }
                    symbol.push(OutStr_.at(i));
                }
            }
            // when the OutStr_.at(i) = ")"
            while (symbol.top() != "("){
                result.push(symbol.top());
                symbol.pop();
            }
            symbol.pop();
        }
    }
    while(!symbol.empty()){
        result.push(symbol.top());
        symbol.pop();
    }
    string sm = "";
    while(!result.empty()){
        sm += result.front();
    }
    return sm;
}
// string PostFixToNumber(string str){
//     // hou zhui to number

// }
/*
 * 优先级判断
 */
bool  opAisBiggerThanOpB(string opA,string opB){
    bool res = false;
    if(opA == "^" && opB != "^"){
        res = true;
    }else if(opA == "*" || opA == "/" && opB != "*" && opB != "/" && opB != "^"){
        res = true;
    }
    return res;
}
bool IsNumber(string str){
    bool IsNumber_True = true;
    if(str == "+" || str == "-" || str == "*" || str == "/" || str == "^" ){
        IsNumber_True = false;
    }
    return IsNumber_True;
}
bool IsANumber(const char str){
    int ToAscii = (int)str;
    bool result = false;
    if(ToAscii >= 48 && ToAscii <= 57 || ToAscii == 46){
        // include dot
        result = true;
    }
    return result;
}
bool IsAInteger(string str){
    // if str = "12.",then still true.
    bool result = false;
    double SToDouble = std::stod(str);
    int IsAboveZero = (int) SToDouble;
    if((SToDouble - (double) IsAboveZero) == 0){
        result = true;
    }
    return result;
}
int FactorialResult(int n){
    if(n == 0){
        return 1;
    }else{
        return n * FactorialResult(n-1);
    }
}
string SinResult(string str){
    // str="s(xxx)" represent sin(xxx);
    double OutSin;
    string s = "sin30";
    int len = str.length();
    OutSin = std::stod(str.substr(2,len-2));
    OutSin = sin(OutSin/180*PI);
    return std::to_string(OutSin);
}
string CosResult(string str){
    // str="c(xxx)" represent cos(xxx);
    double OutCos;
    int len = str.length();
    OutCos = std::stod(str.substr(2,len-2));
    OutCos = cos(OutCos/180*PI);
    return std::to_string(OutCos);
}
string TanResult(string str){
    // str="t(xxx)" represent tan(xxx);
    double OutTan;
    int len = str.length();
    OutTan = std::stod(str.substr(2,len-2));
    OutTan = tan(OutTan/180*PI);
    return std::to_string(OutTan);
}
string LgResult(string str){
    // lg(xxx)
    double OutLg;
    int len = str.length();
    OutLg = std::stod(str.substr(3,len-2));
    string s = "";
    return s;

}
string LnResult(string str){

}
string RadicalResult(string str){
    double OutRadical;
    int len = str.length();
    string s = "";
    return s;
}
string AddResult(string num1,string num2){
    // x+y
    double num_1,num_2;
    num_1 = std::stod(num1);
    num_2 = std::stod(num2);
    return std::to_string(num_1+num_2);
}
string SubResult(string num1,string num2){
    // x-y
    double num_1,num_2;
    num_1 = std::stod(num1);
    num_2 = std::stod(num2);
    return std::to_string(num_1-num_2);
}

string MulResult(string num1,string num2){
    // x*y
    double num_1,num_2;
    num_1 = std::stod(num1);
    num_2 = std::stod(num2);
    return std::to_string(num_1*num_2);
}
string DivResult(string num1,string num2){
    // x/y
    double num_1,num_2;
    num_1 = std::stod(num1);
    num_2 = std::stod(num2);
    return std::to_string(num_1/num_2);
}
string PowResult(string num1,string num2){
    // x^y
    double  num_1,num_2;
    num_1 = std::stod(num1);
    num_2 = std::stod(num2);
    return std::to_string(pow(num_1,num_2));
}
// extern "C" JNIEXPORT jstring JNICALL
// Java_com_jni_calculatetest_MainActivity_getResult(JNIEnv *env, jobject thiz, jstring s_) {
//     // TODO: implement getResult()
//     const char* s = env->GetStringUTFChars(s_,0);
//     std::string string1 = s;
//     return env->NewStringUTF("hello");
// }
int main(){
    string sn = InfixToPostFix("1+2*3+(4*5+6)+7");
    cout << sn << endl;
}