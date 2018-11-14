/*
'O'操作的后面可能会有多余的空格
cin>>temp  可以跳过回车和换行

 


*/


#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<string>

using namespace std;

stack<int> S;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        while(!S.empty()) S.pop();
        char temp;
        int num;
        while(n--){
            /*
            getchar();
            scanf("%c",&temp);
            */
            cin>>temp;
            if(temp=='A'){
                if(!S.empty()){
                    printf("%d\n",S.top());
                }
                else printf("E\n");
            }
            else if(temp=='P'){
                scanf("%d",&num);
                S.push(num);        
            }
            else{
                if(!S.empty()){
                    S.pop();
                    //printf("\n");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
