//BaekJoon_3665
//최종 순위
/*
* 제한 시간 : 1s
* 정답 비율 : 33.882%
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

// 지난 등수 정리
void arrange_prev_rank() {
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);		// temp번이 i 등을 했다
		prev_rank[temp] = i;	// prev[팀] = i 등
	}

	// 그래프로 정리
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (prev_rank[i] > prev_rank[j]) {	// i팀이 j팀보다 등수가 낮다
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

		// 2개 이상 들어온 경우 등수 결정 불가능
		if (curSize >= 2) {	
			cout << "?" << endl;
			return;
		}

		int now = q.front();
		result[n-cnt] = now;	// 뒤에서 부터 찾아가는 거니까
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
		// 정상적인 케이스
		for (int i = 1; i <= n; i++) {
			printf("%d ", result[i]);
		}
	}
	else {
		// Cycle이 생겨서 중간에 끝나버린 케이스
		cout << "IMPOSSIBLE";
	}
	cout << endl;
	return;
}

int main() {
	int testcase = 0;
	cin >> testcase;

	while (testcase-- != 0) {
		// 초기화
		memset(indegree, 0, sizeof(int)*502);
		memset(result, 0, sizeof(int)*502);
		memset(prev_rank, 0, sizeof(int) * 502);
		for (int i = 0; i < 502; i++) {
			memset(team[i], 0, sizeof(int) * 502);
		}
		
		cin >> n;
		arrange_prev_rank();	// 지난 등수 정리
		
		// 이번 등수 추가
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

		// 새로운 등수 확인
		arrange_result_rank();
	}

	return 0;
}
