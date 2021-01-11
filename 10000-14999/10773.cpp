//BaekJoon_10773
//����
/*
* ���� �ð� : 1s
* ���� ���� : 68.600%
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int k;
	cin >> k;
	
	stack<int> st;
	int n = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		if (n == 0) st.pop();
		else st.push(n);
	}

	long long ans = 0;
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	cout << ans << endl;
	return 0;
}