#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double arr[100010];
int main(){
	//freopen("input.txt", "r", stdin);
	int T, n; scanf("%d", &T);
	while (T--){
		double Sum = 0;	//�����Դϴ�.
		scanf("%d", &n);	//n�� �Է¹޽��ϴ�.
		for (int i = 0; i < n; i++){
			scanf("%lf", &arr[i]);	//n��ŭ ���ڸ��ް�
			Sum += arr[i];	//���� �����ݴϴ�.
		}
		sort(arr, arr + n);	//������������ ������ ���ְ�
		printf("%.3f ", (Sum - arr[n - 1] - arr[0]) / (n - 2));	//�������
		printf("%.3f", (Sum - arr[n - 1] - arr[0] + arr[1] + arr[n - 2]) / n);	//��������� �����ݴϴ�.
		puts("");
	}
	return 0;
}