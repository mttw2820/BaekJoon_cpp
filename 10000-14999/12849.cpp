//BaekJoon_12849
//본대 산책
/*
* 제한 시간 : 1s
* 정답 비율 : 64.233%
*/

#include <iostream>
#include <vector>
#define MAX 1000000007
using namespace std;

void init(int &time, vector<int> (&next)[8]){
    scanf("%d", &time);
    next[0] = {1, 2};
    next[1] = {0, 2, 3};
    next[2] = {0, 1, 3, 4};
    next[3] = {1, 2, 4, 5};
    next[4] = {2, 3, 5, 6};
    next[5] = {3, 4, 7};
    next[6] = {4, 7};
    next[7] = {5, 6};
    return;
}

int route(int time, vector<int> next[]){
    vector<int> dp(16, 0);
    dp[0] = 1;

    for(int t=1; t<=time; t++){
        int now = t&1?8:0;
        int prev = 8-now;
        for(int i=0; i<8; i++){
            if(dp[prev+i] != 0){ 
                int s = next[i].size();
                for(int j=0; j<s; j++){
                    dp[now + next[i][j]] = (dp[now + next[i][j]] + dp[prev+i]) % MAX;
                }
                dp[prev+i] = 0;
            }
        }
    }
    if(time&1) return dp[8];
    else return dp[0];
}


int main(){
    int time;
    vector<int> next[8];
    init(time, next);
    int result = route(time, next);
    printf("%d\n", result);

    return 0;
}