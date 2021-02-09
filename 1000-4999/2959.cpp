//BaekJoon_2959
//거북이
/*
* 제한 시간 : 1s
* 정답 비율 : 70.168%
*/

#include <iostream>
using namespace std;

int Partition(int nums[], int left, int right)
{
	int i, j, k;
	int temp[4];
	i = left;
	j = right;

	for (k = left + 1; k <= right; k++) {
		if (nums[k] < nums[left])
			temp[i++] = nums[k];
		else
			temp[j--] = nums[k];
	}
	temp[i] = nums[left];
	for (k = left; k <= right; k++)
		nums[k] = temp[k];
	return i;
}

//����Ʈ
void QuickSort(int nums[], int left, int right)
{
	int p;
	if (left < right) {
		p = Partition(nums, left, right);
		QuickSort(nums, left, p - 1);
		QuickSort(nums, p + 1, right);
	}
}


int main()
{
	int turtle;

	int nums[4];
	for (int i = 0; i < 4; i++)
		cin >> nums[i];

	QuickSort(nums, 0, 3);

	turtle = nums[0] * nums[2];
	cout << turtle << endl;

	return 0;
}
