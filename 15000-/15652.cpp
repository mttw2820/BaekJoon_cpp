//BaekJoon_15652
//N과 M (4)
/*
* 제한 시간 : 1s
* 정답 비율 : 84.198%
*/

#include <iostream>
using namespace std;
#include <vector>

void rec_seq(vector<int>, int, int, int);
void print_seq(vector<int>);

int main() {
	int n, m;
	vector<int> vec;
	cin >> n >> m;

	rec_seq(vec, 1, n, m);
	return 0;
}

void rec_seq(vector<int> seq, int prev, int n, int size) {
	if (size == 0) {
		print_seq(seq);
		return;
	}
	for (int i = prev; i <= n; i++) {
		seq.push_back(i);
		rec_seq(seq, i, n, size - 1);
		seq.pop_back();
	}
}

void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
}