#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int T, N, M, from, to;
bool visited[100010];
int main(){
	/*********************************
	 BFS로 최대 동맹국의 개수를 갱신해줌
	*********************************/
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--){
		int ans = -1;
		memset(visited, false, sizeof(visited));
		scanf("%d %d", &N, &M);
		vector<vector<int> > vi(N + 1);
		for (int i = 0; i < M; i++){
			scanf("%d %d", &from, &to);
			vi[from].push_back(to);
			vi[to].push_back(from);
		}
		for (int a = 1; a <= N; a++){
			if (visited[a]) continue;
			int Cnt = 0;
			queue<int> qu;
			qu.push(a);
			visited[a] = true;
			while (!qu.empty()){
				int SIZ = qu.size();
				for (int i = 0; i < SIZ; i++){
					int Top = qu.front();
					qu.pop();
					for (int j = 0; j < vi[Top].size(); j++){
						int next = vi[Top][j];
						if (!visited[next]){
							Cnt++;
							qu.push(next);
							visited[next] = true;
						}
					}
				}
			}
			ans = max(ans, Cnt);
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}