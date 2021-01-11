//BaekJoon_2529
//부등호
/*
* 제한 시간 : 1s
* 정답 비율 : 50.109%
*/

#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
using namespace std;

int k;
priority_queue <int, vector<int>, greater<int>> Q;
vector<int> s_vec[15];	// vec[i] = vec보다 다음으로 채워질 칸
vector<int> b_vec[15];
vector<int> seq(15);



void smallestSeq(int indegree[15]) {
	int cnt = 1;

	int visited[15] = { 0, };

	// indegree == 0 초기화
	for (int i = 0; i <= k; i++) {
		if (indegree[i] == 0)
			Q.push(i);
	}

	while (!Q.empty()) {
		int now = Q.top();
		Q.pop();

		if (visited[now] == -1) continue;
		visited[now] = -1;

		// 결과 넣기
		seq[now] = cnt++;
		// 다음 순서
		int next = 0;
		for (int i = 0; i < s_vec[now].size(); i++) {
			next = s_vec[now][i];
			indegree[next]--;
			if (indegree[next] == 0 && visited[next] == 0)
				Q.push(next);
		}
	}

	// 결과 출력
	for (int i = 0; i <= k; i++) {
		cout << seq[i] - 1;
	}
	cout << endl;

	return;
}

void biggestSeq(int indegree[15]) {
	int cnt = 1;
	int visited[15] = { 0, };

	// indegree == 0 초기화
	for (int i = 0; i <= k; i++) {
		if (indegree[i] == 0)
			Q.push(i);
	}

	while (!Q.empty()) {
		int now = Q.top();
		Q.pop();

		if (visited[now] == -1) continue;
		visited[now] = -1;

		// 결과 넣기
		seq[now] = cnt++;
		// 다음 순서
		int next = 0;
		for (int i = 0; i < b_vec[now].size(); i++) {
			next = b_vec[now][i];
			indegree[next]--;
			if (indegree[next] == 0 && visited[next] == 0)
				Q.push(next);
		}
	}

	// 결과 출력
	for (int i = 0; i <= k; i++) {
		cout << 10 - seq[i];
	}
	cout << endl;

	return;
}

int main() {
	cin >> k;
	string bs;

	int s_in[15] = { 0, };
	int b_in[15] = { 0, };
	for (int i = 0; i < k; i++) {
		cin >> bs;
		if (bs[0] == '<') {
			// 앞에꺼가 작은 케이스
			s_vec[i].push_back(i + 1);
			s_in[i + 1]++;
			b_vec[i + 1].push_back(i);
			b_in[i]++;
		}
		else {
			s_vec[i + 1].push_back(i);
			s_in[i]++;
			b_vec[i].push_back(i + 1);
			b_in[i + 1]++;
		}
	}

	biggestSeq(b_in);
	smallestSeq(s_in);


	return 0;
}