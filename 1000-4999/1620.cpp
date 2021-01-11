//BaekJoon_1620
//���¾� ���ϸ� ������ �̴ټ�
/*
* ���� �ð� : 2s
* ���� ���� : 29.000%
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<string> numbering_pok;			// ��ȣ�� ����� ����� ����
	vector<pair<string, int>> string_pok;	// �̸����� ����� ����� ����
	int poketmon_number, question_number; char poketmon[22];
	cin >> poketmon_number >> question_number;
	for (int i = 1; i <= poketmon_number; i++){
		scanf("%s", poketmon);
		numbering_pok.push_back(poketmon);
		string_pok.push_back(make_pair(poketmon, i));
	}
	sort(string_pok.begin(), string_pok.end());	// ������ �迭
	
	char question[22];
	for (int i = 0; i < question_number; i++) {
		scanf("%s", question);
		int num = question[0] - '0';
		// ��ȣ -> �̸��� ����� ���
		if (num > 0 && num <= 9) {
			int number = stoi(question);
			printf("%s\n", numbering_pok[number - 1].c_str());
		}
		else {	// �̸� -> ��ȣ�� ����� ���
			// �̺� Ž������ �ش� �̸��� ��ġ�� ã�´�.
			int left = 0, right = poketmon_number - 1;
			while (left<=right) {
				int mid = (left + right) / 2;
				if (string_pok[mid].first == question) {
					// ����
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