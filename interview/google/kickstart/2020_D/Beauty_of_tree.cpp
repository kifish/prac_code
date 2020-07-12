#include<bits/stdc++.h>
using namespace std;


int travel(vector<int> & parent, vector<bool> & visited, int start_node, int interval){
    // start_node >= 1
    int ret = 0;
    int window_cnt = 0;
    do{ 
        if(window_cnt == 0){
            if(!visited[start_node]){
                visited[start_node] = true;
                ret++;
            }
        }
        window_cnt++;
        if(window_cnt == interval){
            window_cnt = 0; // 又可以涂色了
        }

        start_node = parent[start_node];
    }while (start_node != -1);

    return ret;
}

int count(vector<int> & parent, int s1, int s2, int interval1, int interval2){
    int ret = 0;
    vector<bool> visited(parent.size(), false);
    ret += travel(parent, visited,s1,interval1);
    ret += travel(parent, visited,s2,interval2);
    return ret;
}

int main(){
    int case_num = 0;
    cin>>case_num;
    const int max_n = 5 * 1e5 + 1;
    vector<int> parent(101, 0);

    for(int i = 1;i<=case_num;i++){
        int n,tmp,a,b;
        cin>>n>>a>>b;
        parent[1] = -1; // root
        for(int i = 2;i<=n;i++){
            cin>>tmp;
            parent[i] = tmp;
        }
        int total_cnt = 0;
        for(int start_i = 1;start_i<=n;start_i++){
            for(int start_j=1;start_j<=n;start_j++){
                total_cnt += count(parent,start_i,start_j,a,b);
            }
        }
        double ret = (double) total_cnt / (double) (n * n);
        cout<<"Case #"<<i<<": "<<ret<<endl;
    }
}