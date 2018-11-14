学号未给出输出格式，所以需用字符串输入输出。

显示WA,可能是字符串数组开小了。

复制代码
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Student{
    char id[100];
    char name[100];
    char gender[20];
    int age;
    bool operator < (const Student &A) const{
        return strcmp(id,A.id)<0;
    }
}student[1005];

void find(char x[],int left,int right){
    if(left>right) {
        printf("No Answer!");
        return;
    }
    int mid=(left+right)/2;
    int tmp=strcmp(x,student[mid].id);
    if(tmp==0){
        printf("%s %s %s %d",student[mid].id,student[mid].name,student[mid].gender,student[mid].age);
    }
    else if(tmp>0)
        return find(x,mid+1,right);
    else if(tmp<0)
        return find(x,left,mid-1);
}

int main(){
    int n,m;
    char x[100];
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%s %s %s %d",student[i].id,student[i].name,student[i].gender,&student[i].age);
        sort(student,student+n);
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%s",x);
            find(x,0,n-1);
            printf("\n");
        }
    }
    return 0;
}
