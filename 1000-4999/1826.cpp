//BaekJoon_1826
//연료 채우기
/*
* 제한 시간 : 2s
* 정답 비율 : 27.347%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(pair<int, int> &p1, pair<int, int> &p2) {
	pair<int, int> temp = p1;
	p1 = p2;
	p2 = temp;
}

bool sort_in_first(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}

struct Station {
	vector<pair<int, int>> heap;
	int size;
	Station(int n) : heap(n + 1), size(0) {}

	void insert_heap(pair<int, int> input) {
		heap[++size] = input;
		int now = size, parent;
		while (now > 1) {
			parent = now / 2;
			if (heap[now].second < heap[parent].second) break;
			swap(heap[now], heap[parent]);
			now = parent;
		}
	}

	pair<int, int> pop() {
		pair<int, int> output = heap[1];
		swap(heap[1], heap[size--]);

		int now = 1, child;
		while (now * 2 <= size) {
			child = now * 2;
			if (child + 1 <= size && heap[child].second < heap[child + 1].second)
				child++;
			if (heap[now].second > heap[child].second) break;
			swap(heap[now], heap[child]);
			now = child;
		}
		return output;
	}
};

int main() {
	int n, pos, gas_left, here = 0, cnt_stop = 0;
	scanf("%d", &n);
	vector<pair<int, int>> st(n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &st[i].first, &st[i].second);
	}
	scanf("%d %d", &pos, &gas_left);

	if (gas_left >= pos) {
		printf("0\n");
		return 0;
	}
	sort(st.begin(), st.end(), sort_in_first);

	int i = 0;
	Station station(n);
	for (int i = 0; i < n; i++) {
		// 다음 station에 도달하지 못하는 경우
		// 지나친 station의 기름을 더 충전했어야한다
		while (station.size != 0 && here + gas_left < st[i].first) {
			gas_left += station.pop().second;
			cnt_stop++;
		}
		// 그래도 다음 station에 못가는 경우는 끝
		if (here + gas_left < st[i].first) break;

		// 다음 station에 갈 수 있는 경우
		gas_left -= (st[i].first - here);
		here = st[i].first;
		station.insert_heap(st[i]);
	}

	// 아직 부족한 경우 지나친 station의 기름 충전
	while (here + gas_left < pos && station.size != 0) {
		gas_left += station.pop().second;
		cnt_stop++;
	}

	if (here + gas_left >= pos) printf("%d\n", cnt_stop);
	else printf("-1\n");

	return 0;
}