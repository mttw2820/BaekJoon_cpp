//BaekJoon_4153
//�����ﰢ��
/*
* ���� �ð� : 1s
* ���� ���� : 58.315%
*/

#include <iostream>
#include <algorithm>
using namespace std;

long long nums[5] = { 0, };
int main() {
	
	while (true) {
		cin >> nums[0] >> nums[1] >> nums[2];
		
		// ���� ����
		if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0) 
			break;

		sort(nums, nums + 3);
		if (nums[0] * nums[0] + nums[1] * nums[1] == nums[2] * nums[2])
			cout << "right" << endl;
		else cout << "wrong" << endl;
	}

	return 0;
}