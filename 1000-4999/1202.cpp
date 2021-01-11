//BaekJoon_1202
//보석 도둑
/*
* 제한 시간 : 1s
* 정답 비율 : 23.411%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Jewerly {
	int weight;
	int value;
};

void swap(Jewerly &x, Jewerly &y) {
	Jewerly temp = x;
	x = y;
	y = temp;
}

bool sort_in_weight(Jewerly x, Jewerly y) {
	return x.weight < y.weight;
}

struct MaxHeap {
	vector<Jewerly> jew;	// start index = 1
	int size;

	MaxHeap(int n) : jew(n+1), size(0) {}

	void insertJewerly(Jewerly input) {
		jew[++size] = input;
		int now = size, parent;
		while (now > 1) {
			parent = now / 2;
			if (jew[parent].value > jew[now].value) break;
			swap(jew[parent], jew[now]);
			now /= 2;
		}
	}
	
	int popJewerly() {
		Jewerly output = jew[1];
		swap(jew[1], jew[size--]);
		int now = 1, child;
		while (now * 2 <= size) {
			child = now * 2;
			if (child + 1 <= size && jew[child].value < jew[child + 1].value)
				child += 1;
			if (jew[now].value > jew[child].value) break;
			swap(jew[now], jew[child]);
			now = child;
		}

		return output.value;
	}

};

int main() {
	int n, k, w, v, c;
	long long total_value = 0;
	scanf("%d %d", &n, &k);
	vector<Jewerly> jewerly(n+1);
	vector<int> bags(k);
	MaxHeap heap(n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &jewerly[i].weight, &jewerly[i].value);
	}
	for (int i = 0; i < k; i++) {	scanf("%d", &bags[i]);	}
	
	sort(jewerly.begin(), jewerly.end(), sort_in_weight);
	sort(bags.begin(), bags.end());

	for (int i = 0, j = 1; i < k; i++) {
		for (; j<=n && jewerly[j].weight <= bags[i]; j++) {
			heap.insertJewerly(jewerly[j]);
		}
		if(heap.size != 0)
			total_value += heap.popJewerly();
	}

	printf("%lld\n", total_value);

	return 0;
}