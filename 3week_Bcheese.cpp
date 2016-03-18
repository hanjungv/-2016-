#include<cstdio>
#include<algorithm>
using namespace std;
int arr[1010], check[1010];
int main(){
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);	//Testcase �Է��� �޽��ϴ�.
	while (T--){
		int N, M, Total = 0; scanf("%d %d", &N, &M);
		arr[0] = 0, arr[N + 1] = 0;	//������ ���鼭 ���ؾ� �ϱ� ������ �������� 0���� �ʱ�ȭ�մϴ�.
		for (int i = 1; i <= N; i++){
			scanf("%d", &arr[i]);	//�Է��� �ް� Total�� ġ���� �����Դϴ�.
			Total += arr[i];
		}
		int Cnt = 0;	//����� ���Դϴ�.
		while (Total){	//Total�� 0�� �Ǹ� Ż���մϴ�.
			for (int i = 1; i <= N; i++)
				check[i] = max(1, max(arr[i] - arr[i - 1], arr[i] - arr[i + 1]));
			//check�� �����մϴ�. check���� �翷�� ������ ������ �ִ� ������� ����ϴ�.
			for (int i = 1; i <= N; i++){
				if (arr[i] > 0){
					arr[i] -= check[i];	//�������ְ�
					Total -= check[i];	//���� cheese�� �������ݴϴ�.
				}
			}
			Cnt++;	//���� �߰������ݴϴ�.
		}
		printf("%d\n", Cnt);
	}
	return 0;
}