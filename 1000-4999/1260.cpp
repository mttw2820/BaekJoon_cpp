//BaekJoon_1260
//DFS와 BFS
/*
* 제한 시간 : 2s
* 정답 비율 : 33.272%
*/

#include <iostream>
using namespace std;
#define MAX 10001

int Graph[MAX][MAX];
int visit[MAX];
int top = 0;
int Q[MAX];
int front = 0; int rear = 0;
void DFS(int start, int size) {
	visit[start] = 1;
	cout << start << " ";

	for (int i = 0; i <= size; i++) {
		if (Graph[start][i] == 1 && visit[i] == 0)
			DFS(i, start);
	}
}

int BFS(int start, int size) {
	


}

int main()
{
	int N, M, start, v1, v2;
	cin >> N >> M >> start;

	visit[0] = start;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		Graph[v1][v2] = Graph[v2][v1] = 1;
	}

	//DFS
	DFS(start, N);
	

	return 0;
}