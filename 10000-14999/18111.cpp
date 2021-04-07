//BaekJoon_18111
//마인크래프트
/*
* 제한 시간 : 1s
* 정답 비율 : 29.127%
*/

#include <iostream>
using namespace std;

int mine_map[505][505] = {0,};

void get_input(int &n, int &m, int &inb, int &max_h){
    scanf("%d %d %d", &n, &m, &inb);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &mine_map[i][j]);
            if(mine_map[i][j] > max_h){
                max_h = mine_map[i][j];
            }
        }
    }
    return;
}

void count_flatten(int n, int m, int h, int &cnt_more, int &cnt_less){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mine_map[i][j] > h){
                // 제거해야 하는 경우
                cnt_less += mine_map[i][j] - h;
            }
            else cnt_more += h - mine_map[i][j];
        }
    }
    return;
}

bool ispossible(int inb, int cnt_more, int cnt_less){
    if(cnt_less + inb < cnt_more) return false;
    else return true;
}

void flatten(int n, int m, int inb, int max_h){
    int min_time = 1<<31 - 1;
    int result_height = 0;

    for(int h=0; h<=max_h; h++){
        int cnt_more = 0;   // 추가할 높이
        int cnt_less = 0;   // 제거할 높이

        count_flatten(n, m, h, cnt_more, cnt_less);
        if(ispossible(inb, cnt_more, cnt_less)){
            int time = cnt_more + cnt_less * 2;
            if(time <= min_time){
                min_time = time;
                result_height = h;
            }
        }
    }

    // print result
    printf("%d %d\n", min_time, result_height);
}
int main(){
    int n, m, inb, max_h;
    get_input(n, m, inb, max_h);
    flatten(n, m, inb, max_h);

    return 0;
}