#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int Val[110], cnt[110];
int T, n, K;
bool isTrue(int val, int pos){
	if (val == 0) return 1;
	if (pos == n || val < 0) return 0;
	int ret = 0;
	for (int i = 0; i <= cnt[pos]; i++){
		if (val < Val[pos] * i) break;
		if (ret > 0) break;
		ret += isTrue(val - (Val[pos] * i), pos + 1);
	}
	return ret;
}
int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &Val[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &cnt[i]);
		scanf("%d", &K);
		if (isTrue(K, 0)) puts("Yes");
		else puts("No");
	}
	return 0;
}