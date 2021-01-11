//BaekJoon_15651
//N과 M (3)
/*
* 제한 시간 : 1s
* 정답 비율 : 67.841%
*/

#include <iostream>
using namespace std;
#include <vector>

void rec_seq(int, int, vector<int>);
void print_seq(vector<int>);

int main() {
	int n, m;
	vector<int> vec;
	cin >> n >> m;
	
	rec_seq(n, m, vec);

	return 0;
}

void rec_seq(int n, int size, vector<int> seq) {
	if (size == 0) {
		print_seq(seq);
		return;
	}
	for (int i = 1; i <= n; i++) {
		seq.push_back(i);
		rec_seq(n, size-1, seq);
		seq.pop_back();
	}
}

void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
}
