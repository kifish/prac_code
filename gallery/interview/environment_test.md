

mac os clion:

```c++
#include <bits/stdc++.h>
using namespace std;

void pretty_print(vector<int> & v){
    for(auto val : v){
        cout<<val<<endl;
    }
}

int main(){
    vector<int> v = {1,2,3}; // 该环境下这种写法是可以的
    cout<<"hello world"<<endl;
    pretty_print(v);
    return 0;
}

```


```
~/CLionProjects/prac/cmake-build-debug/prac
hello world
1
2
3

Process finished with exit code 0
```


mac os vscode g++

```
#include<bits/stdc++.h>
using namespace std;

void pretty_print(vector<int> & v){
    for(auto val : v){
        cout<<val<<endl;
    }
}

int main(){
    int a = 1;
    cout<<a<<endl;
    cout<<"hello world"<<endl;
    // vector<int> v = {1,2,3}; // 该环境下这种写法不行
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    pretty_print(v);
    return 0;
}
```

```
g++ --version

Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 10.0.0 (clang-1000.10.38)
Target: x86_64-apple-darwin18.0.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

这环境会对auto 的用法报warning

```


```
1
hello world
1
2
3
```






g++

```c++
#include<bits/stdc++.h>
using namespace std;

/*
g++ --version

Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 10.0.0 (clang-1000.10.38)
Target: x86_64-apple-darwin18.0.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

这环境会对auto 的用法报warning

*/
void pretty_print(vector<int> & v){
    for(auto val : v){
        cout<<val<<endl;
    }
}

int main(){
    int a = 1;
    cout<<a<<endl;
    cout<<"hello world"<<endl;
    // vector<int> v = {1,2,3}; // 该环境下这种写法不行
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    pretty_print(v);
    return 0;
}
```

