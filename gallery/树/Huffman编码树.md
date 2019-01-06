http://algorithm.openjudge.cn/200601/3/

http://bailian.openjudge.cn/practice/4080/


```c
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>

using namespace std;
priority_queue<int,vector<int>,greater<int> >q;

int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        while (!q.empty()) q.pop();
        int n;
        cin>>n;
        while (n--){
            int num;
            cin>>num;
            q.push(num);
        }
        int sum = 0;
        while(q.size() > 1){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            int combine = a + b;
            sum += combine;
            q.push(combine);
        }
        cout<<sum<<endl;
    }
    return 0;
}

```