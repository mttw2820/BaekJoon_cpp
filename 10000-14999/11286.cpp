//BaekJoon_11286
//���� ��
/*
* ���� �ð� : 1s
* ���� ���� : 52.710%
*/

#include <iostream>
#include <math.h>
using namespace std;

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int compare_abs(int now, int next) {
	// ���� ��
	// ������ ������ ���� ����
	if (abs(now) == abs(next)) {
		if (now < 0) return now;
		else return next;
	}
	else if (abs(now) < abs(next))
		return now;
	else return next;
}

// ������ ���� �� + ������ ������ ���� ����
void insert_heap(int heap[], int &size, int input) {
	heap[++size] = input;
	// �ּ� �� ����
	int now = size, parent;
	while (now > 1) {
		parent = now / 2;
		int comp = compare_abs(heap[now], heap[parent]);
		if (comp == heap[parent])
			break;
		swap(heap[now], heap[parent]);
		now = parent;
	}
}
void delete_heap(int heap[], int &size) {
	swap(heap[1], heap[size--]);
	// �ּ� �� ����
	int now = 1, child;
	while (now * 2 <= size) {
		child = now * 2;
		
		if (now * 2 + 1 <= size) {
			// ������ �ڽ��� �����ϴ� ���
			int comp = compare_abs(heap[child], heap[child + 1]);
			if (comp == heap[child + 1]) 
				child++;
		}
		int comp = compare_abs(heap[now], heap[child]);
		if (comp == heap[now]) break;
		swap(heap[now], heap[child]);
		now = child;
	}
}
int main() {
	int heap_size = 0;
	int heap[100010] = { 0, };
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		if (input == 0) {
			if (heap_size == 0)
				printf("0\n");
			else {
				printf("%d\n", heap[1]);
				delete_heap(heap, heap_size);
			}
		}
		else {
			insert_heap(heap, heap_size, input);
		}
	}

	return 0;
}