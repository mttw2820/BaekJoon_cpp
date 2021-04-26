//BaekJoon_15685
//드래곤 커브
/*
* 제한 시간 : 1s
* 정답 비율 : 52.965%
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define CHECK true
using namespace std;

struct sp{
    int x, y;
    int dir;
    int gen;
    sp(int a, int b, int d, int g): x(a), y(b), dir(d), gen(g) {}
};
struct pos{
    int x, y;
    pos(int a, int b): x(a), y(b) {}
};

int mx[] = {1, 0, -1, 0};
int my[] = {0, -1, 0, 1};
bool board[101][101] = {false,};

void get_input(int &n, vector<sp> &dragons){
    int x, y, d, g;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &x, &y, &d, &g);
        dragons.push_back(sp(x, y, d, g));
    }
    return;
}

int next(int number){
    number ++;
    if(number > 3) number -= 4;
    return number;
}

void move(int &x, int &y, vector<int> &dir, int dir_num){
    int nx, ny, d = 0;
    for(int i=0; i<dir_num; i++){
        d = dir[i];
        x += mx[d];
        y += my[d];
        board[x][y] = CHECK;
    }
    return;
}
void make_dragon_curves(sp &start_point){
    vector<int> prev_dir(1030, 0);
    int prev_num = 1;
    int x = start_point.x;
    int y = start_point.y;
    
    board[x][y] = CHECK;
    prev_dir[0] = start_point.dir;
    move(x, y, prev_dir, prev_num);
    prev_dir[0] = next(prev_dir[0]);

    int gen = start_point.gen;
    for(int g=1; g<=gen; g++){
        // prev_dir에 담긴 내용 체크하기
        move(x, y, prev_dir, prev_num);
        
        for(int i=0; i<prev_num; i++){
            prev_dir[prev_num+i] = prev_dir[i];
        }
        for(int i=0; i<prev_num; i++){
            prev_dir[prev_num-i-1] = next(prev_dir[prev_num+i]);
        }
        prev_num *= 2;
    }

    
    return;
}

int count_dragon_rec(){
    int count = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(board[i][j] && board[i][j+1] && board[i+1][j] && board[i+1][j+1]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    vector<sp> dragons;
    get_input(n, dragons);
    for(int i=0; i<n; i++){
        make_dragon_curves(dragons[i]);
    }
    
    int result = count_dragon_rec();
    printf("%d\n", result);

    return 0;
}