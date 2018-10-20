#include<cstdio>
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (v[mid] == x)
		return mid;
	return -1;
}

int main(){
	int a[5] = {1, 2, 3, 4, 5};
	for(int x = 1;x<=5;x++)
		printf("%d\n",binsearch(x,a,5));
	return 0;
}