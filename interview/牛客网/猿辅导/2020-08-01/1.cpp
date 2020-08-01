#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

typedef long long LL;
// or #define LL long long

using namespace std;


struct Node{
    int val;
    int time;
};


bool cmp(Node & a, Node & b){
    if(a.time != b.time){
        return a.time < b.time;
    }
    else{
        return a.val < b.val;
    }
}




void print(vector<Node> & nodes){
    for(auto tmp : nodes){
        cout<<"time :"<<tmp.time<<"\t"<<"val: "<<tmp.val<<endl;
    }
    cout<<endl;
}

int cal(vector<Node> & nodes){
    sort(nodes.begin(), nodes.end(), cmp);
    int ret = 0;
    int cur_cnt = 0;
    for(auto tmp : nodes){
        if(tmp.val > 0){
            cur_cnt++;
            ret = max(ret, cur_cnt);
        }
        else{
            cur_cnt--;
        }
    }
    return ret;
}


int main() {
	std::ios::sync_with_stdio(false);
    int n;
    Node tmp;
    vector<Node> nodes;
    while (cin>>n){   
        nodes.clear();
        while(n--){
            int s,e;
            cin>>s>>e;
            tmp.time = s;
            tmp.val = 1;
            nodes.push_back(tmp);
            tmp.time = e;
            tmp.val = -1;
            nodes.push_back(tmp);
        }
        int ret = cal(nodes);
        // print(nodes);
        cout<<ret<<endl;
    }
	return 0;
}




/*
4
1 4
1 2
2 3
3 4


2




AC
*/

