//BaekJoon_15654
//N과 M (5)
/*
* 제한 시간 : 1s
* 정답 비율 : 76.219%
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void rec_seq(vector<int> nums, vector<int> seq, int size);
void print_seq(vector<int> seq);

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

void rec_seq(vector<int> nums, vector<int> seq, int size) {
	if (size == 0) {
		print_seq(seq);
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		int temp = nums[i];
		seq.push_back(temp);
		nums.erase(nums.begin() + i);
		rec_seq(nums, seq, size - 1);
		nums.insert(nums.begin() + i, temp);
		seq.pop_back();
	}
}

void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
	return;
}