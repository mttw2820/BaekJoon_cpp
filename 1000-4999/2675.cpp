//BaekJoon_2675
//���ڿ� �ݺ�
/*
* ���� �ð� : 1s
* ���� ���� : 54.026%
*/

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int testcase = 0;
	cin >> testcase;

	while (testcase != 0) {
		int repeat = 0;
		char str[1001];
		cin >> repeat >> str;

		for (int i = 0; i < strlen(str); i++) {
			for (int j = 0; j < repeat; j++)
				printf("%c", str[i]);
		}
		cout << endl;
		testcase--;
	}

	return 0;
}