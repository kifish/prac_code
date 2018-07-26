#include<cstdio>
#include<algorithm>
using namespace std;
struct Program{
    int s;
    int e;
    bool operator < (const  Program &A) const{
        return e<A.e;
    }
}program[105];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        for(int i=0;i<n;i++){
            scanf("%d %d",&program[i].s,&program[i].e);
        }
        sort(program,program+n);
        int res=0;
        int cur=0;
        for(int i=0;i<n;i++){
            if(cur<=program[i].s){
                cur=program[i].e;
                res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;

}
