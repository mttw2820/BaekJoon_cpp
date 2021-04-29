//BaekJoon_16928
//뱀과 사다리 게임
/*
* 제한 시간 : 1s
* 정답 비율 : 35.988%
*/

#include <iostream>
#include <vector>
#include <queue>
#define GOAL 100
using namespace std;

void get_input(vector<int> &board){
    int n, m, from, to;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n+m; i++){
        scanf("%d %d", &from, &to);
        board[from] = to;
    }
    return;
}

int game_on(vector<int> &board){
    int visit[105] = {0,};
    queue<int> q;
    q.push(1);
    visit[1] = 0;
    int count = -1;

    while(!q.empty()){
        count ++;
        int qsize = q.size();
        for(int i=0; i<qsize; i++){
            int now = q.front();
            q.pop();

            int next = 0;
            for(int move=1; move <=6; move++){
                next = now + move;
                if(next == GOAL) return count + 1;
                if(next > GOAL) break;
                if(visit[next] == 0 || visit[next] > count + 1){
                    visit[next] = count + 1;
                    if(board[next] != 0){
                        next = board[next];
                        visit[next] = count + 1;
                    }
                    q.push(next);
                }
            }
        }
    }
    return visit[GOAL];
}
int main(){
    vector<int> board(105, 0);

    get_input(board);
    int result = game_on(board);
    printf("%d\n", result);

    return 0;
}