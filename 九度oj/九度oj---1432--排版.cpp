
/*
先排版，再输出。
先定位中心坐标，然后定位左上角坐标，然后开始排版，四边同步。左上角起始为（1，1） .



*/

#include<cstdio>
char output[85][85];

int main(){
    int x,y;
    int n;
    char a,b;
    bool isfirst=1;
    while(scanf("%d %c %c",&n,&a,&b)==3){
        for(int size=1,num=1;size<=n;num++,size+=2){
            x=n/2+1-(num-1);
            y=x;
            char tmp=num%2==1?a:b;
            output[x][y]=tmp;//特判n==1 
            for(int i=0;i<=size-2;i++){
                output[x][y+i]=tmp;
                output[x+i+1][y]=tmp;
                output[x+i][y+size-1]=tmp;//四条边不重复。或者也可以多排一次，四条边允许重复 
                output[x+size-1][y+i+1]=tmp;
            }
        }
        if(n!=1){
            output[1][1]=' ';
            output[1][n]=' ';
            output[n][1]=' ';
            output[n][n]=' ';
        }
        if(isfirst)
            isfirst=0;
        else  printf("\n"); 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%c",output[i][j]);
            }
            printf("\n");
        }
    
    }    
    return 0;
}
