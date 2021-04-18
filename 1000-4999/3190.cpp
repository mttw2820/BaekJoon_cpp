//BaekJoon_3190
//뱀
/*
* 제한 시간 : 1s
* 정답 비율 : 37.198%
*/

#include <iostream>
#include <vector>
#include <deque>
#define APPLE 1
#define SNAKE -1
#define EMPTY 0
#define LEFT 10
#define RIGHT -10
using namespace std;

int board[105][105] = {0,};
int mx[] = {0, 1, 0, -1};
int my[] = {1, 0, -1, 0};

struct order{
    int time;
    int dir;
    order(int t, int d): time(t), dir(d) {}
};
struct pos {
    int x;
    int y;
    pos(int a, int b): x(a), y(b) {}
};

struct snake {
    int dir = 0;
    deque<pos> body;
    
    private :
    // 벽이나 몸에 부딪히는지 확인
    bool bump(int x, int y, int n){
        if(x <= 0 || y <= 0 || x > n || y > n) return true;
        else if(board[x][y] == SNAKE) return true;
        else return false;
    }

    public :
    // 지정방향으로 이동했는지 리턴
    bool move(int n){
        pos head = body.front();
        int nx = head.x + mx[dir];
        int ny = head.y + my[dir];
        if(bump(nx, ny, n)) return false;

        // tail
        if(board[nx][ny] != APPLE){
            pos tail = body.back();
            board[tail.x][tail.y] = EMPTY;
            body.pop_back();
        }
        // head
        body.push_front(pos(nx, ny));
        board[nx][ny] = SNAKE;
        return true;
    }

    void turn(int direction){
        if(direction == RIGHT) {
            dir = (dir + 1) % 4;
        }
        else {
            dir--;
            if(dir < 0) dir += 4;
        }
        return;
    }
};

void get_input(int &map_size, int &order_num, vector<order> &order_list){
    int apple_num, x, y, order_time;
    char dir[2];
    scanf("%d %d", &map_size, &apple_num);

    for(int i=0; i<apple_num; i++){
        scanf("%d %d", &x, &y);
        board[x][y] = APPLE;
    }

    scanf("%d", &order_num);
    for(int i=0; i<order_num; i++){
        scanf("%d %c", &order_time, &dir);
        if(dir[0] == 'L') {
            order_list.push_back(order(order_time, LEFT));
        }
        else order_list.push_back(order(order_time, RIGHT));
    }
    return;
}

int game_on(int map_size, int &order_num, vector<order> &order_list){
    int game_clock = 0;
    int order_index = 0;
    snake sn;
    sn.body.push_back(pos(1, 1));
    board[1][1] = SNAKE;
    while(true){
        game_clock++;
        int is_ok = sn.move(map_size);
        if(!is_ok) return game_clock;
        if(order_index < order_num && game_clock == order_list[order_index].time){
            sn.turn(order_list[order_index].dir);
            order_index++;
        }
    }
}
int main(){
    int map_size, order_num;
    vector<order> order_list;
    get_input(map_size, order_num, order_list);
    int result = game_on(map_size, order_num, order_list);
    printf("%d\n", result);
    
    return 0;
}