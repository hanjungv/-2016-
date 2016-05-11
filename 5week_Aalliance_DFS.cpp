#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
bool visited[100010];
vector<vector<int> > graph;
int ans = -1, val = 0;
void DFS(int here){
	visited[here] = true;
	for (int i = 0; i < graph[here].size(); i++){
		int there = graph[here][i];
		if (!visited[there]){
			val++;
			DFS(there);
		}
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	int T, N, M, X, Y; scanf("%d", &T);
	while (T--){
		scanf("%d %d", &N, &M);
		memset(visited, 0, sizeof(visited));
		graph.clear();
		graph.resize(N + 1);
		ans = -1;
		for (int i = 0; i < M; i++){
			scanf("%d %d", &X, &Y);
			graph[X].push_back(Y);
			graph[Y].push_back(X);
		}
		for (int i = 1; i <= N; i++)
			if (!visited[i]){
				val = 0;
				DFS(i);
				ans = max(ans, val);
			}
		printf("%d\n", ans + 1);
	}
	return 0;
}