#include<cstdio>
#include<algorithm>
using namespace std;
int arr[1010], check[1010];
int main(){
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);	//Testcase 입력을 받습니다.
	while (T--){
		int N, M, Total = 0; scanf("%d %d", &N, &M);
		arr[0] = 0, arr[N + 1] = 0;	//양쪽을 보면서 비교해야 하기 때문에 끝구간을 0으로 초기화합니다.
		for (int i = 1; i <= N; i++){
			scanf("%d", &arr[i]);	//입력을 받고 Total은 치즈의 갯수입니다.
			Total += arr[i];
		}
		int Cnt = 0;	//출력할 답입니다.
		while (Total){	//Total이 0이 되면 탈출합니다.
			for (int i = 1; i <= N; i++)
				check[i] = max(1, max(arr[i] - arr[i - 1], arr[i] - arr[i + 1]));
			//check를 갱신합니다. check에는 양옆과 윗면을 포함한 최대 노출면을 담습니다.
			for (int i = 1; i <= N; i++){
				if (arr[i] > 0){
					arr[i] -= check[i];	//차감해주고
					Total -= check[i];	//먹은 cheese를 삭제해줍니다.
				}
			}
			Cnt++;	//날을 추가시켜줍니다.
		}
		printf("%d\n", Cnt);
	}
	return 0;
}