#include<cstdio>
#include<algorithm> 
using namespace std;
const int maxn=10005;
struct node{
    int index;
    int cnt;
    node(int _index=-1, int _cnt=0): index(_index),cnt(_cnt){}
}Node[maxn];
bool cmp(node a,node b){
    if(a.cnt!=b.cnt) return a.cnt>b.cnt;
    else return a.index<b.index;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int index;
        for(int i =1;i<n+1;i++){
            if(i>=2) scanf("%c"); //这一行可能需要去掉。
            scanf("%d",&index);
            Node[index].index=index;
            Node[index].cnt++;
        }
    
        sort(Node+1,Node+10001,cmp);
        printf("%d\n",Node[1].index);

    }
    return 0;
}
