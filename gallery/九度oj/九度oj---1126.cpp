#include<cstdio>
int buf[105];
int main(){
    int n;
    int num;
    bool isfirst;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        isfirst=1;
        for(int i=0;i<num;i++) scanf("%d",&buf[i]);
        if(buf[0]>buf[1]||buf[0]<buf[1]){
            printf("0");
            isfirst=0;
        } 
        for(int i=1;i<num-1;i++){
            if((buf[i-1]<buf[i]&&buf[i]>buf[i+1])||(buf[i-1]>buf[i]&&buf[i]<buf[i+1])){
                
                if(!isfirst)
                    printf(" ");                
                printf("%d",i);
                if(isfirst) isfirst=0;
            }
        }
        if(buf[num-1]>buf[num-2]||buf[num-1]<buf[num-2]){
            if(!isfirst)
                printf(" ");
            printf("%d",num-1);
        }
        printf("\n");
    }
    return 0;
}
