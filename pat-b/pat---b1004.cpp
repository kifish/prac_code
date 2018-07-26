#include<cstdio>
#include<algorithm>
using namespace std;
struct student{
    char name[11];
    char id[20];
    int grade;
}stu[1000];
bool cmp(student a,student b){
    return a.grade>b.grade;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i =0;i<n;i++){
            scanf("%s %s %d",stu[i].name,stu[i].id,&stu[i].grade);
        }
        sort(stu,stu+n,cmp);
        printf("%s %s\n",stu[0].name,stu[0].id);
        printf("%s %s",stu[n-1].name,stu[n-1].id);
    }
    return 0;
}
