//BaekJoon_15664
//N과 M (10)
/*
* 제한 시간 : 1s
* 정답 비율 : 79.757%
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
	rec_seq(vec, seq, 0, m);

	return 0;
}

void rec_seq(vector<int> vec, vector<int> seq, int prev, int size) {
	if (size == 0) {
		print_seq(seq);
		return;
	}
	int comp = -1;
	for (int i = prev; i < vec.size(); i++) {
		int temp = vec[i];
		if (i > 0 && temp == comp) continue;
		seq.push_back(temp);
		rec_seq(vec, seq, i+1, size - 1);
		seq.pop_back();
		comp = temp;
	}
	return;
}

void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
}