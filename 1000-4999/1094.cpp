//BaekJoon_1094
//막대기
/*
* 제한 시간 : 2s
* 정답 비율 : 73.431%
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int x;
	scanf("%d", &x);
	if (x == 64) {
		printf("1\n");
		return 0;
	}
	vector<int> v;
	v.push_back(64);

	int end, cut, sum = 0;
	while (true) {
		end = v[v.size() - 1];
		cut = end / 2;
		v.erase(v.end() - 1);
		v.push_back(cut);
		sum = 0;
		for (int i = 0; i < (int)v.size(); i++) {
			sum += v[i];
		}
		if (sum < x)
			v.push_back(cut);
		else if (sum == x) {
			break;
		}
	}
	printf("%d\n", v.size());
	return 0;
}