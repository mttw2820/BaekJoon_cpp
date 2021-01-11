//BaekJoon_10775
//����
/*
* ���� �ð� : 1s
* ���� ���� : 40.530%
*/

#include <iostream>
#include <map>
using namespace std;

int find_root(map<int, int> &m, int p) {
	if (m.count(p) == 0) return p;
	else if (m[p] == 0) return 0;
	else return m[p] = find_root(m, m[p]);
}
int main() {
	map<int, int> dock;
	int gate, airplane, port, ans = 0;
	bool flag = false;
	scanf("%d %d", &gate, &airplane);

	for (int i = 0; i < airplane; i++) {
		scanf("%d", &port);
		if (flag) continue;
		if (dock.count(port) == 0) {
			// ó�� ��ŷ �õ�
			dock[port] = port - 1;
		}
		else {
			// �̹� ��ŷ�� ���
			int root = find_root(dock, port);
			if (root == 0) {
				ans = i;
				flag = true;
			}
			else dock[root] = root - 1;
		}
	}
	if (!flag) ans = airplane;

	printf("%d\n", ans);

	return 0;
}