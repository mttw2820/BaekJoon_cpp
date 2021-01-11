//BaekJoon_1966
//프린터 큐
/*
* 제한 시간 : 2s
* 정답 비율 : 52.937%
*/

#include <iostream>
#include <queue>
using namespace std;

bool checkPriority(int size, queue<pair<int, int>> docs) {
	int now = docs.front().second;
	docs.pop();
	while (!docs.empty()) {
		if (docs.front().second > now) return false;
		docs.pop();
	}
	return true;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int docNum, ques, priority, ans = 0;
		queue<pair<int, int>> printSW;
		scanf("%d %d", &docNum, &ques);
		for (int i = 0; i < docNum; i++) {
			scanf("%d", &priority);
			printSW.push(pair<int, int>(i, priority));
		}
		
		while (true) {
			if (checkPriority(docNum, printSW)) {
				ans++;
				if (printSW.front().first == ques) break;
				printSW.pop();
			}
			else {
				pair<int, int> temp = printSW.front();
				printSW.pop();
				printSW.push(temp);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}