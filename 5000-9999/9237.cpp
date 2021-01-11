//BaekJoon_9237
//����� �ʴ�
/*
* ���� �ð� : 1s
* ���� ���� : 69.834%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int seed = 0;
long long grow_time[100010] = { 0, };
int main() {
	cin >> seed;
	for (int i = 0; i < seed; i++) {
		scanf("%d", &grow_time[i]);
	}
	sort(grow_time, grow_time + seed);
	for (int i = seed - 1; i >= 0; i--) {
		grow_time[i] += (seed - i);
	}
	sort(grow_time, grow_time + seed);
	cout << 1 + grow_time[seed - 1] << endl;

	return 0;
}