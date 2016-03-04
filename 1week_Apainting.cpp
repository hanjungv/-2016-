#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main(){
	freopen("input.txt", "r", stdin);
	int T, N, K, st, ed;	//T:testcase, N:ĥ�Ϸ��� Ƚ��, K: �ñ��� Ƚ��, st:���۱���, ed:���ᱸ��
	scanf("%d", &T);	//Testcase�� �Է¹޽��ϴ�.
	while (T--){
		scanf("%d %d", &N, &K);	
		map<int, int> mi;			//������ �󱸰��� �Է¹��� map�Դϴ�. 
		for (int i = 0; i < N; i++){
			scanf("%d %d", &st, &ed);
			mi[st]++;			//�ʿ� ���������� +1
			mi[ed + 1]--;		//������������ -1�� �ϰ� �˴ϴ�. �ļȼ��� �ϴµ� ��ǥ�� ���ǰ� �˴ϴ�.
		}
		int Sum = 0;		//���� �����ֱ� ���� ���ǻ� Sum�̶�� ������ �����߽��ϴ�.
		for (map<int, int>::iterator it = mi.begin(); it != mi.end(); ++it){
			//���� ó������ ������ �����ŭ ���鼭
			it->second += Sum;	//���� value���� �����ؼ� �����ݴϴ�.
			Sum = it->second;
		}
		bool check = false;	//check�� K�� ���� ������ �ߺ��Ǵ� ���� ������� �ʰ� �ϱ� ���� ����ϴ� �����Դϴ�.
		for (map<int, int>::iterator it = mi.begin(); it != mi.end(); ++it){
			//�Ȱ��� map�� ũ�⸸ŭ �ݺ����� ���ϴ�.
			if (it->second == K){
				if (!check){
					//���� value���� K�̰� ������ ������ ������ ���ٸ�
					st = it->first; //������ ���ۺκ��� �����Ű��
					check = true;	//���Ž����ݴϴ�. �̺κ��� ���� �ʾ��ָ� ����ؼ� ������ �����ְ� �Ǿ� ����
									//�ߺ��Ǿ� ��µǰų� ����� �ȵ� �� �ֽ��ϴ�.
				}
			}
			else{
				if (check){	
					//K�� ���� �ƴϰ� ������ ������� �� K�� ĥ�� ������ �������� �ǹ��ϹǷ� ����� �ϰ� �˴ϴ�.
					printf("%d %d\n", st, (it->first) - 1);
					check = false;	//���� �ٽ� ���Ž������ �ϴ� ��찡 ������ �����Ƿ� �ٽ� false�� �ٲ��ݴϴ�.
				}
			}
		}
	}
	return 0;
}