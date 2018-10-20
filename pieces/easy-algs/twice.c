//本题要求实现一个函数，判断任一给定整数N是否满足条件：它是完全平方数，又至少有两位数字相同，如144、676等。#include <stdio.h>
#include <stdlib.h> // struct
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
                
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int Istwice(List L,int x){
    while(L){
        if(L->Data == x) return 1;
        L=L->Next;
    }
    return 0;
}
int IsTheNumber(const int N){
    if(sqrt(N)==(int)sqrt(N)){
        int n = N; 
        List L=NULL,p;
        while(n){
            p = (List) malloc(sizeof(struct Node));
            p->Data = n%10; 
            if(Istwice(L,p->Data)) return 1;
            p ->Next = L; L = p;
            n/=10;
        }
        return 0;    
    }
    return 0;
} 
