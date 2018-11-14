#include<iostream>
using namespace std;



//考察，补码加法溢出的问题
//只有两种可能，两个负相加，或两个正相加
//若溢出，sum的范围[-2^63，-2] 或 [0,2^63]
int main() {
	long long int a, b, c,sum;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;
		sum = a + b;
		if (a > 0 && b > 0 && sum < 0) {
			cout << "Case #"<<i+1<<": "<<"true" << endl;
		}
		else if (a < 0 && b < 0 && sum >= 0) {
			cout << "Case #" << i + 1 << ": " << "false" << endl;
		}
		else {
			if(sum > c)
				cout << "Case #" << i + 1 << ": " << "true" << endl;
			else
				cout << "Case #" << i + 1 << ": " << "false" << endl;
		}
	}
	//while (1);
	return 0;
}
