/*
把树和递归联系起来，先判断根结点是否满足调节，再判断左子树根节点和右子树根节点，再判断...

这种做法很好理解，但每次只能计数一层，容易超时。



*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<string>

int cnt=0;
int count(int m,int n){
    if(m<=n)
        cnt++;   //该节点满足条件 
    else return 0;
    count(2*m,n);
    count(2*m+1,n);
    return cnt;
}

int main(){
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF){
        if(m==0&&n==0) break;
        
        cnt=0;
        int res=count(m,n);
        printf("%d\n",res);
    }

    return 0;
}

/*
根据树的性质来数，m为一个子树的根。从m开始的第一层，到倒数第二层，直接累加。然后判断最后一层的左子树与n的关系，若满足条节作差加1，并累加即可。

细节注意以下：如果m，n在同一层的情况。
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<string>
#include<cmath>
int mypow(int n){
    int res=1;
    while(n--){res*=2;}
    return res;
}

int main(){
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF){
        if(m==0&&n==0) break;
        
        int cnt=0;
        int deep_m=1;
        while(mypow(deep_m)-1<m){ //mypow(deep_m)-1 第deep_m层的最大值 
            deep_m++;
        }
        int deep_n=1;
        while(mypow(deep_n)-1<n){
            deep_n++;
        }
        int deepsub=deep_n-deep_m;
                   
        cnt+=mypow(deepsub)-1; //deepsub=1的时候数了两次,不过第一次是0 
        
        if(deepsub>0){
            int last=m*mypow(deepsub);//last_left_child
            if(last<=n){
                cnt+=n-last+1;
            }
        }
        else cnt++;  //只有m这一个结点 
        printf("%d\n",cnt);
    }

    return 0;
}

//再快一点，可以用log
