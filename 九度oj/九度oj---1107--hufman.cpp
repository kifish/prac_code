#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<string>

using namespace std;

priority_queue<int,vector<int>,greater<int> > Q;
int main(){
    int n;
    int res;
    int a,b;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        while(!Q.empty()){Q.pop();}
        while(n--){
            scanf("%d",&a);
            Q.push(a);
        }
        res=0;
        while(Q.size()>1){
            a=Q.top();
            Q.pop();
            b=Q.top();
            Q.pop();
            res+=a+b;
            Q.push(a+b);
        }
        printf("%d\n",res);
    }
    return 0;
}
