#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
using namespace std; 
string a;
vector <string> k;
int main(){
    int i=0;
    std::ios::sync_with_stdio(false);  
    while(cin>>a){
        k.push_back(a);
    }
    for(int i=0;i<k.size();i++){
        for(int j=k[i].size()-1;j>=0;j--){
            cout<<k[i][j];
            if(j==0&&(i!=k.size()-1)) cout<<" ";
            //if(j==0&&i==k.size()-1) cout<<'\n';
        }
    }
    
    
    return 0;
}

/*
无限PE；

 此题坑点在于，单词之间可能有多个空格。cin遇到空格 回车tab都会结束。也就是说不会读入空格。此代码可以读入字母数字，但不会读入空格。

size（）算空格了。注意区间写法。

http://blog.csdn.net/yechaodechuntian/article/details/17060125

 

 

结尾需要特判。不能用else if。 比如最后结尾是字母不是空格或者换行符之类的。那么reverse范围与前面不一样了。
if(('a'<=a[i]&&a[i]<='z')||('A'<=a[i]&&a[i]<='Z')){
               cnt++;
}

改成这样WA。 可能还有符号。

最终AC。

/*
C笔记之NULL和字符串结束符'\0'和EOF
reverse（a，b）  为闭开区间，b不是长度。
http://blog.csdn.net/yechaodechuntian/article/details/17060125

官方文档：https://msdn.microsoft.com/zh-cn/library/93wa19x9(v=vs.110).aspx

*/
#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std; 
string a;
int main(){
    std::ios::sync_with_stdio(false);  
       getline(cin,a);
       for(int i=0,cnt=0;i<=a.size()-1;i++){
       if(a[i]!=' '){
               cnt++;
       }
       else if(a[i]==' '&&cnt>0){
               reverse(a.begin()+i-cnt,a.begin()+i);    
               cnt=0;
       }
          if(i==(a.size()-1)){
               reverse(a.begin()+i-(cnt-1),a.begin()+i+1);
               cnt=0;
       }
    }
    cout<<a;
    return 0;
}




