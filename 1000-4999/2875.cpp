#include <iostream>
using namespace std;

// 그리디 알고리즘 사용
// 여2 남1의 조합으로 팀 구성
// (K-남은 학생 수) 에서 3씩 빼서 0이 되게 하고
// 3명을 뺄때마다 팀은 1개 덜 구성된다.
int main() {
	int n, m, k;
	int cnt = 0;
	cin >> n >> m >> k;
	while (n >= 2 && m >= 1) {
		n -= 2;		m--;
		cnt++;
	}
	k -= (n + m);
	while (k > 0) {
		k -= 3;
		cnt--;
	}
	cout << cnt << endl;

	return 0;
}