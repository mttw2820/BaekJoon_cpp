//BaekJoon_1924
//2007��
/*
* ���� �ð� : 2s
* ���� ���� : 44.449%
*/

#include <iostream>
#include <string.h>
using namespace std;

int days[15] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
char* dates[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main() {
	int date = 1;	//�Ͽ���: 0, ������: 1, ..., �����: 6
	int month, day;
	scanf("%d %d", &month, &day);
	for (int i = 1; i < month; i++)
		date += days[i];
	date += (day-1);
	date %= 7;
	printf("%s\n", dates[date]);
	
	return 0;
}