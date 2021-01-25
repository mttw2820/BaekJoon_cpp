#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
using namespace std;

pair<int, int> bfs(int sp, int ep){
    int time = -1;
    bool isfound = false;
    bitset<200002> check;
    queue<int> q;

    q.push(sp);
    check.reset();

    int size, now, cnt = 0;
    while(!q.empty()){
        size = q.size();
        time++;
        
        for(int i=0; i<size; i++){
            now = q.front();
            check[now] = true;
            if(now == ep){
                isfound = true;
                cnt++;
            }
            q.pop();

            // 이미 찾았다면 이번 time만 찾으면 된다.
            if(isfound) continue;

            int next = now + 1;
            if(!check[next]) {
                q.push(next);
            }
            next = now - 1;
            if(next>=0 && !check[next]){
                q.push(next);
            }
            next = now * 2;
            if((next <= ep) || (next-ep <= ep-now)){
                q.push(next);
            } 
        }
        if(isfound) break;
    }

    return make_pair(time, cnt);
}
int main(){
    int subin, sister;
    scanf("%d %d", &subin, &sister);
    pair<int, int> result = bfs(subin, sister);
    printf("%d\n%d\n", result.first, result.second);
    return 0;
}