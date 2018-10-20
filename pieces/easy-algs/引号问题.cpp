#include<stdio.h>
int main(){
    int c, q = 1;//getchar读取单个字符
    while( (c = getchar() ) != EOF){
        if(c == '"')  { printf("%s", q ? "“" : "''"); q= !q;}
        else printf("%c", c);
    }
    return 0;
} 
