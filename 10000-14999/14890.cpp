//BaekJoon_14890
//경사로
/*
* 제한 시간 : 2s
* 정답 비율 : 54.445%
*/

#include <iostream>
using namespace std;

int navi[105][105] = {0,};

void get_input(int &n, int &len){
    scanf("%d %d", &n, &len);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &navi[i][j]);
        }
    }
    return;
}

bool comp_height(int a, int b){
    if(a-b>1 || b-a>1) return true;
    else return false;
}

int make_hori_road(int n, int len){
    int cnt_road = 0;
    bool broke = false;

    for(int i=0; i<n; i++){
        int cnt_same_h = 1;
        broke = false;
        for(int j=1; j<n; j++){
            if(navi[i][j-1] == navi[i][j]) cnt_same_h++;
            else {
                if(comp_height(navi[i][j-1], navi[i][j])){
                    broke = true;
                    break;
                }
                if(navi[i][j-1] < navi[i][j]){  // go up
                    if(cnt_same_h < len) {
                        broke = true;
                        break;
                    }
                    else cnt_same_h = 1;
                }
                else {      // go down
                    cnt_same_h = 1;
                    for(int k=1; k<len; k++){
                        if(k>=n) break;
                        if(navi[i][j] == navi[i][j+k])
                            cnt_same_h++;
                        else break;
                    }
                    if(cnt_same_h == len){
                        j = j+len-1; 
                        cnt_same_h = 0;
                    }
                    else {
                        broke = true;
                        break;
                    }
                }
            }
        }
        if(!broke) cnt_road++;
    }
    return cnt_road;
}


int make_vert_road(int n, int len){
    int cnt_road = 0;
    bool broke = false;

    for(int j=0; j<n; j++){
        int cnt_same_h = 1;
        broke = false;
        for(int i=1; i<n; i++){
            if(navi[i-1][j] == navi[i][j]) cnt_same_h++;
            else {
                if(comp_height(navi[i-1][j], navi[i][j])){
                    broke = true;
                    break;
                }
                if(navi[i-1][j] < navi[i][j]){  // go up
                    if(cnt_same_h < len) {
                        broke = true;
                        break;
                    }
                    else cnt_same_h = 1;
                }
                else {      // go down
                    cnt_same_h = 1;
                    for(int k=1; k<len; k++){
                        if(k>=n) break;
                        if(navi[i][j] == navi[i+k][j])
                            cnt_same_h++;
                        else break;
                    }
                    if(cnt_same_h == len){
                        i = i + len - 1;
                        cnt_same_h = 0;
                    }
                    else {
                        broke = true;
                        break;
                    }
                }
            }
        }
        if(!broke) cnt_road++;
    }
    return cnt_road;
}
int main(){
    int n, len;
    get_input(n, len);
    int total_road = make_hori_road(n, len);
    total_road += make_vert_road(n, len);
    printf("%d\n", total_road);

    return 0;
}