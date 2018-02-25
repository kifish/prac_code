




//1.

#include<cstdio>
int main(){
    int k;
    char t;
    int sum=0;
    while(scanf("%d %c",&k,&t)!=EOF){
        sum=0;
        if(k<=1000) sum+=8;
        if(k>1000) {
            int temp=k-1000;
            int a;
            if(k%500==0)a=temp/500;
            else a =temp/500+1;
            sum=8+a*4;
        }
        if(t=='y') sum+=5;
        printf("%d",sum);
    }
    return 0;
}

//注意检查==还是=；a[1]表示a[1][0]的地址，即&a[[1][0];


//G:Huffman编码树
/*
#include<cstdio>
#include<queue>
using namespace std;
int main(){
    int t;int n;int ans;
    int x;int y;
    priority_queue<int,vector<int>,greater<int> > q;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&n);
            while(n--){
                int temp;
                scanf("%d",&temp);
                q.push(temp);
            }
             ans=0;
             while(q.size()>1){
                 x=q.top();
                 q.pop();
                 y=q.top();
                 q.pop();
                 q.push(x+y);
                 ans+=(x+y);
             }
             printf("%d\n",ans);
             q.pop();
            
        }
    }
    return 0;
}
*/
