#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int arr[500][500];
int main(){
	//freopen("input.txt", "r", stdin);
	int Total = 0, T, M, N, input, i, j;
	scanf("%d", &T);
	while (T--){
		Total = 0;
		scanf("%d %d", &M, &N);
		while (N--){
			for (i = 0; i < M; i++){
				if (i == 0){
					for (j = 0; j < M; j++){
						scanf("%d", &arr[j][i]);
						Total += arr[j][i];
					}
					j--;
				}
				else {
					scanf("%d", &arr[j][i]);
					Total += arr[j][i];
				}
			}
			for (i = M - 2; i >= 0; i--){
				for (j = 1; j < M; j++){
					arr[i][j] = min(arr[i + 1][j], min(arr[i + 1][j - 1], arr[i][j - 1]));
					Total += arr[i][j];
				}
			}
		}
		printf("%d\n", Total);
	}
	return 0;
}