#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	freopen("input.txt", "r", stdin);
	int T, A, B, C, st, ed; scanf("%d", &T);
	// T,A,B,C�� �������� ��Ÿ���� �ٿ� �����ϴ�. st,ed�� S,E�� ��Ÿ���ϴ�.
	while (T--){
		int Cnt = 0;	//�������� ���� ��Ÿ���ϴ�. ī��Ʈ�� �� ���Դϴ�.
		scanf("%d %d %d %d %d", &A, &B, &C, &st, &ed);	//�Է��� �޽��ϴ�.
		for (int i = st; i <= ed; i++){	//���ۺκк��� ���κб��� for���� ���� �˴ϴ�.
			int check = i;				//�ؿ��� i�� �����ٰ��̱� ������ �ݺ����� ������ ���� check�� �޾ƿɴϴ�.
			if (check%A == 0) ++Cnt;	//A�� ����϶� ī��Ʈ�� ������ŵ�ϴ�.
			else if (check%B == 0) ++Cnt;	//���� ���� B�� ����϶�
			else if (check%C == 0) ++Cnt;	//C�� ����϶� üũ�մϴ�.
			else{	//���� A,B,C�� ����� �ƴҰ��
				while (check > 0){	//�� �ڸ����� A,B,C�� ������ Ȯ���մϴ�. 
					//�������� �ִ� 100000���� ���ü� �ֱ⶧���� �ִ� 6�� while���� ���� �˴ϴ�
					if (check % 10 == A || check % 10 == B || check % 10 == C){
						++Cnt;	//�ڸ����� A,B Ȥ�� C�� �� ��� Cnt�� ������Ű��
						break;	//�ߺ� ī��Ʈ�� ���� �ʱ� ���� Ż���մϴ�.
					}
					check /= 10;	//���� break���� ���� ��� ����ؼ� ���ҽ��� Ȯ���ؾ� �ϱ� ������ 10�������ݴϴ�.
				}
			}
		}
		printf("%d\n", Cnt);//�׸��� ī��Ʈ�� ��½�ŵ�ϴ�.
	}
	return 0;
}