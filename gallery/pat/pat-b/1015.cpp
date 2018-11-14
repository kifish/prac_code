// 模拟题，加个优先级排序即可。

#include<cstdio>
#include<algorithm>
using namespace std;
struct Student{
    int d;
    int c;
    int id;
    int sum;
    int priority;
    bool operator < (const Student &a)const{
        if(priority!=a.priority){
            return priority>a.priority;
        }
        else {
            if(sum!=a.sum) return sum>a.sum;
            else if(d!=a.d) return d>a.d;
            else  return id<a.id;
        }
    }
}student[100005];
int main(){
    int N,L,H;
    int cnt=0;
    scanf("%d %d %d",&N,&L,&H);
    for(int i=0;i<N;i++){
        scanf("%d %d %d",&student[i].id,&student[i].d,&student[i].c);
        student[i].sum=student[i].c+student[i].d;
        if(student[i].d>=L&&student[i].c>=L){
            cnt++;
            if(student[i].d>=H&&student[i].c>=H){
                student[i].priority=3;
                continue;
                    
            }
            if(student[i].d>=H&&student[i].c<H){
                student[i].priority=2;
                continue;
                    
            }
            if(student[i].c<H&&student[i].d<H&&student[i].d>=student[i].c){
                student[i].priority=1;
                continue;
                    
            }
            student[i].priority=0;
            
        }
        else student[i].priority=-1;
    }
    sort(student,student+N);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%d %d %d\n",student[i].id,student[i].d,student[i].c);
    }
    return 0;
}
