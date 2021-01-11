#include <iostream>
using namespace std;
#include <vector>

int num;
char m[6600][6600];

void getBlank(int x, int y, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m[x + i][y + j] = ' ';
		}
	}
}
void getStar(int x, int y, int size) {
	if (size == 1) {
		m[x][y] = '*';
		return;
	}
	size /= 3;
	getStar(x, y, size);
	getStar(x + size, y, size);
	getStar(x + size * 2, y, size);
	getStar(x, y + size, size);
	getBlank(x + size, y + size, size);
	getStar(x + size * 2, y + size, size);
	getStar(x, y + size * 2, size);
	getStar(x + size, y + size * 2, size);
	getStar(x + size * 2, y + size * 2, size);
	return;
}

int main() {
	cin >> num;
	
	getStar(0, 0, num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%c", m[i][j]);
		}
		printf("\n");
	}

	return 0;
}