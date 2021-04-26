//BaekJoon_15683
//감시
/*
* 제한 시간 : 1s
* 정답 비율 : 41.808%
*/

#include <iostream>
#include <vector>
#define WALL 6
using namespace std;

int nx[] = {-1, 0, 1, 0};
int ny[] = {0, 1, 0, -1};
int directions[] = {0, 4, 2, 4, 4, 1};

void get_input(int &n, int &m, vector<vector<int>> &room){
    int input = 0;
    vector<int> temp(10, 0);
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &input);
            temp[j] = input;
        }
        room.push_back(temp);
    }
    return;
}

bool check_range(int x, int y, int n, int m){
    if(x<0 || y<0 || x>=n || y>=m) return false;
    return true;
}

void camera(int x, int y, int dir, int n, int m, vector<vector<int>> &room){
    while(true){
        if(!check_range(x, y, n, m)) return;
        if(room[x][y] == WALL) return;
        if(room[x][y] == 0) room[x][y] = -1;
        x += nx[dir];
        y += ny[dir];
    }
}

void cctv(int x, int y, int dir, int cctv_num, int n, int m, vector<vector<int>> &room){
    if(cctv_num == 1){
        camera(x, y, dir, n, m, room);
    }   
    else if(cctv_num == 2){
        camera(x, y, dir, n, m, room);
        camera(x, y, dir + 2, n, m, room);
    }
    else if(cctv_num == 3){
        camera(x, y, dir, n, m, room);
        int n_dir = dir + 1;
        if(n_dir == 4) n_dir = 0;
        camera(x, y, n_dir, n, m, room);
    }
    else if(cctv_num == 4) {
        for(int i=0; i<4; i++){
            if(i==dir) continue;
            camera(x, y, i, n, m, room);
        }
    }
    else {
        for(int i=0; i<4; i++){
            camera(x, y, i, n, m, room);
        }
    }
}

int count_empty_space(int n, int m, vector<vector<int>> &room){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(room[i][j] == 0) count ++;
        }
    }
    
    return count;
}

int dfs_cctv(int x, int y, int dir, int n, int m, vector<vector<int>> room){
    // check_cctv
    if(y >= 0) cctv(x, y, dir, room[x][y], n, m, room);

    bool check_dfs = false;
    int min_space = 100;
    int count = 0;
    for(int i=x; i<n; i++){
        int j = y+1;
        if(i!=x) j = 0;
        for(; j<m; j++){
            if(room[i][j] >=1 && room[i][j] < 6){
                check_dfs = true;
                int cctv_num = room[i][j];
                for(int k=0; k<directions[cctv_num]; k++){
                    count = dfs_cctv(i, j, k, n, m, room);
                    if(count < min_space) min_space = count;
                }
                break;
            }
        }
        if(check_dfs) break;
    }
    if(!check_dfs){
        // ending condition
        min_space = count_empty_space(n, m, room);
    }
    return min_space;
}

int main(){
    int n, m;
    vector<vector<int>> room;
    get_input(n, m, room);
    int result = dfs_cctv(0, -1, 0, n, m, room);
    printf("%d\n", result);
    return 0;
}