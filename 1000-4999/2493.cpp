//BaekJoon_2493
//ž
/*
* ���� �ð� : 1.5s
* ���� ���� : 36.348%
*/

#include <iostream>
using namespace std;
#include <stack>
#include <vector>

int main() {
	int n;
	stack <pair<int, int>> left;
	stack <pair<int, int>> right;
	scanf("%d", &n);
	vector<int> get(n, 0);

	pair<int, int> temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp.first);
		temp.second = i;
		left.push(temp);
	}

	while (!left.empty()) {
		pair<int, int> now = left.top();
		left.pop();
		//left���� �ϳ��� pop�ؼ� right�� top�� ���� ��
		while (!right.empty() && right.top().first < now.first) {
			get[right.top().second] = now.second + 1;
			right.pop();
		}
		right.push(now);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", get[i]);
	cout << endl;

	return 0;
}