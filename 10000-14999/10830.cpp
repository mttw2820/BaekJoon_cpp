//BaekJoon_10830
//행렬 제곱
/*
* 제한 시간 : 1s
* 정답 비율 : 35.524%
*/

#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr(30);

vector<long long> mult_arr(vector<long long> arr1, vector<long long> arr2, int a) {
	vector<long long> temp(30);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			temp[i*a + j] = 0;
			for (int k = 0; k < a; k++) {
				temp[i*a + j] += (arr1[i*a + k] % 1000) * (arr2[k*a + j] % 1000) % 1000;
			}
			temp[i*a + j]%=1000;
		}
	}
	return temp;
}
vector<long long> calc(int a, long long b) {
	if (b == 1) return arr;
	else if (b % 2 == 0) {
		vector<long long> temp = calc(a, b / 2);
		return mult_arr(temp, temp, a);
	}
	else {
		return mult_arr(arr, calc(a, b - 1), a);
	}
}
int main() {
	int a; long long b;
	scanf("%d %lld", &a, &b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cin >> arr[i*a+j];
		}
	}
	vector<long long> ans = calc(a, b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			printf("%lld ", ans[i*a + j]%1000);
		}
		printf("\n");
	}
	return 0;
}