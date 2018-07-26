

/*
用char接收输入似乎会很麻烦.

 scanf("% d",&num[(i+m)%n]);

 scanf(" %d",&num[(i+m)%n]);
注意以上两者的区别，scanf占位符后面才有效。

printf(" %d",num[i]);
printf("% d",num[i]);
注意以上两者的区别，输出时似乎效果一样.

*/

#include<cstdio>
int num[105];
int main(){
    
    int n=0;
    int m=0;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i =0;i<n;i++){
            scanf("%d",&num[(i+m)%n]); 
        }
        for(int i=0;i<n;i++) {
            if (i==0) printf("%d",num[i]);
            else printf(" %d",num[i]);
        }
    }
    return 0;
}
