
两步：划分；递归。

复制代码
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int A[105];
int part(int A[],int left,int right){
    int temp=A[left];
    while(left<right){
        while(left<right&&A[right]>temp) right--;
        A[left]=A[right];
        while(left<right&&A[left]<=temp) left++;
        A[right]=A[left];
    }
    A[left]=temp;
    return left;
}

void quick_sort(int A[],int left,int right){
    if(left<right){
        int pos=part(A,left,right);
        quick_sort(A,left,pos-1);
        quick_sort(A,pos+1,right);
    }
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&A[i]);
        quick_sort(A,0,n-1);
        for(int i=0;i<n;i++) printf("%d ",A[i]);
        printf("\n");
    }
    return 0;
}
复制代码
 

选择排序

复制代码
#include<cstdio>
int num[105];
void select_sort(int n){
    for(int i=0;i<n;i++){
        int minidx=i;
        int min=num[i];
        for(int j=i;j<n;j++){
            if(min>num[j]){
                min=num[j];
                minidx=j;
            }
        }
        num[minidx]=num[i];
        num[i]=min;
    }
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&num[i]);
        select_sort(n);
        for(int i=0;i<n;i++){
            printf("%d ",num[i]);
            if(i==n-1) printf("\n");
        }
        
    }
    return 0;
}
复制代码
 
