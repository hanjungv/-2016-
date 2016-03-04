#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	freopen("input.txt", "r", stdin);
	int T, A, B, C, st, ed; scanf("%d", &T);
	// T,A,B,C는 문제에서 나타내는 바와 같습니다. st,ed는 S,E를 나타냅니다.
	while (T--){
		int Cnt = 0;	//문제에서 답을 나타냅니다. 카운트를 할 것입니다.
		scanf("%d %d %d %d %d", &A, &B, &C, &st, &ed);	//입력을 받습니다.
		for (int i = st; i <= ed; i++){	//시작부분부터 끝부분까지 for문을 돌게 됩니다.
			int check = i;				//밑에서 i를 나눠줄것이기 때문에 반복문에 영향이 없게 check로 받아옵니다.
			if (check%A == 0) ++Cnt;	//A의 배수일때 카운트를 증가시킵니다.
			else if (check%B == 0) ++Cnt;	//위와 같이 B의 배수일때
			else if (check%C == 0) ++Cnt;	//C의 배수일때 체크합니다.
			else{	//만약 A,B,C의 배수도 아닐경우
				while (check > 0){	//그 자리수에 A,B,C가 들어가는지 확인합니다. 
					//문제에서 최대 100000까지 들어올수 있기때문에 최대 6번 while문을 돌게 됩니다
					if (check % 10 == A || check % 10 == B || check % 10 == C){
						++Cnt;	//자리수에 A,B 혹은 C가 들어갈 경우 Cnt를 증가시키고
						break;	//중복 카운트를 하지 않기 위해 탈출합니다.
					}
					check /= 10;	//만약 break되지 않을 경우 계속해서 감소시켜 확인해야 하기 때문에 10을나눠줍니다.
				}
			}
		}
		printf("%d\n", Cnt);//그리고 카운트를 출력시킵니다.
	}
	return 0;
}