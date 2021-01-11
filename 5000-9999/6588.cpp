//BaekJoon_6588
//골드바흐의 추측
/*
* 제한 시간 : 1s
* 정답 비율 : 26.058%
*/

#include <iostream>
#include <vector>
#include <string.h>
#define MAX 1000000
using namespace std;

bool isPrime[MAX + 1];
vector<int> prime;
void setPrime() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= MAX; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int j = 2; i*j <= MAX; j++) {
				isPrime[i*j] = false;
			}
		}
	}
	return;
}

int main() {
	setPrime();
	int ps = prime.size();
	int num = 0;
	while (true) {
		scanf("%d", &num);
		if (num == 0) break;

		bool notChanged = true;
		for (int i = 0; i < ps; i++) {
			if (prime[i] >= num) break;
			if (isPrime[num - prime[i]]) {
				printf("%d = %d + %d\n", num, prime[i], num - prime[i]);
				notChanged = false;
				break;
			}
		}
		if (notChanged) {
			printf("Goldbach's conjecture is wrong.\n");
		}
	}

	return 0;
}