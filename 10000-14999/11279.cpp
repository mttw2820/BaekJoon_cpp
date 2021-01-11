//BaekJoon_11279
//최대 힙
/*
* 제한 시간 : 1s
* 정답 비율 : 42.525%
*/

#include <iostream>
using namespace std;

void swap(long long &x, long long &y) {
	long long temp = x;
	x = y;	y = temp;
	return;
}

void insert_heap(long long input, long long heap[], int size) {
	heap[size] = input;
	// 최대 힙 정리
	int parent, now = size;
	while (now > 1) {
		parent = now / 2;
		if (heap[parent] > heap[now]) break;
		swap(heap[parent], heap[now]);
		now = parent;
	}
	return;
}
void delete_heap(long long heap[], int &size) {
	swap(heap[size], heap[1]);
	size--;
	// 최대 힙 정리
	int left, right, now = 1;
	while (now * 2 <= size) {
		left = now * 2;
		right = now * 2 + 1;
		int child = left;
		if (right <= size) {
			// 오른쪽 자식이 있는 경우
			if (heap[right] > heap[left]) 
				child = right;
		}
		if (heap[now] > heap[child]) break;
		swap(heap[now], heap[child]);
		now = child;
	}
	return;
}
int main() {
	int heap_size = 0;
	long long heap[100010] = { 0, };
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long input = 0;
		scanf("%lld", &input);
		if (input == 0) {
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