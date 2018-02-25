//多点测试

#include<cstdio>
int main(){
    int h;
    while(scanf("%d",&h)!=EOF){
        int blanks;
        int num;
        for(int i=0;i<h;i++){
                num=h+i*2;
            blanks=(3*h-2)-2*i-h;
            while(blanks--) printf(" ");
            while(num--){
                printf("*");
                if(num==0)
                    printf("\n");

            }
        }
    }
    return 0;
}
