#include <iostream>
using namespace std;

int main() {
	int t, m;
	scanf("%d %d", &t, &m);
	
	int time = t % 30;
	//정각인 경우
	if (time == 0) {
		if (m == 0)
			printf("O\n");
		else printf("X\n");
		return 0;
	}
	double min = (double)m * 60 / 360;
	if (time == min / 2) {
		printf("O\n");
	}
	else printf("X\n");

	return 0;
}