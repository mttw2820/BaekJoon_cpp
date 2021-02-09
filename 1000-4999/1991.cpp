//BaekJoon_1991
//트리 순회
/*
* 제한 시간 : 2s
* 정답 비율 : 63.162%
*/

#include <iostream>
using namespace std;
#define MAX 30

typedef struct node* tree_ptr;
struct node {
	char data;
	tree_ptr left;
	tree_ptr right;
};

void preOrder(tree_ptr tree) {
	if (tree) {
		cout << tree->data;
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

void inOrder(tree_ptr tree) {
	if (tree) {
		inOrder(tree->left);
		cout << tree->data;
		inOrder(tree->right);
	}
}

void postOrder(tree_ptr tree) {
	if (tree) {
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->data;
	}
}

int main() {
	struct node Tree[MAX];
	char temp[3];
	int N, root = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp[0] >> temp[1] >> temp[2];
		root = temp[0] - 'A';

		Tree[root].data = temp[0];

		if (temp[1] == '.') {
			Tree[root].left = NULL;
		}
		else {
			Tree[root].left = &Tree[temp[1] - 'A'];
			Tree[temp[1] - 'A'].data = temp[1];
		}
		if (temp[2] == '.') {
			Tree[root].right = NULL;
		}
		else {
			Tree[root].right = &Tree[temp[2] - 'A'];
			Tree[temp[2] - 'A'].data = temp[2];
		}
	}

	preOrder(Tree); cout << endl;
	inOrder(Tree); cout << endl;
	postOrder(Tree); cout << endl;

	return 0;
}