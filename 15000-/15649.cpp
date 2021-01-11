//BaekJoon_15649
//N�� M (1)
/*
* ���� �ð� : 1s
* ���� ���� : 61.444%
*/

#include <iostream>
using namespace std;
#include <vector>

void rec_seq(vector<int> vec, vector<int> seq, int size);
void print_seq(vector<int> seq);
int main() {
	int n, m;
	vector<int> vec;
	vector<int> seq;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		vec.push_back(i + 1);

	// vec���� ���� ���ں��� ������� ���� ��������� ������ ����� ������.
	rec_seq(vec, seq, m);

	return 0;
}

// �迭�� �̿��ϸ� swap���� ���� �����ϴ�.
// ���������� ���͸� ���°� ���ؼ� �̷��� �����ߴ�.
// n�� m�� Ŀ���� ���� �޼ҵ� �ð����⵵ ���� swap�� �� ���� �ð� �ʰ� ������ �迭�� ���������...
void rec_seq(vector<int> vec, vector<int> seq, int size) {
	if (size == 0) {
		print_seq(seq);
		return;
	}

	for (int i = 0; i < vec.size(); i++) {
		int temp = vec[i];
		seq.push_back(temp);
		vec.erase(vec.begin() + i);
		rec_seq(vec, seq, size - 1);
		vec.insert(vec.begin() + i, temp);
		seq.pop_back();
	}
}

// cin���� �ϸ� �ð��ʰ��� ���´�. ����!
void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
	return;
}