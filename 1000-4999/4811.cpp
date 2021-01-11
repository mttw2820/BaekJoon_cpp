#include <iostream>
using namespace std;

long long rec[30][60]{ 0, };	//�ߺ���� ������(�ð��ʰ� ����)

long long msg(int w, int h) {
	//1. ���� ���� ���� �ݰ��� ��� �����δ� H�� ��� : ����� �� 1��
	if (w == 0)
		rec[w][h] = 1;
	//2. �ݰ��� �ϳ��� ���� ��� �������� W�� ����Ѵ�.
	else if (h == 0) {
		if (rec[w - 1][h + 1] != 0)
			rec[w][h] = rec[w - 1][h + 1];
		rec[w][h] = msg(w - 1, h + 1);
	}
	//3. �ݰ��� �԰ų� �Ѱ��� �԰� �ְų�
	else {
		if (rec[w][h - 1] == 0) rec[w][h - 1] = msg(w, h - 1);
		if (rec[w - 1][h + 1] == 0) rec[w - 1][h + 1] = msg(w - 1, h + 1);
		rec[w][h] = rec[w][h - 1] + rec[w - 1][h + 1];
	}
	return rec[w][h];
}

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		cout << msg(n, 0) << endl;
	}
	return 0;
}