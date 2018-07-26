#include<cstdio>
#include<algorithm>
using namespace std;
const double eps=1e-8;
bool greater(double x){
    if(x>eps) return 1;
    else return 0;
}
struct Goods{
    double price;
    double size;
    double sp;
}goods[1005];
bool cmp(Goods a,Goods b){
    return a.sp>b.sp;
}
int main(){
    int n,m;
    while(scanf("%d %d",&m,&n)!=EOF){
        if(n==-1&&m==-1) break;
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&goods[i].size,&goods[i].price);
            goods[i].sp=goods[i].size/goods[i].price;
        }
        sort(goods,goods+n,cmp);
        int i=0;
        double res=0;
        double reserve=(double)m;
        while(greater(reserve)&&i<n){           //i<n,考虑全部买完的情况 
            if(reserve>goods[i].price){
                reserve-=goods[i].price;
                res+=goods[i].size;
                i++;
            }
            else{
                res+=goods[i].sp*reserve;
                reserve=0;
                i++;
            }
        }
        printf("%.3f\n",res);
    }
    return 0;

}
