//A.


#include<cstdio>
int main(){
    int n,m;
    int sum;
    while(scanf("%d %d",&m,&n)!=EOF){
        sum=0;
        for(int i=m;i<=n;i++){
            if(i%17==0) sum+=i;
        }
        printf("%d",sum);
    }
    return 0;
}

 

//http://bailian.openjudge.cn/jssxly2016/A/

