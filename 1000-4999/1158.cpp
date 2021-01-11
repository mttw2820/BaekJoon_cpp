//BaekJoon_1158
//�����۽� ����
/*
* ���� �ð� : 2s
* ���� ���� : 50.640%
*/
#include <iostream>
using namespace std;
#include <vector>

int main() {
	int n, k, now = 0;
	cin >> n >> k;
	vector<int> joseph;
	for (int i = 0; i < n; i++) {
		//�ڸ� ��ȣ�� �ʱ�ȭ
		joseph.push_back(i+1);
	}

	cout << "<";
	for (int i = 0; i < n-1; i++) {
		//���� ��ġ���� 1, 2, ... k ��° ��ġ�ϱ� k-1��ŭ ���Ѵ�.
		now += k-1;
		//�������� ����� 1���� �ٽ� ����
		while (now >= joseph.size()) 
			now %= joseph.size();
		cout << joseph[now] << ", ";
		joseph.erase(joseph.begin() + now);
	}
	cout << joseph[0] << ">" << endl;

	return 0;
}