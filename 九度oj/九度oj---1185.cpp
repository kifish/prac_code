//题目没有考虑最大值重复的情况。
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1005];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        int max;
        max=a[n-1];
        int idx=n-1;
        /*
        for(;a[idx]==max;idx--);
        if(idx==0||idx==-1) {
            printf("%d\n",max);
            printf("-1\n");
        }
        else{
            printf("%d\n",max);
            for(int i=0;i<=idx;i++) {
                if(i!=0) printf(" ");
                printf("%d",a[i]);
            }
            printf("\n");
        }
        */
        if(idx==0) {
            printf("%d\n",max);
            printf("-1\n");
        }
        else{
            printf("%d\n",max);
            for(int i=0;i<n-1;i++){
                if(i!=0) printf(" ");
                printf("%d",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
