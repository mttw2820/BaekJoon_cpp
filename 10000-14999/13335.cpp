//BaekJoon_13335
//트럭
/*
* 제한 시간 : 1s
* 정답 비율 : 49.063%
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue <int> trucks;
	int truck_num, bridge_len, bridge_weight, temp;
	scanf("%d %d %d", &truck_num, &bridge_len, &bridge_weight);
	for (int i = 0; i < truck_num; i++) {
		scanf("%d", &temp);
		trucks.push(temp);
	}

	int cnt_time = 1, weight = 0;
	queue<int> enter_time;
	queue<int> on_bridge;
	while (!trucks.empty() || !on_bridge.empty()) {
		//최대 하중까지 차가 들어온다.
		while (!trucks.empty() && weight + trucks.front() <= bridge_weight && on_bridge.size() <= bridge_len) {
			on_bridge.push(trucks.front());
			weight += trucks.front();	//하중 더하기
			trucks.pop();
			enter_time.push(cnt_time);
			cnt_time++;
		}

		//가장 앞에 있는 차가 빠질 때까지 시간을 보낸다.
		//맨앞에 있는 차가 빠질 때까지 걸리는 시간
		// = 차가 들어온 시간 + 걸리는 시간 - 현재 시간
		if(enter_time.front() + bridge_len - cnt_time > 0)
			cnt_time += (enter_time.front() + bridge_len - cnt_time);
		weight -= on_bridge.front();
		enter_time.pop();
		on_bridge.pop();
	}

	cout << cnt_time << endl;

	return 0;
}