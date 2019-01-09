http://algorithm.openjudge.cn/algorithmb/C/

贪心可解。

用的是O（N^2）的方法，287ms，时限1s。应该有更快的方法。

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

const int N = 10005;
const int INF = 0x3fffffff;
int c[N];
int need[N];
int reserve_cost;

//
//struct Price{
//    int produce_day;
//    int deliver_day;
//    int per_cost;
//};


int main(){
    int n;
    cin>>n>>reserve_cost;
    for(int i = 1;i<=n;i++){
        cin>>c[i]>>need[i];
    }
    long long total_cost = 0;
//    int total = 0;//认为库存永远都是空的，在1-i天之间都可以自由平行移动，只要把存储价格算上去就行。
    for(int day = 1;day <= n;day++){
        int min_cost = INF;
        int the_day_cost;
        int select_day;
        for(int j = 1;j <= day;j++){
            the_day_cost = c[j] + (day - j) * reserve_cost;
            if(the_day_cost < min_cost){
                min_cost = the_day_cost;
                select_day = j;
            }
        }
        //cout<<"select "<<select_day<<"at "<<day<<endl;
        total_cost += min_cost * need[day];
    }
    cout<<total_cost<<endl;
    return 0;
}
```




https://www.cnblogs.com/nowandforever/p/4416213.html

优化到O（N）
p[i]存的是第i天的最小花费（per）。并且通过递推保证正确性。


