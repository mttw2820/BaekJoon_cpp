//BaekJoon_2697
//숨바꼭직
/*
* 제한 시간 : 2s
* 정답 비율 : 24.933%
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int bin, sis;
	cin >> bin >> sis;
	int way[200001] = { 0 };
	bool visit[200001];
	queue <int> q;

	visit[bin] = false;
	way[bin] = 0;
	q.push(bin);
	while (visit[sis]) {
		int now = q.front();
		q.pop();

		if (visit[now - 1] == true && (now - 1) > 0) {
			visit[now - 1] = false;
			way[now - 1] = way[now] + 1;
			q.push(now - 1);
		}
		if (visit[now + 1] == true) {
			visit[now + 1] = false;
			way[now + 1] = way[now] + 1;
			q.push(now + 1);
		}
		if (visit[now * 2] == true && now * 2 < sis * 2) {
			visit[now * 2] = false;
			way[now * 2] = way[now + 1];
			q.push(now * 2);
		}
	}

	cout << way[sis] << endl;

	return 0;
}