//BaekJoon_6603
//로또
/*
* 제한 시간 : 1s
* 정답 비율 : 53.609%
*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[]) {
	for (int i = 0; i < 6; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void makeLotto(vector<int> all, int now, int lotto[], int cnt) {
	// all에 남은 개수+cnt == 6 일 경우 이후의 숫자 전부를 lotto에 넣어야한다.
	if (all.size() - now == 6 - cnt) {
		for (int i = now; i < all.size(); i++, cnt++) {
			lotto[cnt] = all[i];
		}
	}
	// 6개의 숫자로 배열이 완성되면 출력한다.
	if (cnt == 6) {
		printArray(lotto);
		return;
	}
	
	// all[now]를 포함하는 배열
	lotto[cnt] = all[now];
	makeLotto(all, now + 1, lotto, cnt + 1);
	// all[now]를 포함하지 않는 배열
	makeLotto(all, now + 1, lotto, cnt);
	return;
}



int main() {
	while (true) {
		int k = 0;
		scanf("%d", &k);
		if (k == 0)	//종료조건
			break;
		vector<int> v(k,0);
		for (int i = 0; i < k; i++) {
			scanf("%d", &v[i]);
		}
		int lotto[7] = { 0, };
		makeLotto(v, 0, lotto, 0);
		printf("\n");
	}

	return 0;
}