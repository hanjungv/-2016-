#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[510]; 
int main(){
	//freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--){
		int N, A, B, ans = -1; scanf("%d", &N);
		memset(dp, 0, sizeof(dp));
		vector<pair<int, int> > vi;
		for (int i = 0; i < N; i++){
			scanf("%d %d", &A, &B);
			if (B > A) swap(A, B);
			vi.push_back({ A, B });
		}
		sort(vi.rbegin(), vi.rend());
		for (int i = 0; i < N; i++){
			for (int j = 0; j < i; j++){
				if (vi[i].first <= vi[j].first && vi[i].second <= vi[j].second)
					if (dp[j] + 1 > dp[i]){
						dp[i] = dp[j] + 1;
						ans = max(ans, dp[i]);
					}
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}