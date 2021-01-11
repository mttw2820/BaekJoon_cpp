//BaekJoon_7785
//ȸ�翡 �ִ� ���
/*
* ���� �ð� : 1s
* ���� ���� : 37.462%
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	char name[10], status[10];
	set<string> log;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s %s", name, status);
		if (status[0] == 'e') {
			log.insert(name);
		}
		else {
			if (log.find(name) != log.end())
				log.erase(log.find(name));
		}
	}

	set<string>::reverse_iterator it = log.rbegin();
	for (; it != log.rend(); ++it) {
		printf("%s\n", (*it).c_str());
	}

	return 0;
}