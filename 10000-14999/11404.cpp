//BaekJoon_11404
//플로이드
/*
* 제한 시간 : 1s
* 정답 비율 : 45.763%
*/

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 99999999	// 충분히 크게 잡기

int n, m;
long long dist[110][110] = { 0, };

/* Floyd Warshall */
void FW() {
	for (int k = 1; k <= n; k++) {	// 경유하는 도시
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// city(i)에서 city(j)로 가는 거리
				if (i == j) continue;

				// i -> k -> j 과 i -> j 거리 비교
				if (dist[i][k] != INF && dist[k][j] != INF) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;
	}
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (dist[a][b] > c)
			dist[a][b] = c;
	}

	FW();

	return 0;
}