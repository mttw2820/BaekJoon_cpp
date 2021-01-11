//BaekJoon_1717
//������ ǥ��
/*
* ���� �ð� : 2s
* ���� ���� : 30.082%
*/

#include <iostream>
using namespace std;

int parent[1000001] = { 0, };
int find_root(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find_root(parent[a]);
	}
}

int comp_set(int a, int b) {
	int set_a = find_root(a);
	int set_b = find_root(b);
	if (set_a == set_b) return 0;
	else return -1;
}
void union_set(int a, int b) {
	if (comp_set(a, b) == 0) return;	// �̹� ���� ����

	int root_a = find_root(a);
	int root_b = find_root(b);
	// ��ġ��
	parent[root_b] = root_a;
	return;
}
int main() {
	int n, m, op, a, b;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n+1; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &op, &a, &b);
		if (op == 0) {
			// UNION
			union_set(a, b);
		}
		else {
			//FIND
			int comp = comp_set(a, b);
			if (comp == 0)	// ���� ����
				printf("YES\n");
			else printf("NO\n");	// �ٸ� ����
		}
	}

	return 0;
}