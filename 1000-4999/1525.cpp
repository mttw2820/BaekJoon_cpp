//BaekJoon_1525
//퍼즐
/*
* 제한 시간 : 1s
* 정답 비율 : 38.896%
*/

#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
 
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void swap(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
	return;
}

int main() {
	int start = 0, input;
	int dest = 123456789;
	for (int i = 0; i < 9;i++) {
		scanf("%d", &input);
		if (input == 0) input = 9;
		start *= 10;
		start += input;
	}

	map<int, int> m;
	queue<int> q;
	m.insert(make_pair(start, 0));
	q.push(start);
	int ans = -1;
	while (!q.empty()) {
		int now_num = q.front();
		q.pop();
		if (now_num == dest) {
			ans = m[now_num];
			break;
		}
		
		string now = to_string(now_num);
		int blank = now.find('9');
		int x = blank / 3;
		int y = blank % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string next = now;
				swap(next[3 * x + y], next[3 * nx + ny]);
				int next_num = stoi(next);
				if (m.count(next_num) == 0) {
					// 처음 오는 경우라면
					m[next_num] = m[now_num] + 1;
					q.push(next_num);
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}