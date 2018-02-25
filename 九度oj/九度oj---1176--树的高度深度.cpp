
/*
都从1开始计数。
高度从下往上数。
深度从上往下数。
对于整棵树来说，最深的叶结点的深度就是树的深度；树根的高度就是树的高度。这样树的高度和深度是相等的。
对于树中相同深度的每个结点来说，它们的高度不一定相同，这取决于每个结点下面的叶结点的深度。

节点内容不一定是1，2，...,n

*/

#include<cstdio>
#include<cmath>
int buf[1005];
int main(){
    int n;
    int d;
    while(scanf("%d",&n)!=EOF){
        int cnt=n;
        for(int i=1;i<=n;i++) scanf("%d",&buf[i]);
        scanf("%d",&d);
        int left=pow(2,d-1);
        int right=pow(2,d)-1;
        if(left>n||d<=0) printf("EMPTY\n");
        else{ 
            for(int i=left;i<=right&&i<=n;i++){
                if(i!=left) printf(" ");
                printf("%d",buf[i]);
            }
            printf("\n");
        }
    }
}
