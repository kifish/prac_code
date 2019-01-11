#include <cstdio>
#include <cstdlib>
#include <string>
#include <stack>
#include <iostream>
using namespace std;
int main(){
    stack<string> raw;
    stack<double> nums;
    string s;
    while(cin>>s){
        raw.push(s);
    }
    while (!raw.empty()){
        s = raw.top();
        raw.pop();
        if(s == "*"){
            double b = nums.top();
            nums.pop();
            double a = nums.top();
            nums.pop();
            double res = a * b;
            nums.push(res);
        }
        else if(s == "/"){
            double b = nums.top();
            nums.pop();
            double a = nums.top();
            nums.pop();
            double res = a / b;
            nums.push(res);
        }
        else if(s == "+"){
            double b = nums.top();
            nums.pop();
            double a = nums.top();
            nums.pop();
            double res = a + b;
            nums.push(res);
        }
        else if(s == "-"){
            double b = nums.top();
            nums.pop();
            double a = nums.top();
            nums.pop();
            double res = a - b;
            nums.push(res);
        }
        else{
            double num = atof(s.c_str());
            nums.push(num);
        }
    }
    printf("%f\n",nums.top());
    return 0;
}