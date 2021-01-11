#include <iostream>
using namespace std;

int main() {
	int nums[10] = { 0, };
	int check = 0;
	for (int i = 0; i < 8; i++) {
		cin >> nums[i];
	}
	if (nums[1] - nums[0] == 1) check = 1;
	else if (nums[1] - nums[0] == -1) check = -1;
	else check = 10;
	for (int i = 2; i < 8; i++) {
		if ((nums[i] - nums[i - 1]) == check) continue;
		else {
			check = 10;
			break;
		}
	}
	
	
	if (check == 1) cout << "ascending" << endl;
	else if (check == -1) cout << "descending" << endl;
	else cout << "mixed" << endl;


	return 0;
}