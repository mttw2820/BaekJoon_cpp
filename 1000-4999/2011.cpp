//BaekJoon_2011
//��ȣ�ڵ�
/*
* ���� �ð� : 2s
* ���� ���� : 19.762%
*/

#include <iostream>
using namespace std;

char code[5001];
int dp[5001] = { 0, };
//dp[i]�� code[i-1]���� ���� �� �ִ� �ִ� �ؼ� ����� ��
int main() {
	scanf("%s", code);

	dp[0] = 1; dp[1] = 1;
	int prev = code[0] - '0';
	//ù ���ڰ� 0�̸� ����
	if (prev == 0) {
		cout << "0" << endl;
		return 0;
	}
	int i = 2;
	for (i = 2; code[i-1]; i++) {
		int now = code[i-1] - '0';
		//0�� �ι��̻� ����
		if (now == 0 && prev == 0) {
			cout << "0" << endl;
			return 0;
		}
		//���ڸ� �� ��ȣ�� ���
		if (now != 0) {
			dp[i] = dp[i - 1];
		}
		//���ڸ� �� ��ȣ�� ���
		if ((prev == 1)||(prev == 2 && now <= 6)) {	
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}
		
		prev = now;
	}
	cout << dp[i-1] << endl;
	return 0;
}