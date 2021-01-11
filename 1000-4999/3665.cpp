//BaekJoon_3665
//���� ����
/*
* ���� �ð� : 1s
* ���� ���� : 33.882%
*/

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
int team[502][502] = { 0, };
int prev_rank[502] = { 0, };
int indegree[502] = { 0, };
int result[502] = { 0, };

// ���� ��� ����
void arrange_prev_rank() {
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);		// temp���� i ���� �ߴ�
		prev_rank[temp] = i;	// prev[��] = i ��
	}

	// �׷����� ����
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (prev_rank[i] > prev_rank[j]) {	// i���� j������ ����� ����
				team[i][j] = 1;
				indegree[j]++;
			}
			else team[i][j] = 0;
		}
	}
	return;
}

void arrange_result_rank() {
	queue<int> q;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int curSize = q.size();

		// 2�� �̻� ���� ��� ��� ���� �Ұ���
		if (curSize >= 2) {	
			cout << "?" << endl;
			return;
		}

		int now = q.front();
		result[n-cnt] = now;	// �ڿ��� ���� ã�ư��� �Ŵϱ�
		cnt++;
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (team[now][i] == 1) {
				indegree[i]--;
				if (indegree[i] == 0)
					q.push(i);
			}
		}
	}

	if (cnt == n) {
		// �������� ���̽�
		for (int i = 1; i <= n; i++) {
			printf("%d ", result[i]);
		}
	}
	else {
		// Cycle�� ���ܼ� �߰��� �������� ���̽�
		cout << "IMPOSSIBLE";
	}
	cout << endl;
	return;
}

int main() {
	int testcase = 0;
	cin >> testcase;

	while (testcase-- != 0) {
		// �ʱ�ȭ
		memset(indegree, 0, sizeof(int)*502);
		memset(result, 0, sizeof(int)*502);
		memset(prev_rank, 0, sizeof(int) * 502);
		for (int i = 0; i < 502; i++) {
			memset(team[i], 0, sizeof(int) * 502);
		}
		
		cin >> n;
		arrange_prev_rank();	// ���� ��� ����
		
		// �̹� ��� �߰�
		cin >> m;
		int a, b;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			// swap
			if (team[a][b] == 1) {
				team[b][a] = 1;
				team[a][b] = 0;
				indegree[a]++;
				indegree[b]--;
			}
			else {
				team[a][b] = 1;
				team[b][a] = 0;
				indegree[a]--;
				indegree[b]++;
			}
		}

		// ���ο� ��� Ȯ��
		arrange_result_rank();
	}

	return 0;
}
