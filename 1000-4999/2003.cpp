//BaekJoon_2003
//������ �� 2
/*
* ���� �ð� : 0.5s
* ���� ���� : 50.582%
*/


#include <iostream>
using namespace std;

int arr[10001] = { 0, };
int main() {
	int n, cnt = 0;
	long long m;
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int L = 0, R = 0;
	while (R < n) {
		long long sum = 0;
		//���� �� ���ϱ�
		for (int i = L; i <= R; i++) 
			sum += arr[i];
		
		if (sum == m) {
			cnt++;
			R++;
			continue;
		}
		if (sum < m || L >= R) R++;
		else L++;
	}

	cout << cnt << endl;
	return 0;
}