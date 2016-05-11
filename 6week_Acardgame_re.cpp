#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
using namespace std;
int arr[10010];
int main(){
	//freopen("input.txt", "r", stdin);
	int T, N; scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + N);
		int Val = INT_MAX, left = 0, right = N - 1;
		while (left < right){
			Val = min(Val, abs(arr[left] + arr[right]));
			if (arr[left] + arr[right] > 0) right--;
			else left++;
		}
		printf("%d\n", Val);
	}
	return 0;
}