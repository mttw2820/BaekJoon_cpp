//BaekJoon_2257
//화학식량
/*
* 제한 시간 : 2s
* 정답 비율 : 35.444%
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool isNum(char c) {
	if (c - '0' >= 0 && c - '0' <= 9) return true;
	else return false;
}
pair<int, int> chemi_form(int sp, int len, char mole[]) {
	int sum = 0;
	pair<int, int> temp;
	for (int i = sp; i < len; i++) {
		switch (mole[i]) {
		case 'H':
			if (i < len - 1 && isNum(mole[i+1])) 
				sum += mole[i + 1] - '0';
			else sum += 1;
			break;
		case 'C':
			if (i < len - 1 && isNum(mole[i + 1]))
				sum += 12 * (mole[i + 1] - '0');
			else sum += 12;
			break;
		case 'O':
			if (i < len - 1 && isNum(mole[i + 1]))
				sum += 16 * (mole[i + 1] - '0');
			else sum += 16;
			break;
		case '(':
			temp = chemi_form(i + 1, len, mole);
			i = temp.second;
			if (i < len - 1 && isNum(mole[i + 1]))
				sum += temp.first * (mole[i + 1] - '0');
			else sum += temp.first;
			break;
		case ')':
			return make_pair(sum, i);
			break;
		}
	}
	return make_pair(sum, sp);
}
int main() {
	char mole[10010];
	scanf("%s", mole);
	int ans = chemi_form(0, strlen(mole), mole).first;
	printf("%d\n", ans);
	return 0;
}