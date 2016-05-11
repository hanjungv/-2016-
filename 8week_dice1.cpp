#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int T, W, H, N, M, x, y, num, idx, arr[10][10], dice[12][6], dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
int isA[6][4] = { { 2, 4, 5, 3 }, { 6, 4, 1, 3 }, { 2, 1, 5, 6 }, { 1, 2, 6, 5 }, { 1, 4, 6, 3 }, { 2, 3, 5, 4 } };
char side;
void Modeling(int idx, char side, int num);
void Modeling2();
void Find();
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		memset(arr, -1, sizeof(arr));
		memset(dice, 0, sizeof(dice));
		scanf("%d %d", &W, &H);
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &x, &y, &num);
			--y;
			--x;
			arr[y][x] = i;
			dice[i][0] = num;
			dice[i][5] = 7 - num;
		}
		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %c %d", &idx, &side, &num);
			idx--;
			Modeling(idx, side, num);
		}
		Modeling2();
		Find();
	}
	return 0;
}
void Modeling(int idx, char side, int num) {
	if (side == 'L') {
		dice[idx][1] = num;
		dice[idx][3] = 7 - num;
	}
	else if (side == 'R') {
		dice[idx][3] = num;
		dice[idx][1] = 7 - num;
	}
	else if (side == 'U') {
		dice[idx][2] = num;
		dice[idx][4] = 7 - num;
	}
	else {
		dice[idx][4] = num;
		dice[idx][2] = 7 - num;
	}
}
void Modeling2() {
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (arr[y][x] != -1) {
				for (int i = 0; i < 4; i++) {
					int nextX = x + dx[i];
					int nextY = y + dy[i];
					if (nextX >= 0 && nextX < W&&nextY >= 0 && nextY < H) {
						if (arr[nextY][nextX] != -1) {
							int Idx = arr[nextY][nextX];
							int ex_Idx = arr[y][x];
							if (i == 0) {
								if (dice[ex_Idx][2] != 0) {
									dice[Idx][4] = dice[ex_Idx][2];
									dice[Idx][2] = 7 - dice[Idx][4];
								}
								else {
									if (dice[Idx][4] != 0) {
										dice[ex_Idx][2] = dice[Idx][4];
										dice[ex_Idx][4] = 7 - dice[ex_Idx][2];
									}
								}
							}
							else if (i == 1) {
								if (dice[ex_Idx][3] != 0) {
									dice[Idx][1] = dice[ex_Idx][3];
									dice[Idx][3] = 7 - dice[Idx][1];
								}
								else {
									if (dice[Idx][1] != 0) {
										dice[ex_Idx][3] = dice[Idx][1];
										dice[ex_Idx][1] = 7 - dice[ex_Idx][3];
									}
								}
							}
							else if (i == 2) {
								if (dice[ex_Idx][4] != 0) {
									dice[Idx][2] = dice[ex_Idx][4];
									dice[Idx][4] = 7 - dice[Idx][2];
								}
								else {
									if (dice[Idx][2] != 0) {
										dice[ex_Idx][4] = dice[Idx][2];
										dice[ex_Idx][2] = 7 - dice[ex_Idx][4];
									}
								}
							}
							else {
								if (dice[ex_Idx][1] != 0) {
									dice[Idx][3] = dice[ex_Idx][1];
									dice[Idx][1] = 7 - dice[Idx][3];
								}
								else {
									if (dice[Idx][3] != 0) {
										dice[ex_Idx][1] = dice[Idx][3];
										dice[ex_Idx][3] = 7 - dice[ex_Idx][1];
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void Find(){
	for (int i = 0; i < N; i++){
		bool isTrue = false;
		int Top = dice[i][0];
		for (int j = 0; j < 4; j++){
			if (isA[Top - 1][j] == dice[i][1]){
				for (int k = 0; k < 4; k++){
					if (isA[Top - 1][(j + k) % 4] != dice[i][1 + k])
						break;
					if (k == 3){
						isTrue = true;
						break;
					}
				}
				if (isTrue) break;
			}
			if (isTrue) break;
		}
		if (isTrue) printf("A ");
		else printf("B ");
	}
	puts("");
	return;
}