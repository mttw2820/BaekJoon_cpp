//BaekJoon_1620
//나는야 포켓몬 마스터 이다솜
/*
* 제한 시간 : 2s
* 정답 비율 : 29.000%
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<string> numbering_pok;			// 번호로 물어볼때 사용할 벡터
	vector<pair<string, int>> string_pok;	// 이름으로 물어볼때 사용할 벡터
	int poketmon_number, question_number; char poketmon[22];
	cin >> poketmon_number >> question_number;
	for (int i = 1; i <= poketmon_number; i++){
		scanf("%s", poketmon);
		numbering_pok.push_back(poketmon);
		string_pok.push_back(make_pair(poketmon, i));
	}
	sort(string_pok.begin(), string_pok.end());	// 사전순 배열
	
	char question[22];
	for (int i = 0; i < question_number; i++) {
		scanf("%s", question);
		int num = question[0] - '0';
		// 번호 -> 이름을 물어보는 경우
		if (num > 0 && num <= 9) {
			int number = stoi(question);
			printf("%s\n", numbering_pok[number - 1].c_str());
		}
		else {	// 이름 -> 번호를 물어보는 경우
			// 이분 탐색으로 해당 이름의 위치를 찾는다.
			int left = 0, right = poketmon_number - 1;
			while (left<=right) {
				int mid = (left + right) / 2;
				if (string_pok[mid].first == question) {
					// 정답
					printf("%d\n", string_pok[mid].second);
					break;
				}
				if (string_pok[mid].first < question) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}
	}

	return 0;
}