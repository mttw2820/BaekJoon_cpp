//BaekJoon_5671
//호텔 방 번호
/*
* 제한 시간 : 1s
* 정답 비율 : 67.387%
*/

#include <iostream>
using namespace std;

int main()
{
	int N, M, count, max, flag;
	int nums[4];
	
	while (1) {
		if (cin >> N >> M) {
			count = 0;
			for (int i = N; i <= M; i++) {
				nums[0] = i % 10;
				nums[1] = (i % 100) / 10;
				nums[2] = (i % 1000) / 100;
				nums[3] = i / 1000;

				for (int j = 3; j >= 0; j--) {
					if (nums[j] != 0) {
						max = j; break;
					}
				}

				flag = 0;
				for (int m = 0; m < max; m++) {
					if (flag == 1) break;
					for (int n = m + 1; n < max + 1; n++) {
						if (nums[m] == nums[n]) {
							flag = 1; break;
						}
					}
				}
				if (flag == 0) count++;
				for (int k = 0; k < 4; k++)
					nums[k] = 0;
			}
			cout << count <<endl;
		}
		else break;
	}
	return 0;
}
