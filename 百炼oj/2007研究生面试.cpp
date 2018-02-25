A.

复制代码
#include<cstdio>
#include<algorithm>
using namespace std;
struct Mouse{
        int num;
        char color[15];
        bool operator < (const Mouse &A) const{
            return num>A.num;
        } 
}mouse[105];//须写在main函数之外
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d %s",&mouse[i].num,mouse[i].color);
        }
        sort(mouse,mouse+n);
        for(int i=0;i<n;i++){
            printf("%s\n",mouse[i].color);
        }
    }
    return 0;    
}
复制代码
 B.

复制代码
#include<cstdio>
#include<string>
#include<cstring>
using namespace std; /***/
char strb[105];
string s,a,b;
int main(){
    
    while(gets(strb)!=NULL){
    s=strb;
    //printf("%s\n",s.c_str());
    scanf("%s",strb);
    a=strb;
    //printf("%s\n",a.c_str());
    scanf("%s",strb);
    b=strb;
    //printf("%s\n",b.c_str());
    int pos=s.find(a,0);
    while(pos!=string::npos){
        s.insert(pos,b);
        s.erase(pos+b.size(),a.size());
        pos=s.find(a,pos);
    }
    printf("%s",s.c_str());
	memset(strb,0,sizeof(strb));
	getchar();
	}
    return 0;
}
复制代码
不加getchar(),第二组数据会出问题.
超时了.

参考这个

复制代码
#include <bits/stdc++.h>
using namespace std;
string s[1000];
int top;
int main(){
while(cin>>s[++top]);
for(int i=1;i<top-2;i++){
if(s[i]==s[top-2])s[i]=s[top-1];
cout<<s[i]<<" ";
}
}
复制代码
 

 

复制代码
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string str[1001];
int main(){
    int idx=0;
    while(cin>>str[idx++]);
    idx--;
    for(int i=0;i<=idx-3;i++){ //好像最后会多读一次。改成idx-3
        if(str[i]==str[idx-2])
            str[i]=str[idx-1];
    }
    for(int i=0;i<=idx-3;i++){
        if(i!=0) cout<<" "<<str[i];
        else cout<<str[i];
    }
}
复制代码
 

 

stl string常用函数
reverse ( s.begin(), s.end () );  反向排序函数，即字符串反转函数

REFERENCE:http://www.cnblogs.com/wangkangluo1/archive/2011/07/22/2114118.html

http://blog.csdn.net/y990041769/article/details/8763366

 C.

以某元素结尾的子序列。

最长不递增子序列。

复制代码
#include<cstdio>
int num[30];
int dp[30];
int max(int a,int b){return a>b?a:b;}
int main(){
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&num[i]);
    }
    int ans=-1;
    for(int i=0;i<k;i++) dp[i]=1;
    for(int i=1;i<=k;i++){
        for(int j=1;j<i;j++){
            if(num[j]>=num[i]&&(dp[j]+1>dp[i]))
                dp[i]=dp[j]+1;
        }
        ans=max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}
复制代码
外循环正向更新；内循环正向更新；dp[j]，表示以第j个元素结尾的子序列的个数，因此内循环意义在于考虑是否要将num[i]加在该序列后面。内循环结束更新最大值。

 
