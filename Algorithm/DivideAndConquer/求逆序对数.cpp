#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

int n, num[20010], sum, res[20010];

void merge(int l, int mid, int r){
	int l_index = l;
	int r_index = mid + 1;
	int s = l;
	while(l_index <= mid && r_index <= r){
		if (num[l_index] > num[r_index]){
			sum += mid - l_index + 1;
			res[s] = num[r_index];
			s++;
			r_index++;
		}
		else{
			res[s] = num[l_index];
			s++;
			l_index++;
		}
	}
	while(l_index <= mid){
		res[s] = num[l_index];
		s++;
		l_index++;
	}
	while(r_index <= r){
		res[s] = num[r_index];
		s++;
		r_index++;
	}
	for (int i = l; i <= r; i++)
		num[i] = res[i];
	return;
}

void divide(int l, int r){
	if (l == r){
		return;
	}
	else{
		int mid = (l+r)/2;
		divide(l, mid);
		divide(mid+1, r);
		merge(l, mid, r);
	}
}


int main(){
	while(cin >> n){
		if(n == 0) break;
		sum = 0;
		for (int i = 0; i < n; i++) 
			cin >> num[i];
		divide(0, n-1);
		cout << sum << endl;
	}
    return 0;
}

