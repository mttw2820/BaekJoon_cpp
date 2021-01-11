//BaekJoon_1948
//�Ӱ���
/*
* ���� �ð� : 2s
* ���� ���� : 28.058%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* ������ ��� ��� Ž��, ��� ��� �̵��ڰ� ���̴� �ð�
   == ���� �ð� */
int n, m;
vector<pair<int, int>> next_city[10010];	// ���� ����, �Ÿ�
vector<pair<int, int>> prev_city[10010];	// ���� ����, �Ÿ�
queue<int> Q;
int Time[10010] = { 0, };

int main() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		next_city[a].push_back(make_pair(b, c));
		prev_city[b].push_back(make_pair(a, c));
	}
	int start = 0, end = 0;
	cin >> start >> end;

	// ���� ��� �ð�
	Q.push(start);
	while (!Q.empty()) {
		int now = Q.front();
		int t = Time[now];
		Q.pop();

		for (int i = 0; i < next_city[now].size(); i++) {
			int next = next_city[now][i].first;
			int path = next_city[now][i].second;
			if (t + path > Time[next]) {
				Time[next] = t + path;
				Q.push(next);
			}
		}
	}
	int result_time = Time[end];

	// ���� ��� ������ ��
	int path_cnt = 0;
	Q.push(end);
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();

		for (int i = 0; i < prev_city[now].size(); i++) {
			int prev = prev_city[now][i].first;
			int path = prev_city[now][i].second;
			if (prev_city[now][i].second == -1) continue;
			if (Time[now] - path == Time[prev]) {
				//�ѹ� ���� path�� �ٽ� count�Ǹ� �ȵǴϱ� �����
				prev_city[now][i].second = -1;
				path_cnt++;
				Q.push(prev);
			}
		}
	}

	cout << result_time << endl << path_cnt << endl;

	return 0;
}