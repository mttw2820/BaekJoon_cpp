//BaekJoon_2002
//추월
/*
* 제한 시간 : 2s
* 정답 비율 : 43.889%
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, cnt=0;
	cin >> n;
	int car[100];
	string in[100];
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			if (temp == in[j]) {
				car[i] = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (car[i] > car[j]) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}