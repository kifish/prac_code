
/*

#https://github.com/kifish/prac_code/tree/master/%E4%B9%9D%E5%BA%A6oj

 

本题要求实现一个函数，求N个集合元素A[]的中位数，即序列中第\lfloor N/2 +1\rfloor⌊N/2+1⌋大的元素。其中集合元素的类型为自定义的ElementType。

有几个测试点没通过 

选择排序，出现样例错误和超时。

*/

#include <stdio.h>
#include<memory.h>
#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
void Swap(ElementType *a, ElementType *b)
{
    ElementType t =*a;
    *a = *b;
    *b = t;
}
void Sort(ElementType A[], int N){
    int i, j, max;
    for (i = 0;i<N-1;i++){
    max = i;
        for( j = i+1;j<N;j++){
            if(A[j]>A[max])
                max = j;
        }
        Swap(&A[i],&A[max]);
    }
}
ElementType Median( ElementType A[], int N ){
    /*
        for(int i =0;i<N;i++){
        ElementType amax=A[i];
        int pos=i;
        for(int j=i+1;j<N;j++){
            if(A[j]>amax){
                amax=A[j];
                 pos = j;
            }
        }
        if(i!=pos){
        amax = A[i];
        A[i] = A[pos];
        A[pos] = amax;    
        }
    }
    */
    //ElementType a[MAXN];
    //memcpy(a,A,10*sizeof(ElementType));
    //int n=N;
    Sort(A, N);
    return A[N/2];
}
