//BaekJoon_10866
//덱
/*
* 제한 시간 : 0.5s
* 정답 비율 : 55.048%
*/

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	string order;
	int number = 0;
	int testorder = 0;
	deque<int> deq;

	cin >> testorder;
	while (testorder != 0) {
		cin >> order;
		if (order == "push_front") {
			cin >> number;
			deq.push_front(number);
		}
		else if (order == "push_back") {
			cin >> number;
			deq.push_back(number);
		}
		else if (order == "size") {
			cout << deq.size() << endl;
		}
		else if (order == "empty") {
			if (deq.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else {
			if (deq.empty()) {
				cout << "-1" << endl;
				testorder--;
				continue;
			}
			if (order == "pop_front") {
				int front = deq.front();
				deq.pop_front();
				cout << front << endl;
			}
			else if (order == "pop_back") {
				int back = deq.back();
				deq.pop_back();
				cout << back << endl;
			}
			else if (order == "front") {
				cout << deq.front() << endl;
			}
			else if (order == "back") {
				cout << deq.back() << endl;
			}
		}

		testorder--;
	}

	return 0;
}