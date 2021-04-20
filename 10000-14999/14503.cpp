//BaekJoon_14503
//로봇 청소기
/*
* 제한 시간 : 2s
* 정답 비율 : 52.486%
*/

#include <iostream>
#define NORTH 0
#define WEST 1
#define SOUTH 2
#define EAST 3
#define NOT_CLEANED 0
#define CLEANED -1
#define WALL 1
using namespace std;

int mx[] = {-1, 0, 1, 0};
int my[] = {0, 1, 0, -1};

int room[55][55] = {0,};
struct cleaner{
    int x;
    int y;
    int dir;
    cleaner(int a, int b, int d): x(a), y(b), dir(d){}

    private:
    bool check_range(int a, int b, int n, int m){
        if(a<0 || b<0 || a>=n || b>=m) return false;
        return true;
    }

    int left_dir(int d){
        int left = d - 1;
        if(left < 0) left += 4;
        return left;
    }

    bool is_not_cleaned(int a, int b, int n, int m){
        if(check_range(a, b, n, m)){
            if(room[a][b] == NOT_CLEANED) return true;
            else return false;
        }
        else return false;
    }

    public:
    bool clean(int n, int m){
        if(room[x][y] == NOT_CLEANED) {
            room[x][y] = CLEANED;
            return true;
        }
        else return false;
    }

    bool move(int n, int m){
        // check_left
        int left = left_dir(dir);
        int nx = x + mx[left];
        int ny = y + my[left];
        if(is_not_cleaned(nx, ny, n, m)){
            dir = left;
            x = nx; y = ny;
            return true;
        }
        else {
            int turn_dir = left;
            bool is_stucked = true;

            for(int i=0; i<3; i++){
                turn_dir = left_dir(turn_dir);
                if(is_not_cleaned(x + mx[turn_dir], y + my[turn_dir], n, m)){
                    is_stucked = false;
                }
            }

            if(is_stucked){
                int back = left_dir(left);
                int bx = x + mx[back];
                int by = y + my[back];
                // end
                if(!check_range(bx, by, n, m) || room[bx][by] == WALL){
                    return false;
                }
                else {  // go back
                    x = bx; y = by;
                }
            }
            else {
                dir = left;
            }

            return true;
        }
    }
};

int main(){
    int n, m, x, y, d;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &y, &d);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &room[i][j]);
        }
    }

    cleaner cleaner_machine(x, y, d);
    bool iscleaned = false;
    bool isover = false;
    int count_cleaned_floor = 0;

    while(true){
        iscleaned = cleaner_machine.clean(n, m);
        isover = cleaner_machine.move(n, m);
        if(iscleaned) count_cleaned_floor++;
        if(!isover) break;
    }
    printf("%d", count_cleaned_floor);

    return 0;
}