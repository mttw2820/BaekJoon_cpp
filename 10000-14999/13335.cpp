//BaekJoon_13335
//Ʈ��
/*
* ���� �ð� : 1s
* ���� ���� : 49.063%
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
		//�ִ� ���߱��� ���� ���´�.
		while (!trucks.empty() && weight + trucks.front() <= bridge_weight && on_bridge.size() <= bridge_len) {
			on_bridge.push(trucks.front());
			weight += trucks.front();	//���� ���ϱ�
			trucks.pop();
			enter_time.push(cnt_time);
			cnt_time++;
		}

		//���� �տ� �ִ� ���� ���� ������ �ð��� ������.
		//�Ǿտ� �ִ� ���� ���� ������ �ɸ��� �ð�
		// = ���� ���� �ð� + �ɸ��� �ð� - ���� �ð�
		if(enter_time.front() + bridge_len - cnt_time > 0)
			cnt_time += (enter_time.front() + bridge_len - cnt_time);
		weight -= on_bridge.front();
		enter_time.pop();
		on_bridge.pop();
	}

	cout << cnt_time << endl;

	return 0;
}