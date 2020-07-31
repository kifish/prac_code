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



// vector<int> fac_cache = {-1};

int fac(int n){
    if(n == 1){
        return 1;
    }
    int tmp = fac(n-1);
    tmp %= mod;
    return n * tmp;
}


int fac_v(int n,int k){
    int ret = 1;
    while(k--){
        ret *= n;
        ret %= mod;
        n--;
    }
    return ret;
}




int select(int total, int k){
    if(k == 0){
        return 1;
    }
    if(k == total){
        return 1;
    }

    LL a1 = fac_v(total,k) % mod;
    LL a2 = fac(k) % mod;
    // int a2 = fac(k);
    return a1 / a2;
}


LL cal(int m, int n){
    if(m == 0) return 0;
    // m niu
    // n color
    LL sum = 1;
    LL product = 1;
    for(int i = 1;i<=m;i++){
        product *= n;
        product %= mod;            
        LL tmp = select(m,i); // i >= 1
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




