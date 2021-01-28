//BaekJoon_2206
//벽 부수고 이동하기
/*
* 제한 시간 : 2s
* 정답 비율 : 22.638%
*/

#include <iostream>
#include <queue>
using namespace std;

struct pos{     // x, y, 벽을 부순 횟수
    int x;
    int y;
    int crack;

    pos(int _x, int _y, int _c) : x(_x), y(_y), crack(_c) {}
};

bool iswall[1005][1005];
bool visit[1005][1005][2];
int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};

void init(int &n, int &m){  // 입력 처리
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1;j<=m; j++){
            scanf("%1d", &iswall[i][j]);
        }
    }
    return;
}

bool range_check(int x, int y, int n, int m){   // 이동 범위 확인
    if(x<1 || y<1|| x>n || y>m) return false;
    else return true;
}

int bfs(int n, int m){
    queue<pos> q;
    pos spos(1, 1, 0);
    q.push(spos);
    visit[1][1][0] = true;

    int cnt = 0;
    while(!q.empty()){
        // 각 움직임 횟수 별로 FOR문 --> 이동 횟수를 변수 하나로 카운트 가능
        int qsize = q.size();
        cnt++;
        
        for(int k=0; k<qsize; k++){
            int x = q.front().x;
            int y = q.front().y;
            int crack = q.front().crack;
            q.pop();

            if(x==n && y == m){
                return cnt;
            }

            int nx, ny;
            for(int i=0; i<4; i++){
                nx = x + mx[i];
                ny = y + my[i];

                if(range_check(nx, ny, n, m)){
                    // 벽이 아니고 처음 가는 길
                    if(!iswall[nx][ny] && !visit[nx][ny][crack]){
                        visit[nx][ny][crack] = true;
                        pos npos(nx, ny, crack);
                        q.push(npos);
                    }
                    // 벽이고 뽀갠적 없는 경우
                    if(iswall[nx][ny] && crack == 0){
                        visit[nx][ny][1] = true;
                        pos npos(nx, ny, 1);
                        q.push(npos);
                    }
                }
            }
        }
    }

    return -1;
}

int main(){
    int n, m;
    init(n, m);
    int result = bfs(n, m);
    printf("%d\n", result);
    return 0;
}