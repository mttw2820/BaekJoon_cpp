//BaekJoon_2146
//다리 만들기
/*
* 제한 시간 : 2s
* 정답 비율 : 32.725%
*/

#include <iostream>
#include <queue>
using namespace std;

int n;
int map[100][100] = { 0, };
int	check[100][100] = { 0, };
int d_x[] = { 1, -1, 0, 0 };
int d_y[] = { 0, 0, 1, -1 };

// DFS로 섬에 번호를 붙인다
void dfs(int x, int y, int island_number) {
	check[x][y] = -1;
	map[x][y] = island_number;

	int n_x = 0, n_y = 0;
	for (int i = 0; i < 4; i++) {
		n_x = x + d_x[i];
		n_y = y + d_y[i];
		if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= n) continue;
		if (check[n_x][n_y] == 0 && map[n_x][n_y] == 1)
			dfs(n_x, n_y, island_number);
	}

	return;
}

int bfs(int island_number) {
	int bridge = 0;
	queue<pair<int, int>> Q;

	// 해당 섬을 모두 Q에 push
	// 동시에 check 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = 0;
			if (map[i][j] == island_number){
				Q.push(make_pair(i, j));
				check[i][j] = -1;
			}
		}
	}

	// 한칸씩 나아가면서 다른 섬에 도착했는지 확인
	int x = 0, y = 0, n_x = 0, n_y = 0;
	while (!Q.empty()) {
		int qsize = Q.size();
		for (int k = 0; k < qsize; k++) {
			x = Q.front().first;
			y = Q.front().second;
			Q.pop();
			
			for (int i = 0; i < 4; i++) {
				n_x = x + d_x[i];
				n_y = y + d_y[i];
				if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= n) continue;

				// 다른 섬에 도착한 경우
				if (map[n_x][n_y] != 0 && map[n_x][n_y] != island_number) 
					return bridge;

				// 아직 바다인 경우
				if (check[n_x][n_y] != -1 && map[n_x][n_y] == 0) {
					check[n_x][n_y] = -1;
					Q.push(make_pair(n_x, n_y));
				}
			}
		}
		bridge++;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	// dfs 섬 번호 붙이기
	int island_number = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0 && map[i][j] != 0)
				dfs(i, j, island_number++);
		}
	}

	// bfs로 각 섬에서 다른 섬까지 최소 거리 구하기
	int min_bridge = 10000;
	for (int i = 1; i < island_number; i++) {
		int new_bridge = bfs(i);
		if (min_bridge > new_bridge)
			min_bridge = new_bridge;
	}

	cout << min_bridge << endl;
	return 0;
}