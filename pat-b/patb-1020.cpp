/*
两种情况：把月饼全部买完（库存刚好满足需求i=n，或库存小于需求i=n）；买了部分月饼i<=n-1。
错误原因：没有注意到价格和数量可以是小数。
原题如下：每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。


*/

#include<cstdio>
#include<algorithm>
using namespace std;
struct Mcake{
    double price;
    double vol;
    bool operator < (const Mcake &A) const{
    if((price/vol)==(A.price/A.vol)) return vol>A.vol;
    else return price/vol>A.price/A.vol;
    }
}mcake[1005];
int main(){
    int n,th;
    scanf("%d %d",&n,&th);
    for(int i=0;i<n;i++) scanf("%lf",&mcake[i].vol);
    for(int i=0;i<n;i++) scanf("%lf",&mcake[i].price);
    sort(mcake,mcake+n);
    int cnt=0;
    double res=0;
    int i=0;
    while((cnt+mcake[i].vol)<=th&&i<n){
        cnt+=mcake[i].vol;
        res+=mcake[i].price;
        i++;
    }
    if(i<=n-1&&cnt<th)    res+=(1.0*(th-cnt))/mcake[i].vol*mcake[i].price;
    printf("%.2f",res);
    return 0;
}
