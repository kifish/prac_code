
分解还有问题,未完待续.

复制代码
#include<cstdio>
#include<string>
#include<cstring>
int digitnum[10];
char strnum[35];
string s;
int fenjie(int n){
    sprintf(strnum,"%d",n);
    for(int i=0;i<strlen(strnum);i++){
        digitnum[strnum[i]-'0']++;
    }
    int j=0;
    //for(int i=0;i<10;i++) printf("%d ",digitnum[i]);
    
    for(int i=0;i<10;i++){
        bool stflag=1;
        for(int k=0;k<digitnum[i];k++){
            if(stflag) 
                {    strnum[j++]='0'+digitnum[i];
                    stflag=0;
                }
            strnum[j++]=i+'0';
        }    
    }
    int a;
    sscanf(strnum,"%d",&a);
    return a;
}


int main(){
    int n;
    scanf("%d",&n);
    int nn;
    nn=fenjie(n);
    printf("%d",nn);
    return 0;
}
复制代码
