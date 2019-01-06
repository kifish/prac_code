http://poj.org/problem?id=1094


WA
```C
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<char> v;
void init(int n){
    v.clear();
    for(int i = 0;i<n;i++)
        v.push_back(i + 'A');
}
int cal(int n){
    return (n-1)*(n-1)/2;
}

int less_[26][26] = {-1};//-1这种初始化是无效的，只会使第一个数-1，（在本地环境中）其他皆为0.

//这种方法是错的，首先 大小要满足双向，a < b，要顺带修改 b > a的信息；这稍微修改是可以做到的
//其次要满足 大小的传递性 a < b && b < c，-> a < c 这就比较麻烦了。如果处理好了这个，就已经完成了排序任务。鸡生蛋蛋生鸡的问题。因此，需要使用拓扑排序。
int is_less(char a,char b){
    return less_[a-'A'][b - 'A'];
}

bool update_less(char a,char b){
    if(less_[a-'A'][b-'A'] == -1){
        less_[a-'A'][b-'A'] = 1;
        return true;
    }
    else return false;
}

void merge_sort(int lo,int hi){
    if(lo == hi)
        return;
    int mid = (lo + hi) / 2;
    merge_sort(lo,mid);
    merge_sort(mid + 1,hi);
    vector<char> temp;
    int i = lo,j = mid + 1;
    while(i <= mid && j <= hi){
        if(!is_less(v[i],v[j])) temp.push_back(v[j++]);
        else temp.push_back(v[i++]);
    }
    while (i <= mid) temp.push_back(v[i++]);
    while (j <= hi) temp.push_back(v[j++]);
    for(i = lo;i<=hi;i++){
        v[i] = temp[i - lo];
    }
}

int main(){
    int n,m;
    while (scanf("%d %d",&n,&m) == 2 && !(n == 0 || m == 0)){
        memset(less_,-1,sizeof(less_));
        getchar();
        int idx = 0;
//        4 6
//        A<B
//        A<C
//        B<C
//        C<D
//        B<D
//        A<B
//        输入如上，如果用scanf("%c<%c\n",&a,&b);
//        最后一组数据无法读入！
//        还是要用换行符读入getchar
        for (int i = 1;i<=m;i++){
            char a,b;
            scanf("%c<%c",&a,&b);
            getchar();
            if(idx == 0 && !update_less(a,b)){
                idx = i;
            }
        }
        if(idx == 0){
            if(m < cal(n)){
                printf("Sorted sequence cannot be determined.\n");
            }
            else{
                init(n);
                merge_sort(0,n-1);
                string res = "";
                for(int i = 0;i<v.size();i++){
                    res += v[i];
                }
                printf("Sorted sequence determined after %d relations: %s.\n",m,res.c_str());
            }
        }
        else{
            printf("Inconsistency found after %d relations.\n",idx);
        }
    }
}
```

https://blog.csdn.net/DOLFAMINGO/article/details/76906479



AC

```C
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int degree[27],degree_buf[27],edge[27][27],n;
vector<char> res;

int toposort(){
    int state = 3;//3 表示可以确定。
    memcpy(degree_buf,degree, sizeof(degree));
    int times = n;
    if(!res.empty()) res.clear();
    while (times--){
        int the_node,cnt = 0;
        for(int i = 0;i<n;i++){
            if(degree_buf[i] == 0){
                cnt++;
                the_node = i;//若有多个度数为0 的点，只保存一个，这是可以的。
            }
        }

        if(cnt == 0) return 1;//成环，矛盾。
        else if(cnt > 1) state = 2;//最小的不能确定，但之后可能发现环。2表示不能确定的状态
        degree_buf[the_node] = -1;
        res.push_back(the_node + 'A');
        for(int j = 0;j<n;j++){
            if(edge[the_node][j]) degree_buf[j]--;
        }
    }
    return state;
}


int main(){
    int m;
    while (scanf("%d %d",&n,&m) == 2 && !(n == 0 || m == 0)){
        getchar();
        int state = 3,step = 0;//3 表示可以确定
        memset(edge,0, sizeof(edge));
        memset(degree,0, sizeof(degree));
        for (int i = 1;i<=m;i++) {
            char a, b;
            scanf("%c<%c", &a, &b);
            getchar();
            if(step != 0) continue;//第几步发现环，即矛盾
            edge[a - 'A'][b - 'A'] = 1;
            degree[b- 'A']++;
            state = toposort();
            if(state == 1){
                step = i;//已经发现矛盾。
            } else if(state == 3){
                step = i;//已经完全确定。
            }
        }
        if(state == 1){
            printf("Inconsistency found after %d relations.\n",step);
        }
        else if(state == 2){
            printf("Sorted sequence cannot be determined.\n");
        }
        else{
            string s = "";
            for(int i = 0;i<res.size();i++) s += res[i];
            printf("Sorted sequence determined after %d relations: %s.\n",step,s.c_str());
        }
    }
}
```