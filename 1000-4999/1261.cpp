//BaekJoon_1261
//�˰���
/*
* ���� �ð� : 1s
* ���� ���� : 39.170%
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 99999
using namespace std;

int n, m;
vector<string> vec;
queue<pair<int, int>> q;
int cnt[110][110] = { 0, };
int d_x[] = { 0, 0, 1, -1 };
int d_y[] = { 1, -1, 0, 0 };

void algosPOT() {
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < m + 1; j++)
			cnt[i][j] = INF;
	}

	q.push(make_pair(0, 0));
	cnt[0][0] = 0;

	// ��濡�� ������� �̵��� ���� cnt�״��
	// ������ ������� �̵��� ���� cnt �״��
	// �� �ܿ��� cnt+1���� ������ �̵�, �ƴϸ� ���α�
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int n_x, n_y;
		for (int i = 0; i < 4; i++) {
			n_x = x + d_x[i];
			n_y = y + d_y[i];
			if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) continue;
			// ������ �̵��ϴ� ���
			if (vec[n_x][n_y] == '0' && cnt[x][y] < cnt[n_x][n_y]) {
				cnt[n_x][n_y] = cnt[x][y];
				q.push(make_pair(n_x, n_y));
			}
			else if (cnt[x][y] + 1 < cnt[n_x][n_y]) {
				cnt[n_x][n_y] = cnt[x][y] + 1;
				q.push(make_pair(n_x, n_y));
			}
		}
	}

	// ���
	cout << cnt[n - 1][m - 1] << endl;
	return;
}
int main() {
	cin >> m >> n;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	algosPOT();

	return 0;
}