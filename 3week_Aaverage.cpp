#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double arr[100010];
int main(){
	//freopen("input.txt", "r", stdin);
	int T, n; scanf("%d", &T);
	while (T--){
		double Sum = 0;	//총합입니다.
		scanf("%d", &n);	//n을 입력받습니다.
		for (int i = 0; i < n; i++){
			scanf("%lf", &arr[i]);	//n만큼 숫자를받고
			Sum += arr[i];	//합을 구해줍니다.
		}
		sort(arr, arr + n);	//오름차순으로 소팅을 해주고
		printf("%.3f ", (Sum - arr[n - 1] - arr[0]) / (n - 2));	//절사평균
		printf("%.3f", (Sum - arr[n - 1] - arr[0] + arr[1] + arr[n - 2]) / n);	//보정평균을 구해줍니다.
		puts("");
	}
	return 0;
}