//BaekJoon_14889
//스타트와 링크
/*
* 제한 시간 : 2s
* 정답 비율 : 50.611%
*/

#include <iostream>
using namespace std;
#include <stdlib.h>

int power[25][25] = { 0, };
int min_diff = -1;
int total = 0;

void team_matching(int team[], int now, int size);
int cal_diff(int team[], int size);

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> power[i][j];
			total += power[i][j];
		}
	}

	int team[15] = { 0, };
	for (int i = 0; i < n / 2; i++) team[i] = i;

	team_matching(team, 1, n);
	cout << min_diff << endl;
	return 0;
}

void team_matching(int team[], int now, int size) {
	if (now == size/2) {// 팀 매칭 끝
		int diff = cal_diff(team, size/2);
		if (min_diff < 0 || min_diff > diff)
			min_diff = diff;
		return;
	}

	// 앞에서 now번째이면 뒤에 size/2 - now - 1 개의 수가 와야한다.
	// 따라서 team[now]에는 now~{size - (size/2-now)} = size/2+now
	for (int i = team[now-1]+1; i <= size/2 + now; i++) {
		team[now] = i;
		team_matching(team, now + 1, size);
	}
	return;
}

int cal_diff(int start[], int size) {
	int start_power, link_power;
	start_power = link_power = 0;

	//link 배열 만들기
	int link[15] = { 0, };
	int cnt_s = 0, cnt_l = 0;
	for (int i = 0; i < size*2; i++) {
		if (start[cnt_s] != i)
			link[cnt_l++] = i;
		else cnt_s++;
	}

	//각 팀의 능력치 비교하기
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			start_power += (power[start[i]][start[j]] + power[start[j]][start[i]]);
			link_power += (power[link[i]][link[j]] + power[link[j]][link[i]]);
		}
	}

	return abs(start_power - link_power);
}