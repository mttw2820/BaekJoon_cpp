//BaekJoon_1110
//더하기 사이클
/*
* 제한 시간 : 2s
* 정답 비율 : 48.090%
*/

#include <iostream>
using namespace std;

int n;
int cnt = 0;
void cycle(int x, int y) {
	cnt++;
	int temp = (x + y) % 10;
	int check = 10 * y + temp;
	if (check == n) return;
	cycle(y, temp);
}

int main() {
	cin >> n;
	if (n < 10) cycle(0, n);
	else cycle(n / 10, n % 10);
	cout << cnt << endl;
	return 0;
}