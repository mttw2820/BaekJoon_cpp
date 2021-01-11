//BaekJoon_15903
//카드 합체 놀이
/*
* 제한 시간 : 1s
* 정답 비율 : 40.606%
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	long long score = 0;
	scanf("%d %d", &n, &m);
	vector<long long> card(n);
	for (int i = 0; i < n; i++) {
		scanf("%ld", &card[i]);
	}

	for (int i = 0; i < m; i++) {
		sort(card.begin(), card.end());
		long long sum = card[0] + card[1];
		card[0] = sum;
		card[1] = sum;
	}
	for (int i = 0; i < n; i++)
		score += card[i];
	printf("%ld\n", score);
	return 0;
}