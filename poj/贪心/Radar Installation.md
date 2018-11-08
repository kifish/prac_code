
贪心的证明：
所有的岛屿都必须覆盖。
因此第一个区间必须是要消耗一个雷达。
第i个区间是否消耗雷达取决于前一个雷达可出现的区域，如果前一个雷达可出现的区域与第i个区间有交集，那么就可以省一个雷达，并且把前一个雷达可出现的区域缩小为其和第i个区间的交集。如果没有交集，那么要使用一个雷达，则到第i+1个区间迭代的时候，前一个雷达可出现的区域即为第i个区间。以此类推。


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

bool isvalid(int y,int d){
    if(y > d)
        return false;
    return true;
}

struct Interval{
    double l;
    double r;
};
Interval cal(int x,int y, double d){
    double left,right;
    double dx = sqrt(d*d-y*y);
    left = x - dx;
    right = x + dx;
    Interval res = {left,right};
    return res;
}

vector<Interval> g;

bool cmp(Interval a,Interval b){
    return a.l < b.l;
}

int main(){
    int n;
    double d;
    int case_idx = 1;
    int x,y;
    Interval pre_intersect;
    while(scanf("%d %lf",&n,&d) == 2 && n+d != 0){
        g.clear();
        int res = 0;
        for(int i = 0;i < n;i++){
            scanf("%d %d",&x,&y);
            if(!isvalid(y,d)) res = -1;
            g.push_back(cal(x,y,d));
        }
        if(res == 0){
            sort(g.begin(),g.end(),cmp);
            res = 1;
            pre_intersect = {g[0].l,g[0].r};
            for(int i = 1;i<g.size();i++){
                if(g[i].l >= pre_intersect.l && g[i].l <= pre_intersect.r ){
                    pre_intersect.l = g[i].l;
                    pre_intersect.r = min(g[i].r,pre_intersect.r);
                }
                else{
                    res++;
                    pre_intersect.l = g[i].l;
                    pre_intersect.r = g[i].r;
                }
            }
        }
        printf("Case %d: %d\n",case_idx,res);
        case_idx++;
    }
    return 0;
}
```