#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main(){
	freopen("input.txt", "r", stdin);
	int T, N, K, st, ed;	//T:testcase, N:칠하려는 횟수, K: 궁금한 횟수, st:시작구간, ed:종료구간
	scanf("%d", &T);	//Testcase를 입력받습니다.
	while (T--){
		scanf("%d %d", &N, &K);	
		map<int, int> mi;			//개구간 폐구간을 입력받을 map입니다. 
		for (int i = 0; i < N; i++){
			scanf("%d %d", &st, &ed);
			mi[st]++;			//맵에 시작점에는 +1
			mi[ed + 1]--;		//종료지점에는 -1을 하게 됩니다. 파셜섬을 하는데 지표로 사용되게 됩니다.
		}
		int Sum = 0;		//합을 구해주기 위해 편의상 Sum이라는 변수를 선언했습니다.
		for (map<int, int>::iterator it = mi.begin(); it != mi.end(); ++it){
			//맵의 처음부터 끝까지 사이즈만큼 돌면서
			it->second += Sum;	//맵의 value값을 누적해서 더해줍니다.
			Sum = it->second;
		}
		bool check = false;	//check는 K의 값이 됬을때 중복되는 값을 출력하지 않게 하기 위해 사용하는 변수입니다.
		for (map<int, int>::iterator it = mi.begin(); it != mi.end(); ++it){
			//똑같이 map의 크기만큼 반복문을 돕니다.
			if (it->second == K){
				if (!check){
					//만약 value값이 K이고 이전에 갱신해 준적이 없다면
					st = it->first; //구간의 시작부분을 저장시키고
					check = true;	//갱신시켜줍니다. 이부분을 하지 않아주면 계속해서 갱신을 시켜주게 되어 값이
									//중복되어 출력되거나 출력이 안될 수 있습니다.
				}
			}
			else{
				if (check){	
					//K의 값이 아니고 갱신이 됬을경우 그 K번 칠한 구간이 끝난것을 의미하므로 출력을 하게 됩니다.
					printf("%d %d\n", st, (it->first) - 1);
					check = false;	//이후 다시 갱신시켜줘야 하는 경우가 있을수 있으므로 다시 false로 바꿔줍니다.
				}
			}
		}
	}
	return 0;
}