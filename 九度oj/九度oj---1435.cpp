贪心，每次选择浓度最低的。

注意浮点数比较的问题。

AC如下：

复制代码
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int buf[105];
int main(){
    int c;
    int n,v,w;
    while(scanf("%d",&c)!=EOF){
        while(c--){
            scanf("%d %d %d",&n,&v,&w);
            for(int i=0;i<n;i++) scanf("%d",&buf[i]);
            sort(buf,buf+n);
            int sum=0;
            double P=0;
            int idx=0;
            while((((sum*P+1.0*v*buf[idx]/100)/(sum+v))*100-w)<1e-8&&idx<n){
                sum+=v;
                P=((sum-v)*P+1.0*v*buf[idx]/100)/sum;
                idx++;
            }
            if(sum==0){
                printf("0 0.00\n");
            }
            else printf("%d %.2f\n",sum,P);
        }
    }
    return 0;

}
复制代码
 

(((sum*P+1.0*v*buf[idx]/100)/(sum+v))*100)<w-1e-8
上面这行代码会导致WA，因为相当于<

 

(((sum*P+1.0*v*buf[idx]/100)/(sum+v))*100-w)<1e-8
改成这样，AC. 因为相当于<=

