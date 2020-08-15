#include<bits/stdc++.h>


typedef long long LL;
// or #define LL long long

using namespace std;

/*

要整个结果一起算, 不能拆成函数。


*/

void print_vec(vector<int> & v){
    for(auto val : v){
        cout<<val<<" ";
    }
    cout<<endl;
}

const int mod = 1e9 + 7;

// https://zh.wikipedia.org/wiki/%E4%BA%8C%E9%A1%B9%E5%BC%8F%E5%AE%9A%E7%90%86

// (m)/1 * n^1 + (m*(m-1)) /(1*2) * n^2 + (m*(m-1)*(m-2)) / (1*2*3)* n^3 + ...

//sum C(m,i) * n^i (i=0->m)
// x <- 1; y <- n; n <- m
// -> (1+n)^m


LL cal(int m, int n){
    if(m == 0) return 0;
    // m niu
    // n color
    LL sum = 1;
    LL product = 1;
    LL tmp = 1;
    for(int i = 1;i<=m;i++){ //  (m)/1 * n^1 + (m*(m-1)) /(1*2) * n^2 + (m*(m-1)*(m-2)) / (1*2*3)* n^3 + ...
        product *= n;
        product %= mod;            
        tmp *= (m-i + 1); 
        tmp /= i;
        tmp %= mod;
        sum += tmp * product;  
        sum %= mod;
    }
    return sum;
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
3 2
27



*/




