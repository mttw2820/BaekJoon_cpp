//BaekJoon_13469
//구슬 탈출 2
/*
* 제한 시간 : 2s
* 정답 비율 : 25.764%
*/

#include <iostream>
#include <vector>
#include <queue>
#define WALL -1
#define BLANK 0
#define HOLE 1
using namespace std;

struct pos{
    int x;
    int y;
    pos(int X, int Y) : x(X), y(Y) {}
};

int board[15][15] = {0,};
// right, left, down, up
int move_dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void get_input(int &n, int &m, pos &red, pos &blue){
    string str;

    // board size
    scanf("%d %d", &n, &m);
    
    // board input
    for(int i=0; i<n;i++){
        cin >> str;
        for(int j=0; j<m; j++){
            switch(str[j]){
            case '#':
                board[i][j] = WALL;
                break;
            case 'O':
                board[i][j] = HOLE;
                break;
            case '.':
                board[i][j] = BLANK;
                break;
            case 'R':
                board[i][j] = BLANK;
                red.x = i;  red.y = j;
                break;
            case 'B':
                board[i][j] = BLANK;
                blue.x = i; blue.y = j;
                break;
            }
        }
    }
    return;
}

bool move(pos &ball, int dir[]){
    while(true){
        pos next = ball;
        next.x += dir[0];
        next.y += dir[1];
        if(board[next.x][next.y] == HOLE){
            return true;
        }
        else if(board[next.x][next.y] == BLANK){
            ball = next;
        }
        else {  // WALL
            return false;
        }
    }
}

bool tilt_left(pos &red, pos &blue, queue<pair<pos, pos>> &q){
    bool is_red_in = false, is_blue_in = false;
    pos next_red = red, next_blue = blue;

    is_red_in = move(next_red, move_dir[1]);
    is_blue_in = move(next_blue, move_dir[1]);
    
    // 같은 라인 상에 존재하는지
    if(red.x == blue.x){
        if(next_red.y == next_blue.y){
            if(red.y < blue.y) next_blue.y++;
            else next_red.y++;
        }
    }

    if(is_red_in && !is_blue_in) return true;
    else if(!is_blue_in){
        q.push(make_pair(next_red, next_blue));
    }
    return false;
}

bool tilt_right(pos &red, pos &blue, queue<pair<pos, pos>> &q){
    bool is_red_in = false, is_blue_in = false;
    pos next_red = red, next_blue = blue;

    is_red_in = move(next_red, move_dir[0]);
    is_blue_in = move(next_blue, move_dir[0]);
    
    // 같은 라인 상에 존재하는지
    if(red.x == blue.x){
        if(next_red.y == next_blue.y){
            if(red.y < blue.y) next_red.y--;
            else next_blue.y--;
        }
    }

    if(is_red_in && !is_blue_in) return true;
    else if(!is_blue_in){
        q.push(make_pair(next_red, next_blue));
    }
    return false;
}

bool tilt_up(pos &red, pos &blue, queue<pair<pos, pos>> &q){
    bool is_red_in = false, is_blue_in = false;
    pos next_red = red, next_blue = blue;

    is_red_in = move(next_red, move_dir[3]);
    is_blue_in = move(next_blue, move_dir[3]);
    
    // 같은 라인 상에 존재하는지
    if(red.y == blue.y){
        if(next_red.x == next_blue.x){
            if(red.x < blue.x) next_blue.x++;
            else next_red.x++;
        }
    }

    if(is_red_in && !is_blue_in) return true;
    else if(!is_blue_in){
        q.push(make_pair(next_red, next_blue));
    }
    return false;
}

bool tilt_down(pos &red, pos &blue, queue<pair<pos, pos>> &q){
    bool is_red_in = false, is_blue_in = false;
    pos next_red = red, next_blue = blue;

    is_red_in = move(next_red, move_dir[2]);
    is_blue_in = move(next_blue, move_dir[2]);
    
    // 같은 라인 상에 존재하는지
    if(red.y == blue.y){
        if(next_red.x == next_blue.x){
            if(red.x < blue.x) next_red.x--;
            else next_blue.x--;
        }
    }

    if(is_red_in && !is_blue_in) return true;
    else if(!is_blue_in){
        q.push(make_pair(next_red, next_blue));
    }
    return false;
}

bool tilt_board(pos &red, pos &blue, queue<pair<pos, pos>> &q){
    if(tilt_left(red, blue, q)) return true;
    if(tilt_right(red, blue, q)) return true;
    if(tilt_up(red, blue, q)) return true;
    if(tilt_down(red, blue, q)) return true;
    return false;
}

int game_on(pos start_red, pos start_blue){
    queue<pair<pos, pos>> q;
    q.push(make_pair(start_red, start_blue));

    int day = 1;
    bool hole_in = false;
    for(; day<=10; day++){
        int qsize = q.size();
        for(int i=0; i<qsize; i++){
            // tilt
            pos red = q.front().first;
            pos blue = q.front().second;
            q.pop();

            hole_in = tilt_board(red, blue, q);
            if(hole_in) return day;
        }
    }
    return -1;
}

int main(){
    int n, m;
    pos red(0, 0), blue(0, 0);
    get_input(n, m, red, blue);
    int result = game_on(red, blue);
    printf("%d\n", result);
    return 0;
}