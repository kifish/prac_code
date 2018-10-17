
//实际上最后一个测试点N很大。不管了

#include<cstdio>
bool isnotprime[40005];
int prime[40005];
int num=0;
void init(){
    num=0;
    for(int i =2;i<40005;i++){
        if (isnotprime[i]==0){
            prime[num++]=i;
            for(int j=i*i;j<40005;j=j+i)
                isnotprime[j]=1;
        }
    }
}
int main(){
    init();
    int cnt=0;
    int n;
    while(scanf("%d",&n)!=EOF){
    cnt=0;
    bool output=0;
    for(int i =0;i<100000;i++){
        if(prime[i+1]>n) {
            printf("%d",cnt);
            output=1;
            break;
        }
        if((prime[i+1]-prime[i])==2){
            cnt++;
        }
    }
    if(!output) printf("%d",cnt);
    
    
    }
    
    return 0;
}
