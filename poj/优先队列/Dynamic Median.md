TLE
```c
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

priority_queue<int,vector<int>,greater<int> > s1; //小顶堆
priority_queue<int,vector<int>,less<int> > s2; //大顶堆，等价于priority_queue<int> s2

//想象s1，s2竖着放，且将s1翻转后放在s2上面，则由低到高，<=  然后 >=

void delete_m(){
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 > n2)
        s1.pop();
    else if(n1 < n2)
        s2.pop();
    else
        s2.pop();
}

//s1,s2 元素个数的差值的绝对值始终小于等于1
void insert_num(int num){
    int n1 = s1.size();
    int n2 = s2.size();
//    cout<<n1<<" "<<n2<<" "<<num<<endl;
    if(n1 + n2 == 0){
        s2.push(num);
        return;
    }//无top
    if(n2 == 0){
        if(num > s1.top()){
            int tmp = s1.top();
            s2.push(tmp);
            s1.pop();
            s1.push(num);
        }
        else
            s2.push(num);
        return;
    }
    if(n1 == 0){
        if(num < s2.top()){
            int tmp = s2.top();
            s1.push(tmp);
            s2.pop();
            s2.push(num);
        }
        else
            s1.push(num);
        return;
    }
    int min_s1 = s1.top();
    int max_s2 = s2.top();
    //皆>=1
    //先要确定插入于s1，还是s2；再考虑维持s1，s2元素差值的绝对值小于等于1
    if(num > min_s1){
        if(n1 == n2){
            s1.push(num);
        }
        else if(n1 > n2){
            s2.push(min_s1);
            s1.pop();
            s1.push(num);
        }
        else{
            s1.push(num);
        }
    }else{
        if(n1 == n2){
            s2.push(num);
        }
        else if(n1 > n2){
            s2.push(num);
        }
        else{
            if(num >= max_s2)
                s1.push(num);
            else{
                s1.push(max_s2);
                s2.pop();
                s2.push(num);
            }
        }
    }
//    cout<<"inserted"<<endl;
}
void query(){
    int res;
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 > n2)
        res = s1.top();
    else if(n1 < n2)
        res = s2.top();
    else
        res = s2.top();
    cout<<res<<endl;
}
int main(){
    int t;
    int n;
//    string command;
//    cin>>t;
    scanf("%d",&t);
//cin 会超时
//注意如果用clion调试，直接把样例全部复制输入，可能会出问题，但是一行一行输入就不会
//vs2017 不会出现该情况。
    char command;
    int num;
    while(t--){
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
//        cin>>n;
        scanf("%d",&n);
        getchar();
        while(n--){
            //cin>>command;
            command = getchar();
//            cout<<command<<endl;
            if(command == 'I'){
                scanf("%d",&num);
                insert_num(num);
            }
            else if(command == 'Q')
                query();
            else if(command == 'D')
                delete_m();
            getchar();
        }
    }
    return 0;
}


```

TLE
```C
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

priority_queue<int,vector<int>,greater<int> > s1; //小顶堆
priority_queue<int,vector<int>,less<int> > s2; //大顶堆，等价于priority_queue<int> s2

//想象s1，s2竖着放，且将s1翻转后放在s2上面，则由低到高，<=  然后 >=

void delete_m(){
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 > n2)
        s1.pop();
    else if(n1 < n2)
        s2.pop();
    else
        s2.pop();
}

//s1,s2 元素个数的差值的绝对值始终小于等于1
void insert_num(int num){
    int n1 = s1.size();
    int n2 = s2.size();
//    cout<<n1<<" "<<n2<<" "<<num<<endl;
    if(n1 + n2 == 0){
        s2.push(num);
        return;
    }//无top
    if(n2 == 0){
        if(num > s1.top()){
            int tmp = s1.top();
            s2.push(tmp);
            s1.pop();
            s1.push(num);
        }
        else
            s2.push(num);
        return;
    }
    if(n1 == 0){
        if(num < s2.top()){
            int tmp = s2.top();
            s1.push(tmp);
            s2.pop();
            s2.push(num);
        }
        else
            s1.push(num);
        return;
    }
    int min_s1 = s1.top();
    int max_s2 = s2.top();
    //皆>=1
    //先要确定插入于s1，还是s2；再考虑维持s1，s2元素差值的绝对值小于等于1
    if(num > min_s1){
        if(n1 == n2){
            s1.push(num);
        }
        else if(n1 > n2){
            s2.push(min_s1);
            s1.pop();
            s1.push(num);
        }
        else{
            s1.push(num);
        }
    }else{
        if(n1 == n2){
            s2.push(num);
        }
        else if(n1 > n2){
            s2.push(num);
        }
        else{
            if(num >= max_s2)
                s1.push(num);
            else{
                s1.push(max_s2);
                s2.pop();
                s2.push(num);
            }
        }
    }
//    cout<<"inserted"<<endl;
}
void query(){
    int res;
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 > n2)
        res = s1.top();
    else if(n1 < n2)
        res = s2.top();
    else
        res = s2.top();
    cout<<res<<endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //加了这两行还是TLE
    int t;
    int n;
    string command;
    cin>>t;
    int num;
    while(t--){
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
        cin>>n;
        while(n--){
            cin>>command;
            if(command == "I"){
                cin>>num;
                insert_num(num);
            }
            else if(command == "Q")
                query();
            else if(command == "D")
                delete_m();
        }
    }
    return 0;
}


```


TLE
```C
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

priority_queue<int,vector<int>,greater<int> > s1; //小顶堆
priority_queue<int,vector<int>,less<int> > s2; //大顶堆，等价于priority_queue<int> s2

//想象s1，s2竖着放，且将s1翻转后放在s2上面，则由低到高，<=  然后 >=

void delete_m(){
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 > n2)
        s1.pop();
    else if(n1 < n2)
        s2.pop();
    else
        s2.pop();
}

//s1,s2 元素个数的差值的绝对值始终小于等于1
void insert_num(int num){
    int n1 = s1.size();
    int n2 = s2.size();
//    cout<<n1<<" "<<n2<<" "<<num<<endl;
    if(n1 + n2 == 0){
        s2.push(num);
        return;
    }//无top
    if(n2 == 0){
        if(num > s1.top()){
            int tmp = s1.top();
            s2.push(tmp);
            s1.pop();
            s1.push(num);
        }
        else
            s2.push(num);
        return;
    }
    if(n1 == 0){
        if(num < s2.top()){
            int tmp = s2.top();
            s1.push(tmp);
            s2.pop();
            s2.push(num);
        }
        else
            s1.push(num);
        return;
    }
    int min_s1 = s1.top();
    int max_s2 = s2.top();
    //皆>=1
    //先要确定插入于s1，还是s2；再考虑维持s1，s2元素差值的绝对值小于等于1
    if(num > min_s1){
        if(n1 == n2){
            s1.push(num);
        }
        else if(n1 > n2){
            s2.push(min_s1);
            s1.pop();
            s1.push(num);
        }
        else{
            s1.push(num);
        }
    }else{
        if(n1 == n2){
            s2.push(num);
        }
        else if(n1 > n2){
            s2.push(num);
        }
        else{
            if(num >= max_s2)
                s1.push(num);
            else{
                s1.push(max_s2);
                s2.pop();
                s2.push(num);
            }
        }
    }
//    cout<<"inserted"<<endl;
}
void query(){
    int res;
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 > n2)
        res = s1.top();
    else if(n1 < n2)
        res = s2.top();
    else
        res = s2.top();
    cout<<res<<endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //加了这两行还是TLE
    int t;
    int n;
    char command;
    cin>>t;
    int num;
    cin.get();
    while(t--){
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
        cin>>n;
        while(n--){
            command = cin.get();
            if(command == 'I'){
                cin>>num;
                insert_num(num);
            }
            else if(command == 'Q')
                query();
            else if(command == 'D')
                delete_m();
            cin.get();
        }
    }
    return 0;
}
```
cin,cout 就是比stdio慢！



把cout也改了就AC了。

```C
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

priority_queue<int,vector<int>,greater<int> > s1; //小顶堆
priority_queue<int,vector<int>,less<int> > s2; //大顶堆，等价于priority_queue<int> s2

//想象s1，s2竖着放，且将s1翻转后放在s2上面，则由低到高，<=  然后 >=

void delete_m(){
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 > n2)
        s1.pop();
    else if(n1 < n2)
        s2.pop();
    else
        s2.pop();
}

//s1,s2 元素个数的差值的绝对值始终小于等于1
void insert_num(int num){
    int n1 = s1.size();
    int n2 = s2.size();
//    cout<<n1<<" "<<n2<<" "<<num<<endl;
    if(n1 + n2 == 0){
        s2.push(num);
        return;
    }//无top
    if(n2 == 0){
        if(num > s1.top()){
            int tmp = s1.top();
            s2.push(tmp);
            s1.pop();
            s1.push(num);
        }
        else
            s2.push(num);
        return;
    }
    if(n1 == 0){
        if(num < s2.top()){
            int tmp = s2.top();
            s1.push(tmp);
            s2.pop();
            s2.push(num);
        }
        else
            s1.push(num);
        return;
    }
    int min_s1 = s1.top();
    int max_s2 = s2.top();
    //皆>=1
    //先要确定插入于s1，还是s2；再考虑维持s1，s2元素差值的绝对值小于等于1
    if(num > min_s1){
        if(n1 == n2){
            s1.push(num);
        }
        else if(n1 > n2){
            s2.push(min_s1);
            s1.pop();
            s1.push(num);
        }
        else{
            s1.push(num);
        }
    }else{
        if(n1 == n2){
            s2.push(num);
        }
        else if(n1 > n2){
            s2.push(num);
        }
        else{
            if(num >= max_s2)
                s1.push(num);
            else{
                s1.push(max_s2);
                s2.pop();
                s2.push(num);
            }
        }
    }
//    cout<<"inserted"<<endl;
}
void query(){
    int res;
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 > n2)
        res = s1.top();
    else if(n1 < n2)
        res = s2.top();
    else
        res = s2.top();
//    cout<<res<<endl;
    printf("%d\n",res);
}
int main(){
    int t;
    int n;
//    string command;
//    cin>>t;
    scanf("%d",&t);
//cin 会超时
//注意如果用clion调试，直接把样例全部复制输入，可能会出问题，但是一行一行输入就不会
//vs2017 不会出现该情况。
    char command;
    int num;
    while(t--){
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
//        cin>>n;
        scanf("%d",&n);
        getchar();
        while(n--){
            //cin>>command;
            command = getchar();
//            cout<<command<<endl;
            if(command == 'I'){
                scanf("%d",&num);
                insert_num(num);
            }
            else if(command == 'Q')
                query();
            else if(command == 'D')
                delete_m();
            getchar();
        }
    }
    return 0;
}


```