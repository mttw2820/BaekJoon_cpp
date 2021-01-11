//BaekJoon_1068
//Ʈ��
/*
* ���� �ð� : 2s
* ���� ���� : 25.656%
*/

#include <iostream>
#include <vector>
using namespace std;

int check_leaf_dfs(vector<int> tree[50], int d_n, int now) {
	// leaf node �� ���
	if (tree[now].size() == 0 || (tree[now].size() == 1 && tree[now][0] == d_n))
		return 1;

	// child�� �ִ� ���
	int cnt = 0;
	for (int i = 0; i < tree[now].size(); i++) {
		if(tree[now][i] != d_n)
			cnt += check_leaf_dfs(tree, d_n, tree[now][i]);
	}
	
	return cnt;
}
int main() {
	int n, root = 0, parent, delete_node;
	vector<int> tree[50];	// tree[i]�� i����� �ڽ� ��带 push�Ѵ�
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &parent);
		if (parent == -1) {
			root = i;
		}
		else {
			tree[parent].push_back(i);
		}
	}

	scanf("%d", &delete_node);
	if (delete_node == root) printf("0\n");
	else {
		printf("%d\n", check_leaf_dfs(tree, delete_node, root));
	}

	return 0;
}