#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool arr[1010][1010];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int T, n, m;
bool isPossible(int x, int y){
	return (x >= 0 && x < n&&y >= 0 && y < n);
}
int main(){
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--){
		bool isTrue=false;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (arr[i][j] == 0){
					int Cnt = 0;
					for (int k = 0; k < 4; k++){
						int X = j + dx[k];
						int Y = i + dy[k];
						if (isPossible(X, Y)){
							if (arr[Y][X] == 0) 
								Cnt++;
						}
					}
					if (Cnt % 2 != 0){
						isTrue = true;
						break;
					}
				}
			}
			if (isTrue) break;
		}
		if (isTrue) puts("0");
		else puts("1");
	}
	return 0;
}