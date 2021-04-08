//BaekJoon_2630
//색종이 만들기
/*
* 제한 시간 : 1s
* 정답 비율 : 71.212%
*/

#include <iostream>
#define MIXED 0
#define WHITE 1
#define BLUE -1
using namespace std;

struct paper{
    int blue;
    int white;

    paper(int b, int w) : blue(b), white(w) {}

    paper operator+(paper p) {
        return paper(blue + p.blue, white + p.white);
    }
};

int paper_map[130][130] = {0,};

void get_input(int &n){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &paper_map[i][j]);
        }
    }
    return;
}

int check_color(int x, int y, int size){
    bool is_white = false;
    bool is_blue = false;
    bool is_mixed = false;

    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(paper_map[i][j] == 0) is_white = true;
            else is_blue = true;

            if(is_blue && is_white) {
                is_mixed = true;
                break;
            }
        }
    }

    if(is_mixed) return MIXED;
    else if(is_white) return WHITE;
    else return BLUE;
}

paper crop_paper(int x, int y, int size, int n){
    int color = check_color(x, y, size);
    if(color == WHITE) return paper(0, 1);
    else if(color == BLUE) return paper(1, 0);
    else {  // MIXED - split
        paper total(0, 0);
        paper cropped(0, 0);
        
        size /= 2;
        total = crop_paper(x, y, size, n) + crop_paper(x+size, y, size, n) + crop_paper(x, y+size, size, n) + crop_paper(x+size, y+size, size, n);
        
        return total;
    }
}

void print_result(paper result){
    printf("%d\n%d\n", result.white, result.blue);
}

int main(){
    int n;

    get_input(n);
    paper result = crop_paper(0, 0, n, n);
    print_result(result);

    return 0;
}