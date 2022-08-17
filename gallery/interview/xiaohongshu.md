```bash
求两个字符串的最长连续公共子串
a = avbgnh
b = chbgndd
res = bgn
```

```c++
#include <iostream>
#include<bits/c++.h>
using namespace std;

// To execute C++, please define "int main()"

// The TestCase is shown below
// Input : 1 2
// Output : 3


int dp_len[105][105];

string lcs(string a, string b){
	int m = a.size();
	int n = b.size();
	if(m * n == 0) return "";
	
	for(int i = 0; i <= m; i++){
		dp_len[i][0] = 0;
	}
	for(int j = 0; j <= n; j++){
		dp_len[0][j] = 0;
	}
	int max_len = 0;
	int cur_len = 0;
	string ret = "";
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a[i] == b[j]){
				int cur_max_len = max(dp[i-1][j-1], dp[i-1][j]);
				cur_max_len = max(cur_max_len, dp[i][j-1]);
				dp_len[i][j] = max(cur_max_len + 1, dp_len[i][j]);
                if(dp[i][j] > max_len){
                    max_len = dp[i][j];
                    ret = a.substring(i, max_len);
                }
			}
			else{
				;
			}
		}
	}
}

int main() {
	string words = "Hello, World!";
	cout << words << endl;
	int a, b;
	while(cin>> a >> b)
	cout << "Your result is : "<< a + b << endl;
  	return 0;
}
```

复盘
```c++
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"

// The TestCase is shown below
// Input : 1 2
// Output : 3


int dp_len[105][105];

string lcs(string a, string b){
    int m = a.size();
    int n = b.size();
    if(m * n == 0) return "";
    
    for(int i = 0; i <= m; i++){
        dp_len[i][0] = 0;
    }
    for(int j = 0; j <= n; j++){
        dp_len[0][j] = 0;
    }
    int max_len = 0;
    int cur_len = 0;
    string ret = "";
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i-1] == b[j-1]){
                dp_len[i][j] = max(dp_len[i][j], dp_len[i-1][j-1] + 1);
                // cout<<i<<" "<<a[i-1]<<endl;
                // cout<<j<<" "<<b[j-1]<<endl;
                // cout<<dp_len[i][j]<<endl;
                // cout<<max_len<<endl;
                if(dp_len[i][j] > max_len){
                    max_len = dp_len[i][j];
                    // cout<<i - max_len<<endl;
                    // cout<<i<<endl;
                    ret = a.substr(i - max_len, max_len);
                    // cout<<ret<<endl;
                }
                // cout<<"-----"<<endl;
            }
            else{
                ;
            }
        }
    }
    return ret;
}

int main(){
    // string a = "abc";
    // string b = "bc";

    // string a = "abc";
    // string b = "c";

    // string a = "abc";
    // string b = "d";

    string a = "abcd";
    string b = "efbcg";

    string ret = lcs(a, b);
    cout<<ret<<endl;
}

```


题目
```
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise and anti-clockwise)

input: matrix = [[1,2,3],[4,5,6],[7,8,9]], mode 
output : mode = 0 -> [[7,4,1],[8,5,2],[9,6,3]] 
         mode = 1 -> [[3,6,9], [2,5,8], [1,4,7]]

mode = 0
1 2 3       7 4 1
4 5 6  ->   8 5 2
7 8 9       9 6 3

mode = 1
1 2 3       3 6 9
4 5 6  ->   2 5 8
7 8 9       1 4 7

https://www.programiz.com/python-programming/online-compiler/
```

```
'''

A^T 逐列交换

'''

def swap_col(matrix, row_cnt, i, j):
    for row_idx in range(row_cnt):
        matrix[row_idx][i], matrix[row_idx][j] = matrix[row_idx][j], matrix[row_idx][i]

def tran_matrix(matrix, m, n):
    for i in range(m // 2):
        for j in range(n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

def tran_all(matrix):
    if matrix is None:
        return None
    m = len(matrix)
    n = len(matrix[0])

    // At
    tran_matrix(matrix)

    for i in range(n // 2 ):
        j = n - 1 - i
        swap_col(matrix, m, i ,j)
    

```

复盘
```
'''
矩阵转置 逐列交换
'''

def swap_col(matrix, row_cnt, i, j):
    for row_idx in range(row_cnt):
        matrix[row_idx][i], matrix[row_idx][j] = matrix[row_idx][j], matrix[row_idx][i]

def tran_matrix(matrix, m, n):
    for i in range(m):
        for j in range(i+1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

def tran_all(matrix):
    if matrix is None:
        return None
    m = len(matrix)
    n = len(matrix[0])

    tran_matrix(matrix)

    for i in range(n // 2):
        j = n - 1 - i
        swap_col(matrix, m, i ,j)

```
