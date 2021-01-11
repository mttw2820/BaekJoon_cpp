//BaekJoon_7568
//덩치
/*
* 제한 시간 : 1s
* 정답 비율 : 60.356%
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ppl {
	int weight;
	int height;
	int number;
	int rank = 1;
};
vector<ppl> vec;


bool sort_weight(ppl p1, ppl p2) {
	return p1.weight < p2.weight;
}

bool sort_number(ppl p1, ppl p2) {
	return p1.number < p2.number;
}

int main() {
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ppl newppl;
		newppl.weight = a;
		newppl.height = b;
		newppl.number = i;
		vec.push_back(newppl);
	}
	sort(vec.begin(), vec.end(), sort_weight);	//몸무게 순으로 정렬
	for (int i = 0; i < n; i++) {
		int w = vec[i].weight;
		int h = vec[i].height;
		for (int j = i + 1; j < n; j++) {
			if (w == vec[j].weight) continue;
			if (h >= vec[j].height) continue;
			vec[i].rank++;
		}
	}
	sort(vec.begin(), vec.end(), sort_number);
	for (int i = 0; i < n; i++) {
		cout << vec[i].rank << " ";
	}
	cout << endl;
	return 0;
}
