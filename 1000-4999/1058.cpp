//BaekJoon_1058
//친구
/*
* 제한 시간 : 2s
* 정답 비율 : 39.145%
*/

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

int two_friend(vector<int> v[], int x, int size) {
	int cnt = 0;
	queue<int> q;
	bitset<51> visit;	visit.reset();
	visit[x] = 1;	// 본인은 본인의 친구가 될 수 없다

	// 직계 친구
	for (int i = 0; i < size; i++) {
		q.push(v[x][i]);
		visit[v[x][i]] = 1;
		cnt++;
	}

	// 건너 친구
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int s = v[now].size();
		for (int i = 0; i < s; i++) {
			int next = v[now][i];
			if (!visit[next] & 1) {
				visit[next] = 1;
				cnt++;
			}
		}
	}

	return cnt;
}
int main() {
	int n;
	char sin[51];
	vector<int> v[51];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", sin);
		for (int j = 0; j < n; j++) {
			if (sin[j] == 'Y') {
				v[i].push_back(j);
			}
		}
	}

	int max_cnt = 0;
	for (int i = 0; i < n; i++) {
		max_cnt = max(max_cnt, two_friend(v, i, v[i].size()));
	}
	printf("%d\n", max_cnt);

	return 0;
}