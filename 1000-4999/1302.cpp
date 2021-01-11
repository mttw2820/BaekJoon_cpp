//BaekJoon_1302
//����Ʈ����
/*
* ���� �ð� : 2s
* ���� ���� : 47.496%
*/

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<string, int> books;

int main() {
	int n;
	char title[51];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> title;
		if (books.count(title) == 1)
			books[title] ++;
		else
			books.insert(pair<string, int>(title, 1));
	}

	map<string, int>::iterator iter;
	string bestseller;
	for (iter = books.begin(); iter != books.end(); iter++) {
		if (iter->second > books[bestseller] || bestseller == "")
			bestseller = iter->first;
	}
	cout << bestseller << endl;

	return 0;
}