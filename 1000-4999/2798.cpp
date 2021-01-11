//BaekJoon_2798
//����
/*
* ���� �ð� : 1s
* ���� ���� : 42.308%
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	vector <int> card;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp > m) {	//m���� ū ���ڴ� ���ʿ� �����Ѵ�.
			i--; n--;
		}
		else card.push_back(temp);
	}

	int black = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				int sum = card[i] + card[j] + card[k];
				if ((m-sum)>=0 && (m - sum) < (m - black))
					black = sum;
			}
		}
	}
	cout << black << endl;
	return 0;
}