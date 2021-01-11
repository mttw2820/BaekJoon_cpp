//BaekJoon_9466
//텀 프로젝트
/*
* 제한 시간 : 3s
* 정답 비율 : 24.414%
*/

#include <iostream>
using namespace std;

int students[100001] = { 0, };
int check[100001] = { 0, };	//사이클 -1
int n;

void make_team(int now, int cnt) {
	int next = students[now];

	if (check[next] == 0) {	// 첫 방문
		check[now] = cnt;
		make_team(next, cnt);
	}
	else {	// 방문 기록 있는 경우
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

		// 프로젝트 팀을 이루는 학생들의 수 count
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