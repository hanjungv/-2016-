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
				rem = K - A;	//������ ��⸦ ����մϴ�.
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