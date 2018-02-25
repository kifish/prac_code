#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
map<string,int> M;
int in[1005];
int n;
int main(){
    while(scanf("%d",&n)!=EOF&&n!=0){
        M.clear();
        char str[20];
        string s;
        for(int i=0;i<1005;i++) in[i]=0;
        int idx=0;
        while(n--){
            scanf("%s",str);
            s=str;
            
            int idxa,idxb;
            if(M.find(s)==M.end()){
                idxa=idx;
                M[s]=idx++;
            }
            scanf("%s",str);
            s=str;
            if(M.find(s)==M.end()){
                idxb=idx;
                M[s]=idx++;
            }
            in[M[s]]++;
        }
        int cnt=0;
        for(int i=0;i<idx;i++){
            if(in[i]==0)
                cnt++;
        }
        if(cnt==1)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
