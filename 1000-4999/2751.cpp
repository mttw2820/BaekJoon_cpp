//BaekJoon_2751
//�� �����ϱ� 2
/*
* ���� �ð� : 2s
* ���� ���� : 31.744%
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;

void MergeSort(int start, int end) {	// ����� ���İ���
	
	int mid = (start + end) / 2;
	// �ɰ� �� �ִ��� Ȯ��
	if (start == end) return;
	else {		// �ɰ���
		MergeSort(start, mid);
		MergeSort(mid + 1, end);
	}

	// ��ġ�� ����
	int s1 = start, s2 = mid + 1;
	int i = 0;
	vector<int> after(end - start + 1, 0);
	for (i = 0; s1 <= mid && s2 <= end; i++) {
		if (numbers[s1] <= numbers[s2])	after[i] = numbers[s1++];
		else after[i] = numbers[s2++];
	}
	while (s1 <= mid) after[i++] = numbers[s1++];
	while (s2 <= end) after[i++] = numbers[s2++];
	
	for (i = 0; start + i <= end; i++) {
		numbers[start + i] = after[i];
	}

	return;
}



int main() {
	int n = 0;
	cin >> n;
	
	int in = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		numbers.push_back(in);
	}
	
	// MERGE SORTING
	MergeSort(0, n - 1);

	// ���
	for (int i = 0; i < n; i++)
		printf("%d\n", numbers[i]);

	return 0;
}