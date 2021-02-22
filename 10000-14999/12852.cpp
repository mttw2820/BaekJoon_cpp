//BaekJoon_12852
//1로 만들기 2
/*
* 제한 시간 : 0.5s
* 정답 비율 : 52.00%
*/

#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

int dp[MAX] = {0,};
int before[MAX] = {0,};

void move(int now, int next, queue<int> &q){
    if(dp[next] == 0){
        dp[next] = dp[now] + 1;
        before[next] = now;
        q.push(next);
    }
    return;
}
void make_one(int n){
    queue<int> q;
    q.push(n);
    before[n] = -1;

    while(!q.empty()){
        int now = q.front();
        if(now == 1) break;
        q.pop();

        move(now, now-1, q);
        if(now%2 == 0) move(now, now/2, q);
        if(now%3 == 0) move(now, now/3, q);
    }
    return;
}

void print_result(int n){
    if(before[n] > 0){
        print_result(before[n]);
    }
    printf("%d ", n);
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    make_one(n);
    printf("%d\n", dp[1]);
    print_result(1);
    return 0;
}