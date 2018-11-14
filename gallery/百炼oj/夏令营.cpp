
A.

复制代码
#include<cstdio>

bool isprime[100005];

void init(){
    for(int i=0;i<100001;i++)
        isprime[i]=1;
    isprime[1]=0;
    for(int i=2;i<=100000;i++){
        if(isprime[i]==0) continue;
        else{
            //isprime[i]=1;
            for(int j=2*i;j<=100000;j+=i)
                isprime[j]=0;
        }
        
    }
}
int max(int a,int b){
    if(a>b) return a;
    return b;
}
int x,y;
int main(){
    while(scanf("%d %d",&x,&y)!=EOF){
    
    
    init();
    int cnt=0;
    int ed=max(x,y);
    int st=x+y-ed;
    for(int i=st;i<=ed;i++) {
        if(isprime[i]==1)
            cnt++;
    }
    printf("%d\n",cnt);
    
    }
    return 0;
}
复制代码
B 本地正常，oj返回TLE。可能是因为边判断边存储（数字变字符串等）占用了大量时间。

复制代码
#include<cstdio>
#include<cstring>
char str[1005];
char strre[1005];
char digit[105];
int digitsize;
int main(){
    //while(gets(str)){
        gets(str);
        int cnt=1;
        int size=0;
        char tmp;
        tmp=str[0];
        int i=1;
        //puts(str);
        while(i<=strlen(str)-1){
        
        if(str[i]==tmp+32||str[i]==tmp||str[i]==tmp-32){
            cnt++;
            i++; 
        }
        else{
            strre[size++]='(';  
            //puts(strre);
            if(tmp>='a'&tmp<='z')
                strre[size++]=tmp;
            else strre[size++]=tmp+32;
            strre[size++]=',';
            digitsize=0;
            do{
                digit[digitsize++]=cnt%10;

            }while(cnt/=10);
            while(digitsize){
                strre[size++]=digit[--digitsize]+'0';
            }
            strre[size++]=')';
            cnt=1;
            
            tmp=str[i];
            i++;
        }
        if(i==strlen(str)){
            strre[size++]='(';  
            //puts(strre);
            if(tmp>='a'&tmp<='z')
                strre[size++]=tmp;
            else strre[size++]=tmp+32;
            strre[size++]=',';
            digitsize=0;
            do{
                digit[digitsize++]=cnt%10;

            }while(cnt/=10);
            while(digitsize){
                strre[size++]=digit[--digitsize]+'0';
            }
            strre[size++]=')';
            cnt=1;
            i++;
        }
        
        }
        //printf("%c",strre[0]);
        if(strlen(str)==1){
            strre[size++]='(';  
            //puts(strre);
            if(tmp>='a'&tmp<='z')
                strre[size++]=tmp;
            else strre[size++]=tmp+32;
            strre[size++]=',';
            strre[size++]='1';
            strre[size++]=')';
            
        }
        strre[size]=0;
        puts(strre);
        //printf("%s",strre); 
    //}
    return 0;
}
复制代码
 边判断边输出即可。

复制代码
#include<cstdio>
#include<cstring>
char str[1005];
char strre[1005];
char digit[105];
int digitsize;
int main(){
    
        gets(str);
        int cnt=1;
        int size=0;
        char tmp;
        tmp=str[0];
        int i=1;
        //puts(str);
        int L=strlen(str)-1; 
        while(i<=L){
        
        if(str[i]==tmp+32||str[i]==tmp||str[i]==tmp-32){
            cnt++;
            i++; 
        }
        else{
             
            //puts(strre);
            if(tmp>='a'&tmp<='z')
                printf("(%c,%d)",tmp,cnt);
            else printf("(%c,%d)",tmp+32,cnt);
            cnt=1;
            tmp=str[i];
            i++;
        }
        if(i==strlen(str)){
            if(tmp>='a'&tmp<='z')
                printf("(%c,%d)",tmp,cnt);
            else printf("(%c,%d)",tmp+32,cnt);
        }
        
        }
        if(L==0){
            if(tmp>='a'&tmp<='z')
                printf("(%c,1)",tmp);
            else printf("(%c,1)",tmp+32);
        }
    return 0;
}
复制代码
 

C岛屿面积。思路1：题目的限制条件多，因此比较简单。没必要存储图，输入的时候记录每行的st和ed即可.但是讨论比较麻烦。

思路2：1与旁边的1相邻时，本来的周长是4要减去一部分。逐个计算每个1所能贡献的周长。

复制代码
#include<cstdio>

int map[105][105];

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&map[i][j]);
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]==1)
                    cnt+=4-(map[i-1][j]+map[i+1][j]+map[i][j-1]+map[i][j+1]);
            }
        }
        printf("%d\n",cnt);
    
    }
    return 0;
}
复制代码
 

G  此题和poj4078 输入不一样。

复制代码
#include<cstdio>
#include<queue>
using namespace std;
int main(){
    
    int t;
    while(scanf("%d",&t)!=EOF){
    
        priority_queue<int,vector<int>, greater<int> > Q;
        while(t--){
        
        int x;
        scanf("%d",&x);
        if(x==1){
            int num;
            scanf("%d",&num);
            Q.push(num);
        }
        else{
            int tmp;
            tmp=Q.top();
            printf("%d\n",tmp);
            Q.pop();
        }
    }
    }
    
    
    return 0;
}
