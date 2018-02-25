#include<cstdio>
#include<cstring>
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
char monthname[13][20]={
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};
char dayname[7][20]={
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};
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

    int d,m,y;
    char s[20]; 

    while(scanf("%d%s%d",&d,s,&y)!=EOF){
        for(m=1;m<=12;m++){
            if(strcmp(s,monthname[m])==0)//代表第m+1行
                break;
        }

    int days=process[y][m][d]-process[2017][6][25]; //2017.6.25是星期天，不需调整days。
    puts(dayname[(days%7+7)%7]); //可处理差值为负的情况
    }
    return 0;
}
