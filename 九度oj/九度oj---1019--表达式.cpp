/*
while(getline(cin,s),s!="0")
逗号表达式，返回的是
s!="0"
题目输入的最后一组数据是0



*/



#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<string>
using namespace std;
map<char,int> opmap;

string s;
struct obj{
    double num;
    char op;
    bool isnum;
};
stack<obj> S;
queue<obj> q;
void change(){
    int i=0;
    for(;i<s.size();){
        if('0'<=s[i]&&s[i]<='9'){
            obj tmp;
            tmp.isnum=1;
            tmp.num=0;
            for(;i<s.size()&&'0'<=s[i]&&s[i]<='9';){
                tmp.num*=10;
                tmp.num+=s[i]-'0';
                i++;
            }
            q.push(tmp);
        }
        else{
            while(!S.empty()&&opmap[S.top().op]>=opmap[s[i]]){
                q.push(S.top());
                S.pop();
            }
            obj tmp;
            tmp.isnum=0;
            tmp.op=s[i];
            S.push(tmp);
            i++;
        }
    }
    while(!S.empty()){
        q.push(S.top());
        S.pop();
    }
}

double cal(){
    double a,b;
    obj tmp;
    obj cur;
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(cur.isnum==1)
            S.push(cur);
        else{
            tmp=S.top();
            S.pop();
            b=tmp.num;
            tmp=S.top();
            S.pop();
            a=tmp.num;
            if(cur.op=='+'){
                tmp.num=a+b;
                //tmp.isnum=1;
                S.push(tmp);
            }
            else if(cur.op=='-'){
                tmp.num=a-b;
                S.push(tmp);
            }
            else if(cur.op=='*'){
                tmp.num=a*b;
                S.push(tmp);
            }
            else{
                tmp.num=a/b;
                S.push(tmp);
            }
        }
    }
    return S.top().num;
}

int main(){
    opmap['+']=opmap['-']=1;
    opmap['*']=opmap['/']=2;
    while(getline(cin,s),s!="0"){
        for(string::iterator it=s.end();it!=s.begin();it--){
            if(*it==' '){
                s.erase(it);
            }
        }
        while(!S.empty()) S.pop();
        //while(!q.empty()) q.pop();
        change();
        double res=cal();
        printf("%.2f\n",res);
    }
    return 0;
}
