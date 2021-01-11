//BaekJoon_1991
//트리 순회
/*
* 제한 시간 : 2s
* 정답 비율 : 62.977%
*/

#include <iostream>
using namespace std;

// 26개 노드가 skewed 되어있을 경우 배열로 하면 2^26개 필요
// 배열로 하면 공간 낭비가 심할 수 있으니까 인접 리스트 사용

struct node {
	char now = NULL;
	char left = NULL;
	char right = NULL;
};

node tree[30];

void pre_order(node node) {
	printf("%c", node.now);
	if(node.left!=NULL)	pre_order(tree[node.left - 'A']);
	if (node.right!= NULL) pre_order(tree[node.right - 'A']);
	return;
}

void in_order(node node) {
	if (node.left != NULL)	in_order(tree[node.left - 'A']);
	printf("%c", node.now);
	if (node.right != NULL) in_order(tree[node.right - 'A']);
	return;
}

void post_order(node node) {
	if (node.left != NULL)	post_order(tree[node.left - 'A']);
	if (node.right != NULL) post_order(tree[node.right - 'A']);
	printf("%c", node.now);
	return;
}

int main() {
	int n;
	cin >> n;
	char parent = '.', left = '.', right = '.';
	node temp;
	for (int i = 0; i < n; i++) {
		cin >> parent >> left >> right;
		temp.now = parent;
		if (left != '.') temp.left = left;
		else temp.left = NULL;
		if (right != '.') temp.right = right;
		else temp.right = NULL;

		tree[parent - 'A'] = temp;
	}

	pre_order(tree[0]);
	cout << endl;
	in_order(tree[0]);
	cout << endl;
	post_order(tree[0]);
	cout << endl;

	return 0;
}