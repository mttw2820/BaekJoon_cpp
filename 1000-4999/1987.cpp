//BaekJoon_1987
//���ĺ�
/*
* ���� �ð� : 2s
* ���� ���� : 31.001%
*/

#include <iostream>
using namespace std;

char map[25][25];
int alpha[27] = { 0, };

int r, c;
int max_cnt = 0;
int m_x[] = { 0, 0, 1, -1 };
int m_y[] = { 1, -1, 0, 0 };

//parameter) ���� ��ġ, �̵� ĭ��, �̵����, ���ĺ����
void moveDFS(int x, int y, int cnt) {

	//��� ����
	if (cnt > max_cnt) max_cnt = cnt;

	//�̵� ���� ��ġ ��� �����̱�
	//�̵� ���� = ������ ���� ���ĺ�
	for (int i = 0; i < 4; i++) {
		int n_x = x + m_x[i];
		int n_y = y + m_y[i];
		if (n_x >= 0 && n_x < r && n_y >= 0 && n_y < c) {
			int next = map[n_x][n_y] - 'A';
			if (!alpha[next]) {
				alpha[next]++;
				moveDFS(n_x, n_y, cnt+1);
				alpha[next]--;
			}
		}
	}
}

int main() {
	int trace[25][25];
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
	}

	alpha[map[0][0] - 'A']++;
	moveDFS(0, 0, 1);
	cout << max_cnt << endl;

	return 0;
}