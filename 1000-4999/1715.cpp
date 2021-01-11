//BaekJoon_1715
//카드 정렬하기
/*
* 제한 시간 :2s
* 정답 비율 : 38.620%
*/

#include <iostream>
using namespace std;

/* 최소 힙 사용
   두번의 pop으로 더하고 새로운 카드 묶음을 insert한다 */
void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}
void insert_heap(int heap[], int &size, int input) {
	heap[++size] = input;
	int now = size, parent;

	while (now > 1) {
		parent = now / 2;
		if (heap[parent] < heap[now])
			break;
		swap(heap[parent], heap[now]);
		now /= 2;
	}
}

int delete_heap(int heap[], int &size) {
	int front = heap[1];
	swap(heap[1], heap[size--]);
	int now = 1, child;

	while (now * 2 <= size) {
		int child = now * 2;
		if (child + 1 <= size) {	// 오른쪽 자식이 존재할 경우
			if (heap[child] > heap[child+1])
				child += 1;
		}
		if (heap[now] < heap[child]) 
			break;
		swap(heap[now], heap[child]);
		now = child;
	}
	return front;
}

int main() {
	int heap[100010];
	int heap_size = 0, n, input, new_pack = 0, result = 0;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		insert_heap(heap, heap_size, input);
	}

	while (heap_size > 1) {
		new_pack = delete_heap(heap, heap_size);
		new_pack += delete_heap(heap, heap_size);
		insert_heap(heap, heap_size, new_pack);
		result += new_pack;
	}
	printf("%d\n", result);
	return 0;
}