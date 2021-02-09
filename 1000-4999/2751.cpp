//BaekJoon_2751
//수 정렬하기 2
/*
* 제한 시간 : 2s
* 정답 비율 : 30.121%
*/

#include <iostream>
using namespace std;
#define MAX 1000000

//��Ʈ�� �����
void makeHeap(int nums[], int root, int n) {
	int child, temp = nums[root];
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (nums[child] < nums[child + 1]))
			child++;
		if (temp > nums[child]) break;
		else {
			nums[child / 2] = nums[child];
			child *= 2;
		}
	}
	nums[child / 2] = temp;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//����Ʈ
void HeapSort(int nums[], int N) {
	int i;

	for (i = N / 2; i > 0; i--)
		makeHeap(nums, i, N);
	for (i = N - 1; i > 0; i--) {
		swap(nums[1], nums[i + 1]);
		makeHeap(nums, 1, i);
	}
}

int main()
{
	int N = 0;
	int* nums = new int[MAX];


	cin >> N;
	for (int i = 1; i < N+1; i++)
		cin >> nums[i];

	HeapSort(nums, N);
	
	for (int i = 1; i < N+1; i++)
		cout << nums[i] << endl;

	delete[] nums;

	return 0;
}