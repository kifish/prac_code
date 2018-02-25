#include<cstdio>
int main(){
    char cstr[90][90];
    int num = 0;
    while(scanf("%s",cstr[num])!=EOF) {num++;}
    for(int i = num-1;i>=0;i--){
        printf("%s",cstr[i]);
        if(i>0) printf(" ");
    }
    return 0;
}
