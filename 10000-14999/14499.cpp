//BaekJoon_114499
//주사위 굴리기
/*
* 제한 시간 : 2s
* 정답 비율 : 41.917%
*/

#include <iostream>
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
using namespace std;

int board[25][25] = {0,};
int mx[] = {0, 0, 0, -1, 1};
int my[] = {0, 1, -1, 0, 0};

struct dice{
    int x;
    int y;
    int vert[4] = {0, 0, 0, 0};
    int hori[4] = {0, 0, 0, 0};

    dice(int a, int b) : x(a), y(b) {}
    public:
    bool is_valid_move(int n, int m, int dir){
        int nx = x + mx[dir];
        int ny = y + my[dir];
        if(nx<0 || ny<0 || nx>=n || ny>=m) return false;
        x = nx; y = ny;
        return true;
    }

    int roll(int dir){
        // 일단 굴리고
        if(dir == EAST) roll_east();
        else if(dir == WEST) roll_west();
        else if(dir == NORTH) roll_north();
        else roll_south();

        // 바닥 숫자 확인
        if(board[x][y] == 0){
            board[x][y] = vert[3];
        }
        else {
            vert[3] = hori[3] = board[x][y];
            board[x][y] = 0;
        }
        // 윗면 숫자 리턴
        return vert[1];
    }

    void roll_east(){
        int temp = hori[3];
        for(int i=3; i>0; i--){
            hori[i] = hori[i-1];
        }
        hori[0] = temp;

        vert[1] = hori[1];
        vert[3] = hori[3];
    }
    void roll_west(){
        int temp = hori[0];
        for(int i=0; i<3; i++){
            hori[i] = hori[i+1];
        }
        hori[3] = temp;

        vert[1] = hori[1];
        vert[3] = hori[3];

    }
    void roll_north(){
        int temp = vert[0];
        for(int i=0; i<3; i++){
            vert[i] = vert[i+1];
        }
        vert[3] = temp;

        hori[1] = vert[1];
        hori[3] = vert[3];
    }
    void roll_south(){
        int temp = vert[3];
        for(int i=3; i>0; i--){
            vert[i] = vert[i-1];
        }
        vert[0] = temp;

        hori[1] = vert[1];
        hori[3] = vert[3];
    }
};

void get_input(int &n, int &m, int &x, int &y, int &order_num){
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &order_num);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &board[i][j]);
        }
    }
}
void game_on(int n, int m, int x, int y, int order_num){
    dice player(x, y);
    int order = 0;
    for(int i=0; i<order_num; i++){
        scanf("%d", &order);
        if(player.is_valid_move(n, m, order)){
            int output = player.roll(order);
            printf("%d\n", output);
        }
    }
    return;
}
int main(){
    int n, m, x, y, order_num;
    get_input(n, m, x, y, order_num);
    game_on(n, m, x, y, order_num);

    return 0;
}