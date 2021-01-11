//BaekJoon_1927
//최소 힙
/*
* 제한 시간 : 1s
* 정답 비율 : 46.148%
*/

#include <iostream>
using namespace std;

void swap(long long &x, long long &y) {
	long long temp = x;
	x = y;	y = temp;
	return;
}

void insert_heap(int x, long long heap[], int &size) {
	// 가장 끝자리에 insert
	heap[size] = x;
	// 위로 이동
	int parent, now = size;
	while (now > 1) {
		parent = now / 2;
		if (heap[parent] > heap[now]) {
			swap(heap[parent], heap[now]);
			now = parent;
		}
		else break;
	}
	return;
}

void delete_heap(long long heap[], int &size) {
	// root 와 leaf 자리 교체
	swap(heap[1], heap[size]);
	size--;
	// 최소힙 정렬
	int now = 1, left, right;
	while (now * 2 <= size) {
		left = now * 2;
		right = now * 2 + 1;
		int child;	// 비교할 자식 노드
		if (right <= size) {
			// 양쪽 자식 모두 있는 경우
			if (heap[left] < heap[right]) child = left;
			else child = right;
		}
		else { child = left; }

		if (heap[child] >= heap[now]) break;
		else swap(heap[child], heap[now]);
		now = child;
	}
	return;
}

int main() {
	int heap_size = 0;
	long long heap[100010] = { 0, };

	int k = 0;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		long long input = 0;
		scanf("%lld", &input);
		if (input == 0) {
			// 출력하기
			if (heap_size == 0) printf("0\n");
			else {
				printf("%lld\n", heap[1]);
				delete_heap(heap, heap_size);
			}
		}
		else {
			heap_size++;
			insert_heap(input, heap, heap_size);
		}
	}

	return 0;
}