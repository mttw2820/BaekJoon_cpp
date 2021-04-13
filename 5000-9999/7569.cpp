//BaekJoon_7569
//토마토
/*
* 제한 시간 : 1s
* 정답 비율 : 40.407%
*/

#include <iostream>
#include <queue>
using namespace std;

struct pos{
    int x;
    int y;
    int z;
    pos(int X, int Y, int Z): x(X), y(Y), z(Z) {}
};

int boxes[105][105][105] = {0,};
int mx[] = {1, -1, 0, 0, 0, 0};
int my[] = {0, 0, 1, -1, 0, 0};
int mz[] = {0, 0, 0, 0, 1, -1};

void get_input(int &m, int &n, int &h, int &cnt_tomato, int &riped, queue<pos> &q){
    scanf("%d %d %d", &m, &n, &h);

    for(int k=0; k<h; k++){
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                scanf("%d", &boxes[i][j][k]);
                if(boxes[i][j][k] != -1){
                    cnt_tomato++;
                    if(boxes[i][j][k] == 1){
                        riped++;
                        q.push(pos(i,j,k));
                    }
                }
            }
        }
    }
    return;
}

bool is_out_of_range(int m, int n, int h, int x, int y, int z){
    if(x < 0 || y < 0 || z < 0) return true;
    if(x >= m || y >= n || z >= h) return true;
    return false;
}

int spread(int m, int n, int h, pos &now, queue<pos> &q){
    int nx, ny, nz;
    int count = 0;
    for(int i=0; i<6; i++){
        nx = now.x + mx[i];
        ny = now.y + my[i];
        nz = now.z + mz[i];

        if(is_out_of_range(m, n, h, nx, ny, nz)) continue;
        if(boxes[nx][ny][nz] == 0) {
            q.push(pos(nx, ny, nz));
            boxes[nx][ny][nz] = 1;
            count++;
        }
    }
    return count;
}
int wait_tomatoes(int m, int n, int h, int cnt_tomato, int riped, queue<pos> &q){
    if(cnt_tomato == riped) return 0;

    int day = 0;
    while(!q.empty()){
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            pos now = q.front();
            q.pop();
            riped += spread(m, n, h, now, q);
        }

        day++;
        if(cnt_tomato == riped) return day;
    }

    return -1;
}

int main(){
    int m, n, h;
    int cnt_tomato = 0, riped = 0;  // 총 토마토 수와 익은 토마토 수
    queue<pos> q;
    get_input(m, n, h, cnt_tomato, riped, q);
    int day = wait_tomatoes(m, n, h, cnt_tomato, riped, q);
    printf("%d\n", day);
    return 0;
}