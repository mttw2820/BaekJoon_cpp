//BaekJoon_2096
//내려가기
/*
* 제한 시간 : 1s
* 정답 비율 : 36.595%
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> game(int line){
    int present_line[3];
    int dp_min[2][3] = {0,};
    int dp_max[2][3] = {0,};

    scanf("%d %d %d", &present_line[0], &present_line[1], &present_line[2]);
    dp_min[0][0] = dp_max[0][0] = present_line[0];
    dp_min[0][1] = dp_max[0][1] = present_line[1];
    dp_min[0][2] = dp_max[0][2] = present_line[2];

    for(int i=1; i<line; i++){
        int dp_now = i&1;
        int dp_prev = 1-dp_now;

        scanf("%d %d %d", &present_line[0], &present_line[1], &present_line[2]);
        
        dp_min[dp_now][0] = min(dp_min[dp_prev][0], dp_min[dp_prev][1]) + present_line[0];
        dp_max[dp_now][0] = max(dp_max[dp_prev][0], dp_max[dp_prev][1]) + present_line[0];

        dp_min[dp_now][1] = min(dp_min[dp_prev][0], min(dp_min[dp_prev][1], dp_min[dp_prev][2])) + present_line[1];
        dp_max[dp_now][1] = max(dp_max[dp_prev][0], max(dp_max[dp_prev][1], dp_max[dp_prev][2])) + present_line[1];

        dp_min[dp_now][2] = min(dp_min[dp_prev][1], dp_min[dp_prev][2]) + present_line[2];
        dp_max[dp_now][2] = max(dp_max[dp_prev][1], dp_max[dp_prev][2]) + present_line[2];
    }

    int score_index = (line-1) & 1;
    int min_score = min(dp_min[score_index][0], min(dp_min[score_index][1], dp_min[score_index][2]));
    int max_score = max(dp_max[score_index][0], max(dp_max[score_index][1], dp_max[score_index][2]));

    return make_pair(max_score, min_score);
}
int main(){
    int line;
    scanf("%d", &line);

    pair<int, int> score = game(line);
    printf("%d %d\n", score.first, score.second);
    return 0;
}