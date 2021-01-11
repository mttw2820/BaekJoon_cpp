//BaekJoon_15663
//N과 M (9)
/*
* 제한 시간 : 1s
* 정답 비율 : 47.230%
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void rec_seq(vector<int> vec, vector<int> seq, int size);
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
	rec_seq(vec, seq, m);

	return 0;
}

void rec_seq(vector<int> vec, vector<int> seq, int size) {
	if (size == 0) {
		print_seq(seq);
		return;
	}
	for (int i = 0; i < vec.size(); i++) {
		int temp = vec[i];
		if (i > 0 && temp == vec[i - 1]) continue;
		seq.push_back(temp);
		vec.erase(vec.begin() + i);
		rec_seq(vec, seq, size - 1);
		vec.insert(vec.begin() + i, temp);
		seq.pop_back();
	}
	return;
}

void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
}