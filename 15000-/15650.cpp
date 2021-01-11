//BaekJoon_15650
//N�� M (2)
/*
* ���� �ð� : 1s
* ���� ���� : 78.571%
*/

#include <iostream>
using namespace std;
#include <vector>

void NMseq(vector<int> v, vector<int> seq, int start, int size);
void print_seq(vector<int> seq);

int main() {
	int n, m;
	vector<int> v;
	vector<int> seq;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		v.push_back(i + 1);

	// n�� �� m���� �̿��� �������� ������
	NMseq(v, seq, 0, m);

	return 0;
}

void NMseq(vector<int> v, vector<int> seq, int start, int size) {
	if (size == 0) {
		print_seq(seq);
		return;
	}
	
	for (int i = start; i <= v.size() - size; i++) {
		seq.push_back(v[i]);
		NMseq(v, seq, i + 1, size - 1);
		seq.pop_back();
	}
}

void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
	return;
}