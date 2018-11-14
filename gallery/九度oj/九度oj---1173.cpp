
复制代码
#include<cstdio>
int buf[105];
int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&buf[i]);
        scanf("%d",&m);
        int x;
        while(m--){
            scanf("%d",&x);
            int i=0;
            for(;i<n;i++){
                if(buf[i]==x){
                    printf("YES\n");
                    break;
                }
                
            }
            if(i==n) printf("NO\n");
        
        }
    
    }
    return 0;

}
复制代码
二分查找

复制代码
#include<cstdio>
#include<algorithm>
using namespace std;
int buf[105];
void find(int x,int left,int right){
    if(left>right){
        printf("NO\n");
        return;
    }
    int mid=(left+right)/2;
    if(buf[mid]==x) {
        printf("YES\n");
        return;
    }
    else if(buf[mid]>x){
        return find(x,left,mid-1);    
    }
    else return find(x,mid+1,right);
}
int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&buf[i]);
        scanf("%d",&m);
        sort(buf,buf+n);
        int x;
        while(m--){
            scanf("%d",&x);
            find(x,0,n-1);
        }
    }
    return 0;
}
