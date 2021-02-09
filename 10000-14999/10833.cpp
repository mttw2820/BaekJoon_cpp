//BaekJoon_10833
//사과
/*
* 제한 시간 : 1s
* 정답 비율 : 82.761%
*/

#include <iostream>
using namespace std;
#define MAX 101

int main()
{
	int N, apple_left = 0;
	int student[MAX], apple[MAX];
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> student[i];
		cin >> apple[i];
		for (int j = 0;; j++) {
			if (student[i] * j > apple[i]) {
				apple_left += apple[i] - student[i] * (j - 1);
				break;
			}
		}
	}
	cout << apple_left << endl;
	

	return 0;
}