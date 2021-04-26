//BaekJoon_14891
//톱니바퀴
/*
* 제한 시간 : 2s
* 정답 비율 : 52.643%
*/

#include <iostream>
#include <vector>
#include <string>
#define CLOCKWISE 1
#define NONCLOCKWISE -1
using namespace std;

struct wheel{
    string mag;
    int left = 6;
    int right = 2;

    wheel(string m) : mag(m) {}

    public:
    void turn_wheel(int dir){
        if(dir == CLOCKWISE){
            left --;
            right --;

            if(left < 0) left += 8;
            if(right < 0) right += 8;
        }
        else {
            left++;
            right++;

            if(left > 7) left -= 8;
            if(right > 7) right -= 8;
        }
    }

    char get_left(){
        return mag[left];
    }
    char get_right(){
        return mag[right];
    }
    bool is_mid_NORTH(){
        int mid = right - 2;
        if(mid < 0) mid += 8;

        return mag[mid]=='0';
    }
};

void get_input(vector<wheel> &machine){
    string input;

    for(int i=0; i<4; i++){
        cin >> input;
        machine.push_back(wheel(input));
    }
}

void turn_left(int index, int dir, vector<wheel> &machine){
    if(index < 0) return;
    if(machine[index+1].get_left() == machine[index].get_right()) return;
    int next_dir = 0-dir;
    turn_left(index-1, next_dir, machine);
    machine[index].turn_wheel(next_dir);
    return;
}
void turn_right(int index, int dir, vector<wheel> &machine){
    if(index >= 4) return;
    if(machine[index-1].get_right() == machine[index].get_left()) return;
    int next_dir = 0 - dir;
    turn_right(index+1, next_dir, machine);
    machine[index].turn_wheel(next_dir);
    return;
}
void machine_on(vector<wheel> &machine){
    int n, wheel_num, dir;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &wheel_num, &dir);

        // move left
        int left = wheel_num -2;
        turn_left(left, dir, machine);
        int right = wheel_num;
        turn_right(right, dir, machine);

        // move (wheel_num)
        machine[wheel_num-1].turn_wheel(dir);
    }
}

int calc_score(vector<wheel> &machine){
    int total_score = 0;
    int score = 1;
    for(int i=0; i<4; i++){
        if(!machine[i].is_mid_NORTH()){
            total_score += score;
        }
        score *= 2;
    }
    return total_score;
}
int main(){
    vector<wheel> machine;
    get_input(machine);
    machine_on(machine);
    int score = calc_score(machine);
    printf("%d\n", score);
    return 0;
}