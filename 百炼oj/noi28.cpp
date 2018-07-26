//题目：http://noi.openjudge.cn/ch0107/28/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string a;
    vector<string> s;
    std::ios::sync_with_stdio(false);
    while(cin>>a){    //遇到空格换行不会结束，需ctrl+z
        s.push_back(a);
            
    }
    for(int i=s.size()-1;i>=0;i--){
        if(i!=s.size()-1) cout<<" ";
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}
