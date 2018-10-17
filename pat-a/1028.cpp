#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Student{
    char name[10];
    int id;
    int grade;
}student[100005];

bool cmp1(Student a,Student b){
    return a.id<b.id;
}
bool cmp2(Student a,Student b){
    int tmp=strcmp(a.name,b.name);
    if(tmp!=0){
        return tmp<0;
    }
    else return a.id<b.id;
}
bool cmp3(Student a,Student b){
    if(a.grade!=b.grade)
        return a.grade<b.grade;
    else return a.id<b.id;
}

int main(){
    //int cnt=0;
    int n,c;
    while(scanf("%d %d",&n,&c)!=EOF){
        if(n==0) break;
        for(int i=0;i<n;i++){
            scanf("%d %s %d",&student[i].id,student[i].name,&student[i].grade);
        }
        if(c==1) sort(student,student+n,cmp1);
        if(c==2) sort(student,student+n,cmp2);
        if(c==3) sort(student,student+n,cmp3);
        //printf("Case %d:\n",++cnt);
        for(int i=0;i<n;i++){
            printf("%06d %s %d\n",student[i].id,student[i].name,student[i].grade);
        }
    }
    return 0;
}
