//BaekJoon_4195
//ģ�� ��Ʈ��ũ
/*
* ���� �ð� : 3s
* ���� ���� : 27.305%
*/

#include <iostream>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int parent[200010] = { 0, };	// root ����
int net_size[200010] = { 0, };	// root��忡 ��Ʈ��ũ�� ����� �����Ѵ�.

int find_root(int node) {
	if (parent[node] == 0) return node;
	else {
		return parent[node] = find_root(parent[node]);
	}
}

void network_union(int root_a, int root_b) {
	parent[root_b] = root_a;
	net_size[root_a] += net_size[root_b];
}
int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		map<string, int> ppl;
		int rel;
		char str_a[25], str_b[25];
		scanf("%d", &rel);
		memset(parent, 0, sizeof(parent));
		memset(net_size, 0, sizeof(net_size));

		for (int i = 0, j = 1; i < rel; i++) {
			scanf("%s %s", str_a, str_b);
			// ��Ʈ��ũ �� �����ϴ��� Ȯ��
			if (ppl.count(str_a) == 0) {
				net_size[j] = 1;
				ppl[str_a] = j++;
			}
			if (ppl.count(str_b) == 0) {
				net_size[j] = 1;
				ppl[str_b] = j++;
			}

			int a = ppl[str_a];
			int b = ppl[str_b];
			// ��Ʈ��ũ ��ġ��
			int ra = find_root(a);
			int rb = find_root(b);
			if (ra != rb) network_union(ra, rb);
			printf("%d\n", net_size[ra]);
		}

	}


	return 0;
}