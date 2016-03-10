#include<cstdio>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;
int arr[1010];
int main(){
	int T, S; scanf("%d", &T);
	while (T--){
		int avg = 0, ans = 0, A = 0, rate = 0;
		scanf("%d", &S);
		for (int i = 0; i < S; i++){
			scanf("%d", &arr[i]);
			avg += arr[i];
		}
		rate = avg % S;
		avg /= S;
		for (int i = 0; i < S; i++){
			if (arr[i] > avg) ++A;
			else ans += avg - arr[i];
		}
		if (rate - A > 0) ans += (rate - A);
		printf("%d\n", ans);
	}
	return 0;
}