//BaekJoon_11659
//구간 합 구하기 4
/*
* 제한 시간 : 1s
* 정답 비율 : 50.154%
*/

#include <iostream>
using namespace std;

int num[100010] = {0,};
int dp[100010] = {0,};

void get_input(int &len, int &q_len){
    scanf("%d %d", &len, &q_len);
    for(int i=0; i<len; i++){
        scanf("%d", &num[i]);
    }
}

void init_dp(int len){
    dp[0] = num[0];
    for(int i=1; i<len; i++){
        dp[i] = dp[i-1] + num[i];
    }
    return;
}

int make_result(int from, int to){
    if(from == 0) return dp[to];
    else return dp[to] - dp[from-1];
}
int main(){
    int len, q_len;
    int from, to;
    get_input(len, q_len);
    init_dp(len);

    for(int i=0; i<q_len; i++){
        scanf("%d %d", &from, &to);
        int result = make_result(from-1, to-1);
        printf("%d\n", result);
    }
    
    return 0;
}