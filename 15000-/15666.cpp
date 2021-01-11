//BaekJoon_15666
//N과 M (12)
/*
* 제한 시간 : 1s
* 정답 비율 : 83.636%
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void rec_seq(vector<int> vec, vector<int> seq, int prev, int size);
void print_seq(vector<int>);

int main() {
	int n, m, temp;
	vector<int> vec;
	vector<int> seq;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	// 어차피 같은 수 중복 출력이 가능하기 때문에 미리 중복되는 수를 지우는 편이 실행 속도 측면에서 좋을 것 같다.
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] == vec[i - 1]) {
			vec.erase(vec.begin() + i);
			i--;
		}
	}
	rec_seq(vec, seq, 0, m);

	return 0;
}

void rec_seq(vector<int> vec, vector<int> seq, int prev, int size) {
	if (size == 0) {
		print_seq(seq);
		return;
	}

	for (int i = prev; i < vec.size(); i++) {
		seq.push_back(vec[i]);
		rec_seq(vec, seq, i, size - 1);
		seq.pop_back();
	}
	return;
}

void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
}