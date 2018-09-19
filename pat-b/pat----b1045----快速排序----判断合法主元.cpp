// 1.仿照快排思路。注意判断合法是left>right. left-1 小于等于主元，right+1都大于等于主元。 若left=right，则说明a[left]不合法，舍去这种情况。

// 这种方法会超时。

// 复制代码
#include<cstdio>
#include<set>
using namespace std;
set<int> res;
int cnt;
int a[100005];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        cnt=0;
        res.clear();
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++){
            int left=0;
            int right=n-1;
            int times=n;
            while(times--){
            while(left<=i&&a[left]<=a[i]) left++;
            while(right>=i&&a[right]>=a[i]) right--;
            }
            if(left>right){
                cnt++;
                res.insert(a[i]);
            }
        }
        printf("%d\n",cnt);
        for(set<int>::iterator it=res.begin();it!=res.end();it++){
            if(it==res.begin()) printf("%d",*it);
            else printf(" %d",*it);
        }
        printf("\n");
    }
    return 0;
}
// 复制代码
//  2.类似DP.maxleft[i]存的是a[0]到a[i]的最大值，minright[i]存的是a[i]到a[n-1]的最小值。注意初始化以及循环初始值，数组下标须在合法范围。

// 最后遍历元素，判断两边maxleft[i-1],minright[i+1]即可。set自动递增排序。AC.

// 复制代码
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
set<int> res;
int maxleft[100005];
int minright[100005];
int a[100005];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        
        res.clear();
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        maxleft[0]=a[0];
        minright[n-1]=a[n-1];
        for(int i=1,j=n-2;i<n,j>=0;i++,j--){
            maxleft[i]=max(a[i],maxleft[i-1]);
            minright[j]=min(a[j],minright[j+1]);    
        }
        if(minright[1]>a[0]) res.insert(a[0]);
        if(maxleft[n-2]<a[n-1]) res.insert(a[n-1]);
        for(int i=1;i<n-1;i++){
            if(a[i]>maxleft[i-1]&&a[i]<minright[i+1])
                res.insert(a[i]);
        }
        printf("%d\n",res.size());
        for(set<int>::iterator it=res.begin();it!=res.end();it++){
            if(it==res.begin()) printf("%d",*it);
            else printf(" %d",*it);
        }
        printf("\n");
    }
    return 0;
}
