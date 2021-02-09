//BaekJoon_4344
//평균은 넘겠지
/*
* 제한 시간 : 1s
* 정답 비율 : 37.451%
*/

#include <iostream>
#include <vector>
using namespace std;


vector <float> answer;
int main() {
	int ts;
	cin >> ts;
	for (int i = 0; i < ts; i++) {
		int student, E = 0, overE = 0;
		int score[1001];
		cin >> student;
		for (int j = 0; j < student; j++) {
			cin >> score[j];
			E += score[j];
		}
		E /= student;
		for (int j = 0; j < student; j++) {
			if (score[j] > E) overE++;
		}
		float s = (float)overE / (float)student;
		s *= 100;
		answer.push_back(s);
	}

	for (int i = 0; i < ts; i++) {
		printf("%.3f%%\n", answer[i]);
	}

	return 0;
}