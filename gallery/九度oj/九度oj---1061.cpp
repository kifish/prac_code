#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Student{
    char name[105];
    int grade;
    int age;
}student[1005];

bool cmp(Student a,Student b){
    if(a.grade==b.grade){
        if(strcmp(a.name,b.name)==0)
            return a.age<b.age;
        else return strcmp(a.name,b.name)<0;
    }
    else return a.grade<b.grade;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s %d %d",student[i].name,&student[i].age,&student[i].grade);
        }
        sort(student,student+n,cmp);
        for(int i=0;i<n;i++)
            printf("%s %d %d\n",student[i].name,student[i].age,student[i].grade);        
    }    
    return 0;
}
