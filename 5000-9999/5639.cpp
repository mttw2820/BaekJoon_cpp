//BaekJoon_5639
//이진 검색 트리
/*
* 제한 시간 : 1s
* 정답 비율 : 38.195%
*/

#include <iostream>
using namespace std;
#define MAX 10001

void postOrder(int* tree, int root) {
	if (tree[root]) {
		postOrder(tree, root * 2);
		postOrder(tree, root * 2 + 1);
		cout << tree[root] << endl;
	}
}

int main() {
	int tree[MAX];
	int temp = 0;  int root = 1; int child = 2;
	int count = 0;

	while (cin >> temp) {
		if (root == 1) tree[root] = temp;
		else if (tree[root] > temp) {
			child = root * 2;
			tree[child] = temp;
			root = child;
		}
		else if (tree[root] < temp) {
			child = (root * 2) + 1;
			tree[child] = temp;
			root = root / 2;
		}
		count++;
	}

	postOrder(tree, 1);


	return 0;
}