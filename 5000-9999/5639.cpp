//BaekJoon_5639
//���� �˻� Ʈ��
/*
* ���� �ð� : 1s
* ���� ���� : 41.194%
*/

#include <iostream>
using namespace std;

struct node {
	int num;
	node* left = NULL;
	node* right = NULL;
};

node* tree = NULL;

void make_bst(int now) {
	node *new_node = (node*)malloc(sizeof(node));
	new_node->num = now;
	new_node->left = NULL;
	new_node->right = NULL;
	
	if (tree == NULL)
		tree = new_node;
	else {
		node* move = tree;
		// ��ġ���� �̵�
		while (true) {
			if (move->num < now) {
				if (move->right != NULL) move = move->right;
				else {
					move->right = new_node;
					return;
				}
			}
			else {
				if (move->left != NULL)	move = move->left;
				else {
					move->left = new_node;
					return;
				}
			}
		}
	}
}

void postorder(node* n) {
	if (n == NULL) return;
	postorder(n->left);
	postorder(n->right);
	printf("%d\n", n->num);
	return;
}

int main() {
	int temp;
	while (cin >> temp) {
		make_bst(temp);
	}

	postorder(tree);
	
	return 0;
}