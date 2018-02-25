/*
pat会给出“假条件”。有几个测试点n远大于100了。
set可以逆序遍历。

*/

#include<cstdio>
#include<set>
using namespace std;
set<int> alln;
int num[10000]={0};
int main(){
    int k;
    while(scanf("%d",&k)!=EOF){
        int n=0;
        for(int i=0;i<k;i++){
            scanf("%d",&n);
            alln.insert(n);
            bool isprocessed=0;
            while(n!=1){
                if (!isprocessed&&num[n]>=1) break;
                 if(n%2==0){
                    n=n/2;
                    num[n]++;
                    isprocessed=1;
                }
                else if(n%2==1){
                    n=(3*n+1)/2;
                    num[n]++;
                    isprocessed=1;
                }
                
            }
        }
        bool flag=1;
        set<int>::reverse_iterator iter;
        for(iter=alln.rbegin();iter!=alln.rend();iter++){
            if(flag&&num[*iter]==0){
                printf("%d",*iter);
                flag=0;
            }
            else if(num[*iter]==0){
                printf(" %d",*iter);
            }            
        }
    }
    return 0;
}
