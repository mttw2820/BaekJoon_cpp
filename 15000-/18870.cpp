//BaekJoon_18870
//좌표 압축
/*
* 제한 시간 : 2s
* 정답 비율 : 54.260%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point{
    int original;
    int index;
    int compressed;

    point(int ori, int in, int comp): original(ori), index(in), compressed(comp){}
};

void get_input(int &n, vector<point> &vec){
    scanf("%d", &n);
    int input = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &input);
        vec.push_back(point(input, i, 0));
    }
    return;
}

bool comp_original(point p1, point p2){
    return p1.original < p2.original;
}
bool comp_index(point p1, point p2){
    return p1.index < p2.index;
}
void compress_number(int n, vector<point> &vec){
    sort(vec.begin(), vec.end(), comp_original);
    int count = 0;
    for(int i=1; i<n; i++){
        if(vec[i].original != vec[i-1].original) count++;
        vec[i].compressed = count;
    }
    return;
}

void print_result(int n, vector<point> &vec){
    sort(vec.begin(), vec.end(), comp_index);
    for(int i=0; i<n; i++){
        printf("%d ", vec[i].compressed);
    }
    return;
}
int main(){
    int n;
    vector<point> vec;
    get_input(n, vec);
    compress_number(n, vec);
    print_result(n, vec);
    return 0;
}