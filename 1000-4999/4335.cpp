//BaekJoon_4335
//���� ���߱�
/*
* ���� �ð� : 1s
* ���� ���� : 40.146%
*/
#include <iostream>
using namespace std;

int main() {
	int ques, min = 1, max = 10, flag = 0;
	char ans[10];
	while (true) {
		scanf("%d", &ques);
		if (ques == 0) break;
		scanf("%s", &ans);
		scanf("%s", &ans);

		if (ans[0] == 'h') {	//"too high"
			if (ques <= min) flag = -1;
			if (ques <= max) max = ques - 1;
		}
		else if (ans[0] == 'l') {	//"too low"
			if (ques >= max) flag = -1;
			if (ques >= min) min = ques + 1;
		}
		else if (ans[0] == 'o') {
			if (ques < min || ques > max || max < min) {
				flag = -1;
			}
			if (flag == -1) printf("Stan is dishonest\n");
			else printf("Stan may be honest\n");
			//���� ����, �ʱ�ȭ ����
			flag = 0;	min = 1;	 max = 10;
		}
	}

	return 0;
}