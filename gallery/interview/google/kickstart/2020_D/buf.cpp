#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int T, n, a, b;
    cin >> T;
    int parent[110];
    int vis[110];
    int res = 0;
    for (int t = 1; t <= T; t++){
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++)
            cin >> parent[i];
        parent[0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                vis[j] = 0;
            int r = i;
            vis[i] = 1;
            int cnt = 0;
            int sum = 1;
            while(parent[r] != 0){
                r = parent[r]-1;
                cnt++;
                if (cnt == a){
                    vis[r] = 1;
                    sum++;
                    cnt = 0;
                }
            }
            for (int j = 0; j < n; j++){
                int tmp = sum;
                r = j;
                if (vis[j] == 0){
                    tmp++;
                }
                cnt = 0;
                while(parent[r] != 0){
                    r = parent[r]-1;
                    cnt++;
                    if (cnt == b){
                        if (vis[r] == 0){
                            tmp++;
                        }
                        cnt = 0;
                    }
                }
                //cout << tmp << endl;
                res += tmp;
            }
        }
        cout << "Case #" << t << ": " << double(res)/double(n*n) << endl;
    }
    return 0;
}