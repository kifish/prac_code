#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[501];

queue<int> Q;

int main(){
    int inDegree[501];
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++){
            inDegree[i]=0;
            edge[i].clear();
            
        }
        while(m--){
            int a,b;
            scanf("%d %d",&a,&b);
            edge[a].push_back(b);
            inDegree[b]++;
        }
        while(!Q.empty()) Q.pop();
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                Q.push(i);
            }
        }
        int cnt=0;
        while(!Q.empty()){
            int nowP=Q.front();
            Q.pop();
            cnt++;
            for(int i=0;i<edge[nowP].size();i++){
                inDegree[edge[nowP][i]]--;
                if(inDegree[edge[nowP][i]]==0){
                    Q.push(edge[nowP][i]);
                }
            }
        }
        if(cnt==n) puts("YES");
        else puts("NO");
    }
    return 0;
}
