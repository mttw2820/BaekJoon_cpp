//BaekJoon_10039
//��� ����
/*
* ���� �ð� : 1s
* ���� ���� : 66.835%
*/

#include <iostream>
using namespace std;

int main() {
	int average = 0, score = 0;
	for (int i = 0; i < 5; i++) {
		cin >> score;
		if (score < 40) score = 40;
		average += score;
	}
	average /= 5;
	printf("%d\n", average);

	return 0;
}