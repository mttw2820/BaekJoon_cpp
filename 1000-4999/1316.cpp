//BaekJoon_1316
//그룹 단어 체커
/*
* 제한 시간 : 2s
* 정답 비율 : 52.376%
*/

#include <iostream>
using namespace std;
#include <stdlib.h>
#define MAX 100
int main() {

	int N, count=0;
	char word[MAX];
	char prev[1];
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> word;
		int k = 0;
		int check = 1;
		while (word[k] != '\0') {
			if (word[k] != prev[0]){			// 그룹이 바뀌면 이전에 등장한 문자인지 확인
				for (int j = 0; j < k; j++) {	// 0~k 사이에 등장한 적 있는 문자인지
					if (word[k] == word[j]) check = 0;	// 등장한 적이 있다면 그룹 단어 아님
				}
			}
			// 다음 문자로 이동
			prev[0] = word[k];	
			k++;				
		}
		if (check == 1) count++;
	}
	cout << count << endl;

	return 0;
}