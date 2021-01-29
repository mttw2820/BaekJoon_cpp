//BaekJoon_2475
//검증수
/*
* 제한 시간 : 1s
* 정답 비율 : 77.794%
*/

#include <iostream>
using namespace std;

int main(){
    int sum = 0, num = 0;
    for(int i=0; i<5; i++){
        scanf("%d", &num);
        num = num*num%10;
        sum += num;
    }
    cout << sum%10 << endl;
    return 0;
}