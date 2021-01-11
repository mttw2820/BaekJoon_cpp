//BaekJoon_1406
//에디터
/*
* 제한 시간 : 0.3s
* 정답 비율 : 25.565%
*/

#include <iostream>
#include <deque>
using namespace std;

char c[100001];
int main() {
	//커서를 기준으로 왼쪽과 오른쪽 문자열을 덱에 분리해서 저장한다.
	deque <char> left;
	deque <char> right;
	int n;
	char temp[5];
	scanf("%s", c);
	for (int i = 0; c[i]; i++)
		left.push_back(c[i]);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", c);
		switch (c[0]) {
		case 'L':
			if (left.empty()) break;
			temp[0] = left.back();
			left.pop_back();
			right.push_front(temp[0]);
			break;
		case 'D':
			if (right.empty()) break;
			temp[0] = right.front();
			right.pop_front();
			left.push_back(temp[0]);
			break;
		case 'B':
			if (left.empty()) break;
			left.pop_back();
			break;
		case 'P':
			scanf("%s", c);
			left.push_back(c[0]);
			break;
		}
	}
	for (int i = 0; i < left.size(); i++)
		printf("%c", left[i]);
	for (int i = 0; i < right.size(); i++)
		printf("%c", right[i]);
	printf("\n");

	return 0;
}