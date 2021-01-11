#include <iostream>
using namespace std;

long long rec[30][60]{ 0, };	//중복계산 방지용(시간초과 방지)

long long msg(int w, int h) {
	//1. 남은 것이 전부 반개일 경우 앞으로는 H만 출력 : 경우의 수 1개
	if (w == 0)
		rec[w][h] = 1;
	//2. 반개가 하나도 없을 경우 다음에는 W를 출력한다.
	else if (h == 0) {
		if (rec[w - 1][h + 1] != 0)
			rec[w][h] = rec[w - 1][h + 1];
		rec[w][h] = msg(w - 1, h + 1);
	}
	//3. 반개를 먹거나 한개를 먹고 넣거나
	else {
		if (rec[w][h - 1] == 0) rec[w][h - 1] = msg(w, h - 1);
		if (rec[w - 1][h + 1] == 0) rec[w - 1][h + 1] = msg(w - 1, h + 1);
		rec[w][h] = rec[w][h - 1] + rec[w - 1][h + 1];
	}
	return rec[w][h];
}

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		cout << msg(n, 0) << endl;
	}
	return 0;
}