//BaekJoon_15665
//N�� M (11)
/*
* ���� �ð� : 1s
* ���� ���� : 76.049%
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
	// ������ ���� �� �ߺ� ����� �����ϱ� ������ �̸� �ߺ��Ǵ� ���� ����� ���� ���� �ӵ� ���鿡�� ���� �� ����.
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] == vec[i - 1]) {
			vec.erase(vec.begin() + i);
			i--;
		}
	}
	rec_seq(vec, seq, m);

	return 0;
}

void rec_seq(vector<int> vec, vector<int> seq, int size) {
	if (size == 0) {
		print_seq(seq);
		return;
	}
	
	for (int i = 0; i < vec.size(); i++) {
		seq.push_back(vec[i]);
		rec_seq(vec, seq, size - 1);
		seq.pop_back();
	}
	return;
}

void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
}