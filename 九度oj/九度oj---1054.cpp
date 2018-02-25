#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char str[205];
bool cmp(char a,char b){
    return a<b; 
}


int main(){
    while(gets(str)){
        sort(str,str+strlen(str),cmp);
        puts(str);
    }
    return 0;
}
