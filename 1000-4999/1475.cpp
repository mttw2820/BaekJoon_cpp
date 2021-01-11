//BaekJoon_1475
//방 번호
/* 시간 제한 : 2s 
 * 정답 비율 : 38.888%
 */
#include <iostream>
using namespace std;
#include <string.h>

int main() {
	char str[8] = { 0, };
	cin >> str;

	int cnt = 0;
	int check[10] = { 0, };
	for (int i = 0; str[i] != NULL; i++) {
		if (str[i] == '9')
			check[6]++;
		check[str[i]-'0']++;
	}
	check[6] = check[6] / 2 + check[6] % 2;

	for (int i = 0; i < 9; i++) {
		if (check[i] > cnt) cnt = check[i];
	}
	cout << cnt << endl;
	
	return 0;
}