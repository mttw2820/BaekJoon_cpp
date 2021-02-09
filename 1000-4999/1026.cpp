//BaekJoon_1026
//보물
/*
* 제한 시간 : 2s
* 정답 비율 : 62.318%
*/

#include <iostream>
using namespace std;
#include <cstring>
#define MAX 100

int* SelectionSort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[min])
				min = j;
		}
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
	return list;
}

int main() {

	int N;
	int A[MAX], B[MAX];
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int j = 0; j < N; j++)
		cin >> B[j];

	int copy[MAX];
	for (int n=0; n < N; n++) copy[n] = B[n];

	SelectionSort(A, N);
	SelectionSort(copy, N);

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += (A[i] * copy[N-i-1]);
	}

	cout << answer << endl;

	return 0;
}

