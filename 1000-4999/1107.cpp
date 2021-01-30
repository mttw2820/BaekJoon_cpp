//BaekJoon_1107
//리모컨
/*
* 제한 시간 : 2s
* 정답 비율 : 22.396%
*/

#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

// input
void get_input(int &dest, int &n, int &num, bitset<10> &isbroken){
    scanf("%d", &dest);
    scanf("%d", &n);

    isbroken.reset();
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        isbroken[num] = 1;
    }
    return;
}

// 고장난 버튼이 포함되면 -1, 고장난 버튼 없이 채널 이동 가능하면 누른 버튼 수 리턴
int isavailable(int channel, bitset<10> isbroken){
    // 0은 따로 처리한다
    if(channel == 0) {
        if(isbroken[0]) return -1;
        else return 1;
    }

    int cnt = 0;
    while(channel != 0){
        if(isbroken[channel%10]) return -1;
        channel /= 10;
        cnt++;
    }
    return cnt;
}


int minimum_button(int dest, bitset<10> isbroken){
    // +, - 만 눌러서 이동하는 경우
    int min_move = abs(dest - 100);
    int channel_move = 0, move;

    // 완전탐색
    for(int channel = 0; channel<=1000000; channel++){
        // 채널로 이동할 수 있는지 확인
        channel_move = isavailable(channel, isbroken);
        if(channel_move != -1){
            // 채널 이동이 가능하면 (채널 버튼 수) + (+ 또는 - 횟수)
            move = abs(channel -dest);
            move += channel_move;
            min_move = min(min_move, move);
        }
    }

    return min_move;
}

int main(){
    int dest, n, num;
    bitset<10> isbroken;

    get_input(dest, n, num, isbroken);
    int result = minimum_button(dest, isbroken);
    printf("%d\n", result);

    return 0;
}