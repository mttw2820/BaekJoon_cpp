//BaekJoon_15684
//사다리 조작
/*
* 제한 시간 : 2s
* 정답 비율 : 21.194%
*/

#include <iostream>
#include <vector>
#define MAX 9999999
using namespace std;

void get_input(int &n, int &m, int &h, vector<int> (&hori)[35]){
    int a, b;
    vector<int> temp(15, 0);

    scanf("%d %d %d", &n, &m, &h);

    for(int i=0; i<=h; i++) hori[i] = temp;
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        hori[a][b] = b+1;
        hori[a][b+1] = b;
    }
    return;
}

bool is_game_end(int n, int h, vector<int> (&hori)[35]){
    for(int vert = 1; vert<=n; vert++){
        int now = vert;
        for(int i=1; i<=h; i++){
            if(hori[i][now] != 0)
                now = hori[i][now];
        }
        if(now != vert) return false;
    }

    return true;
}
int count_least_hori(int n, int h, int index, int count, vector<int> (&hori)[35]){
    if(is_game_end(n, h, hori)){
        return count;
    }
    if(index >= (n-1)*h) {
        return MAX;
    }
    if(count >= 3) return MAX;
    
    int line = index / (n-1) + 1;
    int from = index % (n-1) + 1;

    // 추가하지 않고 최소
    int least_count = count_least_hori(n, h, index + 1, count, hori);
    
    if(hori[line][from] == 0 && hori[line][from+1] == 0) {
        // 해당 위치에 가로선 추가
        hori[line][from] = from + 1;
        hori[line][from+1] = from;
        int temp = count_least_hori(n, h, index + 1, count + 1, hori);
        if(temp < least_count) least_count = temp;
        hori[line][from] = 0;
        hori[line][from+1] = 0;
    }
    return least_count;
}
int main(){
    int n, m, h;
    vector<int> hori[35];
    get_input(n, m, h, hori);
    int result = count_least_hori(n, h, 0, 0, hori);
    if(result == MAX) result = -1;
    printf("%d\n", result);
    return 0;
}