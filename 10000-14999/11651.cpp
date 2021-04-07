//BaekJoon_11651
//좌표 정렬하기 2
/*
* 제한 시간 : 1s
* 정답 비율 : 69.319%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pos{
    int x;
    int y;
    pos(int x, int y) : x(x), y(y) {}
};

void get_input(int &n, vector<pos> &vec){
    pos input_pos(0, 0);
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &input_pos.x, &input_pos.y);
        vec.push_back(input_pos);
    }

    return;
}
bool comp_pos(pos p1, pos p2){
    if(p1.y == p2.y) return p1.x < p2.x;
    return p1.y < p2.y;
}

void print_result(int n, vector<pos> &vec){
    for(int i=0; i<n; i++){
        printf("%d %d\n", vec[i].x, vec[i].y);
    }
    return;
}

int main(){
    int n;
    vector<pos> vec;
    get_input(n, vec);
    sort(vec.begin(), vec.end(), comp_pos);
    print_result(n, vec);

    return 0;
}