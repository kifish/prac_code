

```C
//
// Created by k on 2018/9/22.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main(){
    map M;
    map::iterator j;
    string s;
    while(cin>>s) M[s]++;//默认初始化为0 
    for(j = M.begin();j!= M.end();++j){
        cout<<j->first<<" "<<j->second<<endl;
    }
    return 0;
}
```
