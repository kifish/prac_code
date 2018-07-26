/*
这里的输入条件需要改一下。
while(getline(cin,s)）
可能会跳不出循环。
改成下面的即可：
while(getline(cin,s)&&s!="")
 
此题运算过程中似乎可以是int
但这题目描述有问题。输入一行内 可能有多组数据！  可能会只有一个数字！不需要四舍五入！
须改成：
while(cin>>s)



解释参考：

http://blog.sina.com.cn/s/blog_60263c1c0101ck25.html

 

 

 

 

没改输出格式，也可能WA。

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
    int num;
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

int cal(){
    int a,b;
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
    while(cin>>s){
        for(string::iterator it=s.end();it!=s.begin();it--){
            if(*it==' '){
                s.erase(it);  
            }
        }
        while(!S.empty()) S.pop();
        while(!q.empty()) q.pop();
        change();
        int res=cal();

        printf("%d\n",res);
    }
    return 0;
}
