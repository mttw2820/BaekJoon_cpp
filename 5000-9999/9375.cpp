//BaekJoon_9375
//패션왕 신해빈
/*
* 제한 시간 : 1s
* 정답 비율 : 54.189%
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct cloth {
    string c_kind;
    int count;

    cloth(string s, int c) : c_kind(s), count(c) {}
};

void check_fashion(vector<cloth> &fashion, string c_sort){
    auto it = fashion.begin();
    for(;it!= fashion.end(); it++){
        if((it->c_kind) == c_sort) {
            it->count++;
            return;
        }
    }
    fashion.push_back(cloth(c_sort, 1));
    return;
}
void get_input(vector<cloth> &fashion){
    int n;
    scanf("%d", &n);

    string c_name, c_sort;
    for(int i=0; i<n; i++){
        cin >> c_name >> c_sort;
        check_fashion(fashion, c_sort);
    }
}

long long make_set(vector<cloth> &fashion){
    int size = fashion.size();
    long long result = 1;

    if(size == 1) return fashion[0].count;

    for(int i=0; i<size; i++){
        result *= fashion[i].count + 1;
    } 
    return result - 1;
}

void solution(){
    vector<cloth> fashion;
    get_input(fashion);
    long long result = make_set(fashion);
    printf("%lld\n", result);
}

int main(){
    int testcase = 0;
    scanf("%d", &testcase);
    for(int i=0; i<testcase; i++){
        solution();
    }
    return 0;
}