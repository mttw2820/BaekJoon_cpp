//BaekJoon_2164
//카드2
/*
* 제한 시간 : 2s
* 정답 비율 : 57.554%
*/

#include <iostream>
#include <queue>		
using namespace std;

/* vector의 erase와 push_back 메소드를 여러번 반복 -> 시간 초과
 * queue의 push, pop이 훨씬 빠르다
 */

int main() {
	queue<int> card[2];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		card[0].push(i);
	}

	int first = 0;	// 현재 앞을 나타내는 벡터
	while (card[0].size() + card[1].size() > 1) {
		card[first].pop();
		// 다음에 넘길 카드가 없다면
		if (card[first].size() == 0) first = 1 - first;
		card[1 - first].push(card[first].front());
		card[first].pop();
		// 다음에 넘길 카드가 없다면
		if (card[first].size() == 0) first = 1 - first;
	}

	if (card[0].size() == 1) first = 0;
	else first = 1;
	printf("%d\n", card[first].front());

	return 0;
}