
/*
A.

复制代码
#include<cstdio>

const double eps=1e-8;// 写法注意
#define Moreequ(a,b) (((a)-(b))>(-eps))
#define Lessequ(a,b) (((a)-(b))<(eps))
#define Less(a,b)    (((a)-(b))<(-eps))
#define More(a,b)    (((a)-(b))>(eps))
#define Equ(a,b)     ((fabs((a)-(b)))<(eps)) 
int main(){
    double x,y;
    while(scanf("%lf",&x)!=EOF){
        if(Moreequ(x,0)&&Less(x,5)) y=-1*x+2.5;
        else if(Moreequ(x,5)&&Less(x,10)) y=2-1.5*(x-3)*(x-3);
        else if(Moreequ(x,10)&&Less(x,20)) y=x/2-1.5;
        printf("%.3f",y);
    }
    return 0;
}
复制代码
 

B.

复制代码
#include<cstdio>
#include<cstring>
char str[100][20];
int main(){
    int i=0;
    while(scanf("%s",str[i])!=EOF){  //注意不能加& 
        i++;
    }//有问题?最后需换行加+CTRL+Z; AC不了。
    int k;
    for(int j=0;j<=i-1;j++){
         k=strlen(str[j]);
        for(int q=k-1;q>=0;q--){
            printf("%c",str[j][q]);
            if(q==0&&j!=i-1) printf(" ");
        }
    }
    return 0;
}
复制代码
scanf碰到空格或者换行结束.这里其实还是有点问题的.

改：

 

 

复制代码
#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
char str[100][20];
int main(){
    string a;
    vector <string> k;
    int i=0;
    while(cin>>a){
        k.push_back(a);
    }
    for(int i=0;i<k.size();i++)
    cout<<k[i];
    
    return 0;
}
复制代码
 C.

strlen 只能统计字符串的长度，不能统计单个字符，不能统计数字。
复制代码
#include<cstdio>

#include<cstring>
using namespace std;


//char res[205];
char raw[101][21];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        char str[205];
        scanf("%s",str);
        int L=strlen(str);
        int rown;
        if(L%n==0) rown=L/n;
        else rown=L/n+1;
                 
        for(int i=1;i<=rown;i++){
            if(i&1==1){ //left--->right
                for(int j=0;j<n;j++)
                    raw[i-1][j]=str[(i-1)*n+j];
            }
            else{ 
                for(int j=n-1;j>=0;j--)
                    raw[i-1][j]=str[(i-1)*n+(n-j-1)];
            }
            }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int k=0;k<rown;k++){
                str[cnt++]=raw[k][i];
            }
        }
        puts(str);
        
    }
    return 0;
}
复制代码
 

D:文件结构“图”
E.http://bailian.openjudge.cn/xly2016/E/

http://blog.csdn.net/clove_unique/article/details/52921399
http://blog.csdn.net/wjlwangluo/article/details/70748560

F.Dungeon Master
迷宫问题。
 

G:重建二叉树
 H.丛林中的路

后缀++，edgen 数量上是对的，下标要减一。

 I.Dominoes

http://blog.csdn.net/xiaoxiaoluo/article/details/7960874

J.Hrinity

buhui

复制代码
#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
#include <string>  
#include <vector>  
#include <map>  
#include <queue>  
#include <set>  
#define PI 3.1415926535898  
#define INF 1000000000  
#define MAXM 300010  
#define MP(x,y) (make_pair((x),(y)))  
using namespace std;  
struct Node{  
    int cnt,h,len;  
    int next[27],fail;  
    void init()  
    {  
        h=0;  
        cnt = 0;  
        fail = -1;  
        memset(next,-1,sizeof(next));  
    }  
}trie[MAXM];  
char str[5100005],tstr[5100005],sub[2505*1205];  
int cnt,ans,subl,pos[2505],total;  
vector<int> tpos,tcnt;  
short ssub[2505*1205];  
bool vi[2505];  
void insert(char str[],int h)  
{  
    int p=0,x;  
    for(int i=0;str[i];i++)  
    {  
        x=str[i]-'A';  
        if(trie[p].next[x]==-1)  
        {  
            trie[++cnt].init();  
            trie[p].next[x]=cnt;  
        }  
        p=trie[p].next[x];  
    }  
    trie[p].cnt++;  
    trie[p].h=h;  
    trie[p].len=strlen(str);  
    pos[h]=p;  
}  
void build_ac()  
{  
    queue<int> q;  
    int root=0;  
    q.push(0);  
    while(!q.empty())  
    {  
        int p=q.front();  
        int temp=0;  
        q.pop();  
        for(int i=0;i<26;i++)  
        {  
            int child=trie[p].next[i];  
            if(child!=-1)  
            {  
                if(p==root)  
                    trie[child].fail=root;  
                else  
                {  
                    temp=trie[p].fail;  
                    while(temp!=-1)  
                    {  
                        if(trie[temp].next[i]!=-1)  
                        {  
                            trie[child].fail=trie[temp].next[i];  
                            break;  
                        }  
                        temp=trie[temp].fail;  
                    }  
                    if(temp==-1)  
                        trie[child].fail=root;  
                }  
                q.push(child);  
            }  
        }  
    }  
}  
int query(char str[],int ty)  
{  
    int index,len,result,root=0;  
    int p=root;  
    result=0;  
    len=strlen(str);  
    for(int i=0;i<len;i++)  
    {  
        index=str[i]-'A';  
        while(trie[p].next[index]==-1&&p!=root)  
            p=trie[p].fail;  
        p=trie[p].next[index];  
        if(p==-1)  
            p=root;  
        int temp=p;  
        while(temp!=root&&trie[temp].cnt!=-1)  
        {  
            result+=trie[temp].cnt;  
            bool flag=0;  
            if(ty==0)  
            {  
                int tt=i-trie[temp].len+1;  
                if(tt>=0&&ssub[tt]==ssub[i]&&ssub[tt]!=trie[temp].h&&vi[ssub[tt]]==1)  
                {  
                    if(trie[temp].h&&vi[trie[temp].h])  
                        vi[trie[temp].h]=0,--total;  
                }  
                else    flag=1;  
            }  
            tpos.push_back(temp);  
            tcnt.push_back(trie[temp].cnt);  
            if(flag==0)  
                trie[temp].cnt=-1;  
            if(ty==1)  
                vi[trie[temp].h]=1;  
  
            temp=trie[temp].fail;  
        }  
    }  
    return result;  
}  
void change(char tstr[])  
{  
    int j = 0;  
    for(int i = 0;tstr[i];i++)  
    {  
        if(tstr[i]>='A'&&tstr[i]<='Z') str[j++]=tstr[i];  
        else if(tstr[i]=='[')  
        {  
            int num = 0;  
            while(tstr[++i]>='0'&&tstr[i]<='9')  
            {  
                num = num*10+tstr[i]-'0';  
            }  
            char tmp;  
            for(;tstr[i]!=']';i++) tmp = tstr[i];  
            for(int k = 0; k < num;k++)  
                str[j++]=tmp;  
        }  
    }  
    str[j]='\0';  
}  
void add(char s[],int h)  
{  
    for(int i=0;s[i];++i,++subl)  
        sub[subl]=s[i],ssub[subl]=h;  
}  
int main()  
{  
    //freopen("J:\\MyDocument\\Code\\input.txt","r",stdin);  
    int ca,n;  
    scanf("%d",&ca);  
    while(ca--)  
    {  
        subl=0;  
        trie[0].init();  
        scanf("%d",&n);  
        cnt = 0;  
        for(int i = 0; i < n; i++)  
        {  
            scanf("%s",tstr);  
            change(tstr);  
            add(str,i+1);  
            insert(str,i+1);  
        }  
        build_ac();  
        tpos.clear(),tcnt.clear();  
        memset(vi,0,sizeof(vi));  
        scanf("%s",tstr);  
        change(tstr);  
        total=query(str,1);  
        for(int i=0;i<tpos.size();++i)  
            trie[tpos[i]].cnt=tcnt[i];  
        sub[subl]='\0';  
        query(sub,0);  
        printf("%d\n",total);  
    }  
}  
复制代码
http://blog.csdn.net/tri_integral/article/details/8946992
*/
