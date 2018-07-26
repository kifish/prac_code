#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int mypow(int k){
    int res=1;
    while(k--){res*=10;}
    return res;
}


int main(){
    int sum;
    int a,b,k;
    while(scanf("%d %d %d",&a,&b,&k)!=EOF){
        int tmp=mypow(k);
        if(a%tmp==b%tmp)
            printf("-1\n");
        else printf("%d\n",a+b);
    }
    return 0;
}
