//BaekJoon_10814
//나이순 정렬
/*
* 제한 시간 : 3s
* 정답 비율 : 41.569%
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct member {
	int join;
	int age;
	string name;
};

bool sort_inAge(member m1, member m2) {
	if (m1.age == m2.age) return m1.join < m2.join;
	else return m1.age < m2.age;
}

int main() {
	vector<member> info;
	member new_mem;
	int n, age; char name[110];
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &age, name);
		new_mem.join = i;
		new_mem.age = age; new_mem.name = name;
		info.push_back(new_mem);
	}

	sort(info.begin(), info.end(), sort_inAge);
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", info[i].age, info[i].name.c_str());
	}

	return 0;
}