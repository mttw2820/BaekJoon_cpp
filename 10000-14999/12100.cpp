//BaekJoon_12100
//2048 (Easy)
/*
* 제한 시간 : 1s
* 정답 비율 : 24.640%
*/

#include <iostream>
#include <vector>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;

void get_input(int &n, vector<vector<int>> &board){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        vector<int> temp;
        int input;
        for(int j=0; j<n; j++){
            scanf("%d", &input);
            temp.push_back(input);
        }
        board.push_back(temp);
    }
    return;
}

int get_max(int n, vector<vector<int>> board){
    int max_num = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(max_num < board[i][j])
                max_num = board[i][j];
        }
    }
    return max_num;
}

void move(int n, int move_index, vector<vector<int>> &board){

    if(move_index == UP){
        for(int j=0; j<n; j++){
            int check_index = 0, new_index = 0;
            int prev = 0;

            for(; check_index<n; check_index++){
                if(board[check_index][j] == 0) continue;
                if(prev == 0) prev = board[check_index][j];
                else{
                    if(prev == board[check_index][j]){
                        // add
                        board[new_index++][j] = prev*2;
                        prev = 0;
                    }
                    else {
                        board[new_index++][j] = prev;
                        prev = board[check_index][j];
                    }
                }
            }
            if(prev != 0) board[new_index++][j] = prev;
            while(new_index < n) board[new_index++][j] = 0;
        }
    }
    else if(move_index == DOWN) {
        for(int j=0; j<n; j++){
            int check_index = n-1, new_index = n-1;
            int prev = 0;

            for(; check_index >= 0; check_index--){
                if(board[check_index][j] == 0) continue;
                if(prev == 0) prev = board[check_index][j];
                else{
                    if(prev == board[check_index][j]){
                        // add
                        board[new_index--][j] = prev*2;
                        prev = 0;
                    }
                    else {
                        board[new_index--][j] = prev;
                        prev = board[check_index][j];
                    }
                }
            }
            if(prev != 0) board[new_index--][j] = prev;
            while(new_index >= 0) board[new_index--][j] = 0;
        }
    }
    else if(move_index == LEFT) {
        for(int i=0; i<n; i++){
            int check_index = 0, new_index = 0;
            int prev = 0;

            for(; check_index < n; check_index++){
                if(board[i][check_index] == 0) continue;
                if(prev == 0) prev = board[i][check_index];
                else{
                    if(prev == board[i][check_index]){
                        // add
                        board[i][new_index++] = prev*2;
                        prev = 0;
                    }
                    else {
                        board[i][new_index++] = prev;
                        prev = board[i][check_index];
                    }
                }
            }
            if(prev != 0) board[i][new_index++] = prev;
            while(new_index < n) board[i][new_index++] = 0;
        }
    } 
    else {  // RIGHT
        for(int i=0; i<n; i++){
            int check_index = n-1, new_index = n-1;
            int prev = 0;

            for(; check_index >= 0; check_index--){
                if(board[i][check_index] == 0) continue;
                if(prev == 0) prev = board[i][check_index];
                else{
                    if(prev == board[i][check_index]){
                        // add
                        board[i][new_index--] = prev*2;
                        prev = 0;
                    }
                    else {
                        board[i][new_index--] = prev;
                        prev = board[i][check_index];
                    }
                }
            }
            if(prev != 0) board[i][new_index--] = prev;
            while(new_index >= 0) board[i][new_index--] = 0;
        }
    }

    return;
}


int max_2048(int n, int count_move, int move_index, vector<vector<int>> board){
    // move
    if(move_index >= 0){
        move(n, move_index, board);
    }
    // get max
    int max_num = get_max(n, board);
    if(count_move == 5) return max_num;

    // dfs
    for(int i=0; i<4; i++){
        int next_max = max_2048(n, count_move + 1, i, board);
        if(max_num < next_max) // update
            max_num = next_max;
    }
    
    return max_num;
}

int main(){
    int n;
    vector<vector<int>> board;
    get_input(n, board);
    int result = max_2048(n, 0, -1, board);
    printf("%d\n", result);
    return 0;
}