//BaekJoon_1764
//듣보잡
/*
* 제한 시간 : 2s
* 정답 비율 : 39.700%
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void get_input(int &n, int &m, vector<string> &unseen, vector<string> &unheard){
    char input[25];
    //string input = "";
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%s", &input);
        unheard.push_back(input);
    }
    for(int i=0; i<m; i++){
        scanf("%s", &input);
        unseen.push_back(input);
    }
    
    sort(unheard.begin(), unheard.end());
    sort(unseen.begin(), unseen.end());

    return;
}

int find_inter(int n, int m, vector<string> &unseen, vector<string> &unheard, vector<string> &both){
    int count_inter = 0;
    int index_s = 0, index_h = 0;
    while(index_h < n && index_s < m){
        if(unseen[index_s] == unheard[index_h]){
            count_inter++;
            both.push_back(unseen[index_s]);
            index_s++; index_h++;
        }
        else if(unseen[index_s].compare(unheard[index_h]) < 0){
            index_s++;
        }
        else index_h++;
    }

    sort(both.begin(), both.end());
    return count_inter;
}

void print_result(int cnt, vector<string> &both){
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++){
        printf("%s\n", both[i].c_str());
    }
    return;
}

int main(){
    int n, m;
    vector<string> unseen;
    vector<string> unheard;
    vector<string> both;

    get_input(n, m, unseen, unheard);
    int cnt_inter = find_inter(n, m, unseen, unheard, both);
    print_result(cnt_inter, both);

    return 0;
}