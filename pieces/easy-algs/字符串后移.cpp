#include "stdio.h"  
#include <iostream>  
#include <string>  //c++ 
using namespace std;
int main()
{
    string s1 = "rlgqncntndqwqlsdnuybuypkexvz";
    for(int k = 1; k<=26; k++)
    {   
        string temp = s1;
        for(int i = 0;i<temp.length();i++)
            {
                int t = temp[i];
                {
                    if(t>='A'&&t<='Z')
                    {
                        t+=k;
                        if(t>'Z') t-=26;
                    }
                    if(t>='a'&&t<='z')
                    {
                        t+=k;
                        if(t>'z') t-=26;  //char t 有问题 
                    }
                    temp[i]=char(t);
                }
            }           
        cout<<temp<<endl;
    }
    return 0;
} 
