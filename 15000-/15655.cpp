//BaekJoon_15655
//N�� M (6)
/*
* ���� �ð� : 1s
* ���� ���� : 87.929%
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void rec_seq(vector<int> nums, vector<int> seq, int prev, int size);
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

	rec_seq(nums, seq, 0, m);

	return 0;
}

void rec_seq(vector<int> nums, vector<int> seq, int prev, int size) {
	if (size == 0) {
		print_seq(seq);
		return;
	}
	for (int i = prev; i < nums.size(); i++) {
		seq.push_back(nums[i]);
		rec_seq(nums, seq, i+1, size - 1);
		seq.pop_back();
	}
	return;
}

void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
}