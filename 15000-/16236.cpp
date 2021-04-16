//BaekJoon_16236
//아기 상어
/*
* 제한 시간 : 2s
* 정답 비율 : 39.592%
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ocean[25][25] = {0,};
int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};

struct position{
    int x;
    int y;
    position(int a, int b) : x(a), y(b){}
};
struct fish {
    position pos;
    int shortest_path;
    fish(position p, int sp): pos(p), shortest_path(sp) {}
};

void get_input(int &n, position &shark){
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &ocean[i][j]);
            if(ocean[i][j] == 9){
                shark.x = i;
                shark.y = j;
                ocean[i][j] = 0;
            }
        }
    }
}

int count_eatable_fish(int n, int size){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ocean[i][j] != 0 && ocean[i][j] < size){
                count ++;
            }
        }
    }
    return count;

}

bool check_range(int n, int size, int x, int y){
    if(x<0 || y<0 || x>=n || y>=n) return false;
    else if(ocean[x][y] > size) return false;
    else return true;
}

// with bfs
fish find_target(int n, position shark, int shark_size){
    bool visit[25][25] = {false,};
    int distance = 0;
    queue<position> q;
    // 가장 위, 가장 왼쪽에 있는 물고기를 찾는다.
    fish target(position(25, 25), -1);

    q.push(shark);
    visit[shark.x][shark.y] = true;

    while(!q.empty()){
        int size = q.size();
        distance++;
        for(int i=0; i<size; i++){
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            for(int i=0; i<4; i++){
                int nx = x + mx[i];
                int ny = y + my[i];
                if(!check_range(n, shark_size, nx, ny)) continue;
                if(visit[nx][ny]) continue;
                visit[nx][ny] = true;
                if(ocean[nx][ny] == 0 || ocean[nx][ny] == shark_size){
                    q.push(position(nx, ny));
                } else {
                    // target
                    if(target.pos.x > nx) 
                        target = fish(position(nx, ny), distance);
                    else if(target.pos.x == nx && target.pos.y > ny) 
                        target = fish(position(nx, ny), distance);
                }
            }
        }
        if(target.shortest_path != -1) return target;
    }
    return target;
}

int baby_shark(int n, position shark){
    int count_day = 0;
    int shark_size = 2;
    int count_eat = 0;
    while(true){
        // count eatable fishes
        int eatable_fish = count_eatable_fish(n, shark_size);
        
        // call mom
        if(eatable_fish == 0)
            return count_day;
        else {
            // find fish
            fish target = find_target(n, shark, shark_size);
            if(target.shortest_path < 0)
                return count_day;

            // move & eat
            count_day += target.shortest_path;
            shark = target.pos;
            count_eat ++;
            ocean[shark.x][shark.y] = 0;
            
            // size update  
            if(count_eat == shark_size){
                count_eat = 0;
                shark_size ++;
            }
        }
    }
}
int main(){
    int n;
    position shark(0, 0);
    get_input(n, shark);
    int result = baby_shark(n, shark);
    printf("%d\n", result);

    return 0;
}