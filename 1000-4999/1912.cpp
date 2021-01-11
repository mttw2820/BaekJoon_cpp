#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int nums[100001];
	int Msum[100001] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	Msum[0] = nums[0];
	for (int i = 1; i < n; i++) {
		int a = Msum[i - 1] + nums[i];
		int b = nums[i];
		Msum[i] = (a > b) ? a : b;
	}
	sort(Msum, Msum + n);
	cout << Msum[n-1] << endl;
	return 0;
}