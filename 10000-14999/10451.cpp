//BaekJoon_10451
//순열 사이클
/*
* 제한 시간 : 1s
* 정답 비율 : 63.270%
*/

#include <iostream>
using namespace std;

int cycle = 0;
int perm[1010] = { 0, };
int check[1010] = { 0, };
bool check_cycle(int now, int this_cycle[]) {
	check[now] = -1;
	this_cycle[now] = -1;
	int next = perm[now];

	if (check[next] != 0) {
		// 다음 노드를 확인한적 있는 경우
		if (this_cycle[next] != 0) return true;
		else return false;
	}

	// 온적 없는 노드
	return check_cycle(next, this_cycle);
}
int main() {
	int testcase;
	cin >> testcase;

	while (testcase != 0) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> perm[i];
			check[i] = 0;
		}

		// 모든 점들에 대해서 cycle 탐색
		int small_check[1010] = { 0, };
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0){
				bool is_cycle = check_cycle(i, small_check);
				if (is_cycle) cycle++;
			}
		}
		cout << cycle << endl;
		cycle = 0;
		testcase--;
	}

	return 0;
}