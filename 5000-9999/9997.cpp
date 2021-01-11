#include <iostream>
#include <cstring>
#include <vector>
#define MAX 67108863
using namespace std;


int getBinary(char voca[]) {
	// 문자열을 포함하는 알파벳 비트로 변환
	int len = strlen(voca);
	int binary = 0;
	for (int i = 0; i < len; i++) {
		binary = binary | (1 << (voca[i] - 'a'));
	}
	return binary;
}

void set_next_combine(bool visit[], int now, int n) {
	for (int i = 0; i < n; i++) {
		if (!(now & (1 << i))) {
			int next = now | (1 << i);
			if (!visit[next]) {
				set_next_combine(visit, next, n);
				visit[next] = true;
			}
		}
	}
	return;
}

bool combine(int dic[], int comb) {
	// 문자열의 조합을 만들어서 알파벳 확인
	int alpha = 0;
	bool flag = false;
	for (int i = 0; comb != 0; i++) {
		if (comb & 1) {
			alpha = alpha | dic[i];
			if (alpha == MAX) {
				flag = true;
				break;
			}
		}
		comb = comb >> 1;
	}
	if (alpha == MAX) flag = true;
	return flag;
}


int main() {
	int N, cnt = 0;
	char voca[101];
	int dic[30] = { 0, };
	scanf("%d", &N);
 	for (int i = 0; i < N; i++) {
		scanf("%s", voca);
		dic[i] = getBinary(voca);
	}

	int comb = (1 << N);
	bool *visit = new bool[comb];
	for (int i = 0; i < comb; i++) {
		if (visit[i] == true) cnt++;
		else if (combine(dic, i)) {
			visit[i] = true;
			cnt++;
			set_next_combine(visit, i, N);
		}
	}
	printf("%d\n", cnt);

	return 0;
}