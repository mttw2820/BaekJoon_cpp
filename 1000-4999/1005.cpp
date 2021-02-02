//BaekJoon_1005
//ACM Craft
/*
* 제한 시간 : 1s
* 정답 비율 : 21.625%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> next_node[1001];
void init(int &buildings, int &orders, int &question, vector<int> &indegree, vector<int> &cons_time){
    // get input
    int input = 0;
    scanf("%d %d", &buildings, &orders);
    for(int i=1; i<=buildings; i++){
        next_node[i].clear();
        indegree[i] = 0;
        scanf("%d", &cons_time[i]);
    }

    int x, y;
    for(int i=0; i<orders; i++){
        scanf("%d %d", &x, &y);
        next_node[x].push_back(y);
        indegree[y]++;
    }

    scanf("%d", &question);

    return;
}

int calc_build_time(int question, int buildings, vector<int> &indegree, vector<int> &cons_time){
    vector<int> calc(buildings+1, 0);
    queue<int> q;
    for(int i=1; i<=buildings; i++){
        if(indegree[i] == 0){
            if(i == question){
                return cons_time[question];
            }
            q.push(i);
            calc[i] = cons_time[i];
            calc.push_back(cons_time[question]);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == question) return calc[question];

        int next, nsize = next_node[now].size();
        for(int i=0; i<nsize; i++){
            next = next_node[now][i];
            indegree[next]--;
            if(calc[next] < calc[now] + cons_time[next]){
                calc[next] = calc[now] + cons_time[next];
            }
            if(indegree[next] == 0) q.push(next);
        }
    }
}
int main(){
    int testcase, buildings, orders, question;
    vector<int> indegree(1010, 0);
    vector<int> cons_time(1010, 0);
    scanf("%d", &testcase);

    for(int t=0; t<testcase; t++){
        init(buildings, orders, question, indegree, cons_time);
        int result = calc_build_time(question, buildings, indegree, cons_time);
        printf("%d\n", result);
    }
    return 0;
}