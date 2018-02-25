
/*
利用日期类的nextday（）；
或者先加一个月的天数，然后判断是否大于给定天数，然后再加一个月的天数，在判断....


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

     int y;
    while(scanf("%d %d",&y,&cnt)!=EOF){
        tmp.d=1;
        tmp.m=1;
        tmp.y=y;
        cnt--;
        while(cnt--){tmp.nextday();}
         printf("%04d-%02d-%02d\n",tmp.y,tmp.m,tmp.d);
    }
    return 0;
}
