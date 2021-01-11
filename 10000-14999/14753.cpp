#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> pos;
vector<int> neg;

int main() {
	int n, temp, zero = 0;	//zero=0�̸� ���°�
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (temp > 0) pos.push_back(temp);
		else if (temp < 0) neg.push_back(temp);
		else zero = 1;
	}

	
	if ((pos.size() + neg.size() <=1) || (pos.size() == 1 && neg.size() == 1)) {
		//��� 1��, ���� 1���� ���
		//��� 1��, �������� 0
		//���� 1��, �������� 1
		cout << 0 << endl;
	}
	else {
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());
		reverse(pos.begin(), pos.end());
		int i;
		int posM = 1;
		int pos_size = pos.size();

		for (i = 0; i < 3 && pos_size>0; i++, pos_size--) {
			posM *= pos[i];
		}

		if (neg.size() >= 2) {
			//���� 2�� �̻��� ��� = ��*��
			int negM = neg[0] * neg[1];
			if (i > 0) {
				//��� 1�� �̻��� ��� : ��*��*��
				negM = negM * pos[0];
			}
			
			//��*�� vs ��*��*��
			printf("%d\n", max(negM, posM));

		}
		else {
			printf("%d\n", posM);
		}

	}

	return 0;
}