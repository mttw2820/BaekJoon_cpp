//BaekJoon_1655
//가운데를 말해요
/*
* 제한 시간 : 2s
* 정답 비율 : 34.345%
*/

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, less<int>> minheap;
priority_queue<int, vector<int>, greater<int>> maxheap;

void choose_mid(int input) {
	if (minheap.size() == 0) {
		minheap.push(input);
		return;
	}
	if (minheap.size() == maxheap.size()) {
		int temp = maxheap.top();
		if (temp < input) {
			maxheap.pop();
			maxheap.push(input);
			minheap.push(temp);
		}
		else {
			minheap.push(input);
		}
	}
	else if (minheap.size() > maxheap.size()) {
		int temp = minheap.top();
		if (temp > input) {
			minheap.pop();
			minheap.push(input);
			maxheap.push(temp);
		}
		else {
			maxheap.push(input);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		
		choose_mid(input);
		printf("%d\n", minheap.top());
	}

	return 0;
}