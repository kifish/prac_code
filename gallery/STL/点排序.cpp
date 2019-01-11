#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point{
    int x,y;
    double d;
    double caldis(Point a){
        return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));
    }
    bool operator < (const Point &a) const{
        if(d!=a.d)
            return d<a.d;
        else if(x!=a.x)
            return x<a.x;
        else return y<a.y;
    }
}point[105];

int main(){
    Point ori;
    scanf("%d %d",&ori.x,&ori.y);
    int n;
    scanf("%d",&n);
    int idx=0;
    int t=n;
    while(t--){
        scanf("%d %d",&point[idx].x,&point[idx].y);
        point[idx].d=point[idx].caldis(ori);
        idx++;
    }
    sort(point,point+n);
    for(int i=0;i<n;i++){
        if(i!=0)
            printf(", ");
        printf("(%d,%d)",point[i].x,point[i].y);
    }
    printf("\n");
    return 0;
}
