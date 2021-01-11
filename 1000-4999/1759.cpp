//BaekJoon_1759
//암호 만들기
/*
* 제한 시간 : 2s
* 정답 비율 : 43.892%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_pwd(int size, vector<char> pwd) {
	int consonant = 0, vowel = 0;
	for (int i = 0; i < size; i++) {
		switch (pwd[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			vowel++;
			break;
		default:
			consonant++;
			break;
		}
	}
	if (vowel > 0 && consonant >= 2) return true;
	else return false;
}
void print_pwd(int size, vector<char> pwd) {
	for (int i = 0; i < size; i++) {
		printf("%c", pwd[i]);
	}
	printf("\n");
	return;
}
void make_pwd(int cnt, int goal, int a_size, int p_size, vector<char> alpha, vector<char> pwd) {
	if (cnt == goal) {
		if (check_pwd(goal, pwd)) {
			print_pwd(goal, pwd);
		}
		return;
	}
	else if (p_size >= a_size) return;

 	for (int i = p_size; i < a_size; i++) {
		pwd[cnt] = alpha[i];
		make_pwd(cnt + 1, goal, a_size, i + 1, alpha, pwd);
	}
	return;
}
int main() {
	int L, C;
	char temp;
	scanf("%d %d", &L, &C);
	vector<char> alpha(C);
	vector<char> pwd(L);
	for (int i = 0; i < C; i++) {
		cin >> alpha[i];
	}
	sort(alpha.begin(), alpha.end());

	make_pwd(0, L, C, 0, alpha, pwd);

	return 0;
}