```C
//
// Created by k on 2018/9/22.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main(){
    set S;
    set::iterator j;
    string s;
    while(cin>>s) S.insert(s);
    for(j = S.begin();j!= S.end();++j){
        cout<<*j<<endl;
    }
    return 0;
}




```