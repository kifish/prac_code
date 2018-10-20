/*

判断边界不好用。可以从后往前扫描。

当然，一行一行扫0之间的255更好。

不用数组也可以。

*/


#include<cstdio>
int map[1005][1005];

int main(){
    int n;
    scanf("%d",&n);
    int stflag=0,edflag=0;
    int sti,stj,edi,edj=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==0&&!stflag){
                stflag=1;
                sti=i;
                stj=j;
            }
            /*
            if(j>=1&&map[i][j-1]==0&&map[i][j]==255&&stflag){  //»òÕß´ÓºóÍùÇ°É¨Ãè£¬ÕÒµ½½áÊøµÄÓÒÏÂ½Ç 
                edi=i;
                edj=j-1;
                //printf("%d %d\n",edi,edj);
            }*/
            
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(map[i][j]==0){
                edi=i;
                edj=j;
                edflag=1;
                break;
            }
        }
        if(edflag) break;
    }
    int cnt=0;
    //printf("%d %d %d %d",sti,stj,edi,edj);
    for(int i=sti;i<=edi;i++){
        for(int j=stj;j<=edj;j++){
            if(map[i][j]==255)
                cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
