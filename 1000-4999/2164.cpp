//BaekJoon_2164
//ī��2
/*
* ���� �ð� : 2s
* ���� ���� : 57.554%
*/

#include <iostream>
#include <queue>		
using namespace std;

/* vector�� erase�� push_back �޼ҵ带 ������ �ݺ� -> �ð� �ʰ�
 * queue�� push, pop�� �ξ� ������
 */

int main() {
	queue<int> card[2];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		card[0].push(i);
	}

	int first = 0;	// ���� ���� ��Ÿ���� ����
	while (card[0].size() + card[1].size() > 1) {
		card[first].pop();
		// ������ �ѱ� ī�尡 ���ٸ�
		if (card[first].size() == 0) first = 1 - first;
		card[1 - first].push(card[first].front());
		card[first].pop();
		// ������ �ѱ� ī�尡 ���ٸ�
		if (card[first].size() == 0) first = 1 - first;
	}

	if (card[0].size() == 1) first = 0;
	else first = 1;
	printf("%d\n", card[first].front());

	return 0;
}