//BaekJoon_10825
//������
/*
* ���� �ð� : 1s
* ���� ���� : 45.838%
*/


#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string.h>

struct student {
	char name[12] = "";
	int lang;
	int eng;
	int math;
};
bool cmp(const student &s1, const student &s2) {
	//1. ���� ������ �����ϴ� ������
	if (s1.lang > s2.lang)
		return true;
	else if (s1.lang == s2.lang) {
		//2. ���� ������ �����ϴ� ������
		if(s1.eng < s2.eng)
			return true;
		else if (s1.eng == s2.eng) {
			//3. ���� ������ �����ϴ� ������
			if (s1.math > s2.math)
				return true;
			else if (s1.math == s2.math) {
				//4. �̸��� ���� ������ �����ϴ� ������
				if (strcmp(s1.name, s2.name)<=0)
					return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	vector <student> info(n);

	for (int i = 0; i < n; i++) 
		scanf("%s %d %d %d", info[i].name, &info[i].lang, &info[i].eng, &info[i].math);

	sort(info.begin(), info.end(), cmp);

	for (int i = 0; i < n; i++) {
		printf("%s\n", info[i].name);
	}

	return 0;
}