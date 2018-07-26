#include<iostream>
#include<cctype>
#include<cstdio> 
#include<string>
#include<cstring>
using namespace std;
int main(){
    char str[105];
    gets(str);
    string s=str;
    char str1[105];
    for(int i=0;i<s.size();i++)
        s[i]=tolower(s[i]);
    while(gets(str1)){
        string a,b;
        a=str1;
        b=str1;
        for(int i=0;i<a.size();i++)
            a[i]=tolower(a[i]);
        
        
        int t=a.find(s,0);
        while(t!=string::npos){
            a.erase(t,s.size());
            b.erase(t,s.size());
            t=a.find(s,t);
        }
        t=b.find(' ',0);
        while(t!=string::npos){
            b.erase(t,1);
            t=b.find(' ',0);//'' not " "
        }
        printf("%s\n",b.c_str());
        
    }

    return 0;
    
}
