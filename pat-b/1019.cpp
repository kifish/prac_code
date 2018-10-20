/*
注意：有样例会有形如123的数，须补0；
   指数写法pow（10，i）；
   6174要有输出。


*/



#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;
int bit[10];
bool cmp(int a,int b){
    return a<b;
}
bool cmpt(int a,int b){
    return a>b;
}
int process_e(int num){
    int i=0;
    int sum=0;
    while(num!=0){
        bit[i++]=num%10;
        num/=10;        
    }
    while(i<4){
        bit[i++]=0;
    }
    sort(bit,bit+i,cmpt);
    for(int j=0;j<i;j++){
        sum+=(pow(10,(i-j-1)))*bit[j];
    }
    return sum;
}
int process_f(int num){
    int i=0;
    int sum=0;
    while(num!=0){
        bit[i++]=num%10;
        num/=10;        
    }
    while(i<4){
        bit[i++]=0;
    }
    sort(bit,bit+i,cmp);
    for(int j=0;j<i;j++){
        sum+=(pow(10,(i-j-1)))*bit[j];
    }
    return sum;
}
int main(){
    int a,b,c,d;
    int n;
    scanf("%d",&n);
    int e,f;
    e=process_e(n);
    f=process_f(n);
    
    if(e==f){
        printf("%04d - %04d = %04d\n",e,f,e-f);
        return 0;
    }
    do{
        n=e-f;
        printf("%04d - %04d = %04d\n",e,f,e-f);
        e=process_e(n);
        f=process_f(n);
    }while(n!=6174&&n!=0);
    return 0;
}
