//BaekJoon_14500
//테트로미노
/*
* 제한 시간 : 2s
* 정답 비율 : 34.656%
*/

#include <iostream>
#include <vector>
using namespace std;

int board[505][505] = {0,};

struct tetro{
    int size_x;
    int size_y;
    int ex_size;
    vector<int> excep;

    tetro(int x, int y, vector<int> ex): size_x(x), size_y(y), excep(ex){
        ex_size = ex.size();
    }

    private :
    bool check_range(int n, int m, int x, int y){
        if(x+size_x > n || y+size_y > m) return false;
        return true;
    }

    public :
    int calc(int n, int m, int x, int y){
        if(!check_range(n, m, x, y)) return -1;
        int total = 0;
        int index_ex = 0;

        for(int i=0; i<size_x; i++){
            for(int j=0; j<size_y; j++){
                if(index_ex < ex_size && i*size_y + j == excep[index_ex]){
                    index_ex++;
                }
                else {
                    total += board[x+i][y+j];
                }
            }
        }
        return total;
    }
};

vector<tetro> tetromino;

void init(int &n, int &m){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &board[i][j]);
        }
    }

    tetromino.push_back(tetro(1, 4, {}));
    tetromino.push_back(tetro(4, 1, {}));
    tetromino.push_back(tetro(2, 2, {}));
    tetromino.push_back(tetro(3, 2, {1, 3}));
    tetromino.push_back(tetro(3, 2, {0, 2}));
    tetromino.push_back(tetro(3, 2, {3, 5}));
    tetromino.push_back(tetro(3, 2, {2, 4}));
    tetromino.push_back(tetro(2, 3, {0, 1}));
    tetromino.push_back(tetro(2, 3, {1, 2}));
    tetromino.push_back(tetro(2, 3, {3, 4}));
    tetromino.push_back(tetro(2, 3, {4, 5}));
    tetromino.push_back(tetro(3, 2, {1, 4}));
    tetromino.push_back(tetro(3, 2, {0, 5}));
    tetromino.push_back(tetro(2, 3, {2, 3}));
    tetromino.push_back(tetro(2, 3, {0, 5}));
    tetromino.push_back(tetro(2, 3, {3, 5}));
    tetromino.push_back(tetro(2, 3, {0, 2}));
    tetromino.push_back(tetro(3, 2, {1, 5}));
    tetromino.push_back(tetro(3, 2, {0, 4}));
    
    return;
}

int game_on(int n, int m){
    int size = tetromino.size();
    int max_sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int t=0; t<size; t++){
                int sum = tetromino[t].calc(n, m, i, j);
                if(sum > max_sum){
                    max_sum = sum;
                }
            }
        }
    }
    return max_sum;
}

int main(){
    int n, m;
    init(n, m);
    int result = game_on(n, m);
    printf("%d\n", result);
    return 0;
}