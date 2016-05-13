#include<cstdio>
#include<cstring>
using namespace std;
int check[1563];
int i, T, N, c, inp;
int main(){
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--){
		memset(check, false, sizeof(check));
		scanf("%d %d", &N, &c);
		for (i = 0; i < N - c; i++){
			scanf("%d", &inp);
			check[inp / 32] |= (1 << (inp % 32));
		}
		for (i = 0; i < N; i++){
			if ((check[(i + 1) / 32] & (1 << (i + 1) % 32)) == 0)
				printf("%d ", i + 1);
		}
		puts("");
	}
	return 0;
}