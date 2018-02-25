#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > Q;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int tmp;
        while(!Q.empty()) Q.pop();
        while(n--) {
            scanf("%d",&tmp);
            Q.push(tmp);
        }
        int ans=0;
        while(Q.size()>1){
            int x=Q.top();
            Q.pop();
            int y=Q.top();
            Q.pop();
            ans+=x+y;
            Q.push(x+y);
        }
        printf("%d\n",ans);
    }
    return 0;
}
