#include <iostream>
using namespace std;

// �׸��� �˰��� ���
// ��2 ��1�� �������� �� ����
// (K-���� �л� ��) ���� 3�� ���� 0�� �ǰ� �ϰ�
// 3���� �������� ���� 1�� �� �����ȴ�.
int main() {
	int n, m, k;
	int cnt = 0;
	cin >> n >> m >> k;
	while (n >= 2 && m >= 1) {
		n -= 2;		m--;
		cnt++;
	}
	k -= (n + m);
	while (k > 0) {
		k -= 3;
		cnt--;
	}
	cout << cnt << endl;

	return 0;
}