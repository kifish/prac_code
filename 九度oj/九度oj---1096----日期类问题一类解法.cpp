/*
选择参考点，0年1月1日（认为是闰年）。日期a，日期b，算出abs（（a-0）-（b-0））.视情况加1，若连续的日期视为两天，则res=abs（（a-0）-（b-0））+1 .



*/


#include<cstdio>

int isleap(int n){
    if((n%100!=0&&n%4==0)||n%400==0)
        return 1;
    else return 0;
}
int dayofmonth[13][2]={
0,0,
31,31,
28,29,
31,31,
30,30,
31,31,
30,30,
31,31,
31,31,
30,30,
31,31,
30,30,
31,31,
};  //****//
struct date{
    int d;
    int m;
    int y;
    void nextday(){
        d++;
        if(d>dayofmonth[m][isleap(y)]){
            m++;
            d=1;
        
            if(m>12){
                m=1;
                y++;
            }
        }
    }
};

int process[5005][13][32];
int abs(int x){
    return x<0?-x:x;
}
int main(){
    date tmp;
    int cnt=0;
    tmp.d=1;
    tmp.m=1;
    tmp.y=0;
    while(tmp.y!=5001){
        process[tmp.y][tmp.m][tmp.d]=cnt;
        tmp.nextday();
        cnt++;
    }

    int d1,m1,y1;
    int d2,m2,y2;
    while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF){
        scanf("%4d%2d%2d",&y2,&m2,&d2);
        int res=abs(process[y1][m1][d1]-process[y2][m2][d2])+1;
        printf("%d\n",res);    
    }
    return 0;
}
