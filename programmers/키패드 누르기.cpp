#include <string>
#include <vector>
#include <math.h>
using namespace std;

struct hd{
    int h;
    bool ismid = false;
    hd(int height, bool mid): h(height), ismid(mid){}
};

int move_finger(int height, int line, hd &hand){
    int move = abs(height - hand.h);
    hand.h = height;

    if(line != 2 && hand.ismid){
        move ++;
        hand.ismid = false;
    }
    else if(line == 2 && !hand.ismid){
        move++;
        hand.ismid = true;
    }

    return move;
}

string dial_mid(int height, int line, string hand, hd &left, hd &right){
    hd temp_left = left;
    hd temp_right = right;

    int move_left = move_finger(height, line, temp_left);
    int move_right = move_finger(height, line, temp_right);

    if(move_left > move_right){
        right = temp_right;
        return "R";
    }
    else if(move_left < move_right){
        left = temp_left;
        return "L";
    }
    else {
        if(hand == "left"){
            left = temp_left;
            return "L";
        }
        else {
            right = temp_right;
            return "R";
        }
    }
}

void print_dial(hd &left, hd &right){
    int dial_left = left.h * 3 + 1;
    if(left.ismid) dial_left ++;
    int dial_right = right.h * 3 + 3;
    if(right.ismid) dial_right --;

    printf("left %d, right %d\n", dial_left, dial_right);
    return;
}
void dial(string &ans, int number, string hand, hd &left, hd &right){
    // set position
    int height = number / 3;
    int line = number % 3;
    if(line == 0) height--;

    if(line == 1) {         // left
        move_finger(height, line, left);
        ans += "L";
    }
    else if(line == 0) {    // right
        move_finger(height, line, right);
        ans += "R";
    }
    else {                  // mid
        ans += dial_mid(height, line, hand, left, right);
    }
    //print_dial(left, right);
    return;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    // init
    hd left(3, false);
    hd right(3, false);

    int s_num = numbers.size();
    for(int i=0; i<s_num; i++){
        if(numbers[i] == 0) numbers[i] = 11;
        dial(answer, numbers[i], hand, left, right);
    }

    return answer;
}