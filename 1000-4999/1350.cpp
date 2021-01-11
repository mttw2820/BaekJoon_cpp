//BaekJoon_1350
//��¥ ����
/*
* ���� �ð� : 2s
* ���� ���� : 30.889%
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int file_num, cluster_size, temp;
	vector<int> file;
	cin >> file_num;
	for (int i = 0; i < file_num; i++) {
		cin >> temp;
		file.push_back(temp);
	}
	cin >> cluster_size;
	long long total = 0;
	for (int i = 0; i < file_num; i++) {
		if (file[i] == 0) continue;
		int count = file[i] / cluster_size;
		if (file[i] % cluster_size != 0) count++;
		total += cluster_size * count;
	}
	cout << total << endl;


	return 0;
}