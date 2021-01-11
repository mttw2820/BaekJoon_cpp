//BaekJoon_9466
//�� ������Ʈ
/*
* ���� �ð� : 3s
* ���� ���� : 24.414%
*/

#include <iostream>
using namespace std;

int students[100001] = { 0, };
int check[100001] = { 0, };	//����Ŭ -1
int n;

void make_team(int now, int cnt) {
	int next = students[now];

	if (check[next] == 0) {	// ù �湮
		check[now] = cnt;
		make_team(next, cnt);
	}
	else {	// �湮 ��� �ִ� ���
		if (check[next] == -1) {
			if (check[now] == 0) return;
			check[now] = -1;
			return;
		}
		else if(check[next] == cnt) {
			check[now] = -1;
			make_team(next, cnt);
		}
		else return;
	}

	return;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase != 0) {
		int in_team = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &students[i]);
			check[i] = 0;
		}

		// ������Ʈ ���� �̷�� �л����� �� count
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0)
				make_team(i, cnt ++);
		}

		for (int i = 1; i <= n; i++) {
			if (check[i] == -1) in_team++;
		}
		cout << n - in_team << endl;
	
		testcase--;
	}

	return 0;
}