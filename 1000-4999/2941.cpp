//BaekJoon_2941
//크로아티아 알파벳
/*
* 제한 시간 : 1s
* 정답 비율 : 46.987%
*/

#include <iostream>
#include <string>
using namespace std;

char first[] = { 'c', 'c', 'd', 'd', 'l', 'n', 's', 'z' };
char second[] = { '=', '-', 'z', '-', 'j', 'j', '=', '=' };

int main() {
	string cro;
	int cnt = 0;
	cin >> cro;
	for (int i = 0; i < cro.length(); i++) {
		cnt++;
		for (int j = 0; j < 8; j++) {
			if (cro[i] == first[j] && cro[i+1] == second[j]) {
				if (j == 2) {
					if(cro[i+2]=='=') i += 2;
				}
				else i += 1;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}