#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
// or #define LL long long

const int MOD = 1e9 + 7;

// https://zh.wikipedia.org/wiki/%E4%BA%8C%E9%A1%B9%E5%BC%8F%E5%AE%9A%E7%90%86

// 1 + (n)/1 * m^1 + (n*(n-1)) /(1*2) * m^2 + (n*(n-1)*(n-2)) / (1*2*3)* m^3 + ...

//sum C(n,i) * m^i (i=0->n)
// x <- 1; y <- m; n <- n
// -> (1+m)^n

LL pow(int base, int pow_val){
    if(pow_val == 1) return base;

    if(pow_val % 2 == 1){
        LL tmp = pow(base, pow_val / 2) % MOD;
        return  (tmp * tmp * base) % MOD;
    }
    else{
        LL tmp = pow(base, pow_val / 2) % MOD;
        return (tmp * tmp) % MOD;
    }
}

LL cal(int n, int m){
    return pow(m+1, n);
}

int main() {
	std::ios::sync_with_stdio(false);
    int n; // niu
    int m; // color
    while (cin>>n>>m)
    {   
        LL ret = cal(n,m);
        cout<<ret<<endl;
    }

	return 0;
}




/*
n m

3 2
27



*/




