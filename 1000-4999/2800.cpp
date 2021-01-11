//BaekJoon_2800
//괄호 제거
/*
* 제한 시간 : 1s
* 정답 비율 : 30.748%
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <bitset>
using namespace std;

bitset<201> make_binary_code(int remove_number, vector<pair<int, int>>  br_index) {
	// 삭제할 괄호 위치에 1을 넣는 함수
	bitset<201> binary = 0;
	for (int i = 0; remove_number != 0; i++) {
		if (remove_number & 1) {
			bitset<201> new_b;
			// 아래 연산 시 1이 int이기 때문에 오버플로우 발생 가능
			// new_b = (1<<br_index[i].first)  | (1<<br_index[i].second)
			new_b[br_index[i].first] = new_b[br_index[i].second] = 1;
			binary = binary | new_b;
		}
		remove_number = remove_number >> 1;
	}
	return binary;
}

string make_str(char str[], bitset<201> remove_code, int len) {
	string ans;
	int i = 0;
	for (i = 0; i < len; i++) {
		// 삭제할 인덱스는 1로 표시되어 출력 X
		if (!(remove_code[0] & 1))
			ans += str[i];
		remove_code = remove_code >> 1;
	}
	return ans;
}

int main() {
	stack<int> st_br;	// 괄호 쌍을 찾기 위한 스택
	vector<pair<int, int>> br_index; // 괄호 쌍의 인덱스
	vector<string> ans;
	char str[201];
	scanf("%s", str);
	int len = strlen(str);

	// 괄호 쌍 찾기
	int cnt_br = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') st_br.push(i);
		else if (str[i] == ')') {
			cnt_br = (cnt_br << 1) + 1;
			br_index.push_back(make_pair(st_br.top(), i));
			st_br.pop();
		}
	}

	for (int i = 1; i <= cnt_br; i++) {
		bitset<201> bin = make_binary_code(i, br_index);	
		ans.push_back(make_str(str, bin, len));
	}

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (string s : ans)
		printf("%s\n", s.c_str());
	
	return 0;
}