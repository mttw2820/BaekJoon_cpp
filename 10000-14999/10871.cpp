#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, x, temp;
	vector<int> A;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < x) A.push_back(temp);
	}
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}

	return 0;
}