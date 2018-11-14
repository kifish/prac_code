
/*

struct bigInteger{
    int digit[maxDigits];
    int size;
}
这里digit每一位的权重都乘以10000；
如果不是特别大的数，没必要；乘以10000后，把字符串转化为数字比较麻烦


*/

#include<cstdio>
#include<cstring>

#define maxDigits 100

struct bigInteger{
    int digit[maxDigits];
    int size;
    void init(){
        for(int i=0;i<maxDigits;i++) digit[i]=0;
        size = 0;
    }
    void set(int x){
        init();
        do{
            digit[size++]=x%10000;
            x/=10000;
        }while(x!=0);
    }
    void output(){
        for(int i=size-1;i>=0;i--){
            if(i!=size-1) printf("04d",digit[i]);
            else printf("%d",digit[i]);
        }
    }
    bigInteger operator * (int x) const{
        bigInteger ret;
        ret.init();
        int carry=0;
        for(int i=0;i<size;i++){
            int tmp=x*digit[i]+carry;
            carry=tmp/10000;
            ret.digit[ret.size++]=tmp%10000;
        }
        if(carry!=0)
            ret.digit[size++]=carry;
        return ret;
    }
    bigInteger operator + (const big Integer &A) const{
        bigInteger ret;
        ret.init();
        int carry=0;
        for(int i=0;i<A.size||i<size;i++){
            int tmp=digit[i]+A.digit[i]+carry;
            carry=tmp/10000;
            ret.digit[ret.size++]=tmp%10000; 
        }
        if(carry!=0)
            ret.digit[ret.size++]=carry;
        return ret;
    }
    bigInteger operator / (int x) const{
        bigInteger ret;
        ret.init();
        int r=0; //r<-->remainder
        for(int i=size-1;i>=0;i--){
            int t=(r*10000+digit[i])/x;
            r=(r*10000+digit[i])%x;
            ret.digit[i]=t;
        }
        ret.size=0;
        for(int i=0;i<maxDigits;i++){
            if(ret.digit[i]!=0)
                ret.size=i;
        }
        ret.size++;
        return ret;
    }
}
