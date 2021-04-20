//BaekJoon_17219
//비밀번호 찾기
/*
* 제한 시간 : 5s
* 정답 비율 : 69.532%
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

void get_input(int &n, int &m, map<string, string> &memo){
    char site[25], pwd[25];
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%s %s", &site, &pwd);
        memo[site] = pwd;
    }
    return;
}

void search_pwd(int m, map<string, string> &memo){
    char site[25];
    for(int i=0; i<m; i++){
        scanf("%s", &site);
        printf("%s\n", memo[site].c_str());
    }
    return;
}
int main(){
    int n, m;
    map<string, string> memo;
    get_input(n, m, memo);
    search_pwd(m, memo);

    return 0;
}