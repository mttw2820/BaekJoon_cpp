//BaekJoon_15656
//N과 M (7)
/*
* 제한 시간 : 1s
* 정답 비율 : 79.409%
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void rec_seq(vector<int>, vector<int>, int);
void print_seq(vector<int>);

int main() {
	int n, m, temp;
	vector<int> nums;
	vector<int> seq;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums.push_back(temp);
	}
	sort(nums.begin(), nums.end());
	rec_seq(nums, seq, m);

	return 0;
}

void rec_seq(vector<int> nums, vector<int> seq, int size) {
	if (size == 0) {
		print_seq(seq);
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		seq.push_back(nums[i]);
		rec_seq(nums, seq, size - 1);
		seq.pop_back();
	}
	return;
}

void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
	return;
}