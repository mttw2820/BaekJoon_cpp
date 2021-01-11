//BaekJoon_15649
//N과 M (1)
/*
* 제한 시간 : 1s
* 정답 비율 : 61.444%
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

	// vec에서 작은 숫자부터 순서대로 빼고 재귀적으로 수열을 만들어 나간다.
	rec_seq(vec, seq, m);

	return 0;
}

// 배열을 이용하면 swap으로 구현 가능하다.
// 개인적으로 벡터를 쓰는게 편해서 이렇게 구현했다.
// n과 m이 커지면 벡터 메소드 시간복잡도 보다 swap이 더 빨라서 시간 초과 때문에 배열을 써야할지도...
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

// cin으로 하면 시간초과가 나온다. 조심!
void print_seq(vector<int> seq) {
	for (int i = 0; i < seq.size(); i++)
		printf("%d ", seq[i]);
	printf("\n");
	return;
}