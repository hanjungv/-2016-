#include<iostream>
#include<cstdio>
using namespace std;
int T, K, C, A, B, rem;
int main(){
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &K, &C);
		for (int i = 0; i < C; i++){
			scanf("%d %d", &A, &B);
			if (A >= B){
				rem = K - A;	//나머지 경기를 계산합니다.
				if (B + rem + 1 >= A - 1) puts("1");
				else puts("0");
			}
			else{
				rem = K - B;
				if (A + rem >= B - 1) puts("1");
				else puts("0");
			}
		}
	}
	return 0;
}