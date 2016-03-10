#include<iostream>
#include<algorithm>
#include<cstdio>
int M, N, T, arr[502], add[500];
using namespace std;
int main(){
	scanf("%d", &T);
	while (T--){
		int Total = 0;
		scanf("%d %d", &M, &N);
		while (N--){
			for (int i = 0; i < M; i++){
				scanf("%d", &arr[i]);
				Total += arr[i];
			}
			for (int i = 0; i < M - 1; i++){
				scanf("%d", &add[i]);
				Total += add[i];
			}
			for (int k = M - 1; k > 0; k--){
				int new_add = arr[k - 1], last = arr[k];
				for (int i = 0; i < M - 1; i++){
					int comp = add[i];
					add[i] = min(comp, min(new_add, last));
					if (add[i] == 0)
						break;
					Total += add[i];
					last = comp;
					new_add = add[i];
				}
			}
		}
		printf("%d\n", Total);
	}
	return 0;
}
