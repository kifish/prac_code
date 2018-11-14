#include<cstdio>
#include<stack>
using namespace std;
char str[110];
char res[110];
int main(){
    while(scanf("%s",str)!=EOF){
        stack<int> S;
        int i;
        for(i=0;str[i]!=0;i++){
            if(str[i]=='('){
                S.push(i);
                res[i]=' '; 
            }
            else if(str[i]==')'){
                if(!S.empty()){
                    S.pop();
                    res[i]=' ';
                }
                else{
                    res[i]='?';
                }
            }
            else res[i]=' ';        
        }
        while(!S.empty()){
            res[S.top()]='$';
            S.pop();
        }
        res[i]=0;  /*******/
        puts(str);
        puts(res);
    }
    return 0;
        
}
