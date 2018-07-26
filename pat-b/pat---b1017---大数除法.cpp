
//注意a<b的情况，商为0.（商至少有一位）
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
#define maxdigit 1010
struct bigInteger{
    int bit[maxdigit];
    int size;
    void init(){
        memset(bit,0,sizeof(bit));
        size=0;
    }
};

bigInteger process(string a){
    bigInteger res;
    for(int i=0;i<a.size();i++){
        res.bit[i]=a[a.size()-1-i]-'0';
    }
    res.size=a.size();
    return res;
};

bigInteger divide(bigInteger a,int b,int &r){
    bigInteger res;
    res.init();
    //int r=0;
    for(int i=a.size-1;i>=0;i--){
        r*=10;
        res.bit[i]=(r+a.bit[i])/b;
        r=(r+a.bit[i])%b;
    }
    int i=maxdigit-1;
    while(res.bit[i]==0&&i>=1){i--;}
    res.size=i+1;
    return res;
};

void output(bigInteger a){
    for(int i=a.size-1;i>=0;i--){
        printf("%d",a.bit[i]);
    }
}

int main(){
    string a;
    int b=0;
    while(cin>>a){
        scanf("%d",&b);
        int r=0;
        bigInteger k=process(a);
        bigInteger res=divide(k,b,r);
        output(res);
        printf(" %d\n",r);
    }
    return 0;
}
