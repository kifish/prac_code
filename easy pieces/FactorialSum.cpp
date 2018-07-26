
int FactorialSum(List L)
{    int sum = 0;
    int i,n;
    while(L){
         n = L->Data;
         i =n-1;
        for(;i>0;i--) n*=i;
        sum+=n;
        L = L->Next;
    }
    return sum;
}
//这里没有考虑到 0！=1 的情况。

int FactorialSum(List L)
{    int sum = 0;
    int i,n;
    while(L){
          n=1;
        for(i=1;i<=L->Data;i++) n*=i;
        sum+=n;
        L = L->Next;
    }
    return sum;
}
