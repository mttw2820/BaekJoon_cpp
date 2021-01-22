//BaekJoon_1043
//거짓말
/*
* 제한 시간 : 2s
* 정답 비율 : 33.551%
*/

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

void init(int ppl, int tppl, vector<int> &truth, int (&parent)[55]){
    int input = 0;
    for(int i=0; i<tppl; i++){
        scanf("%d", &input);
        truth.push_back(input);
    }

    for(int i=1; i<=ppl; i++){
        parent[i] = i;
    }

    return;
}

int get_parent(int (&parent)[55], int g){
    if(parent[g] == g){
        return g;
    }
    else{
        return parent[g] = get_parent(parent, parent[g]);
    }
}

void make_party_group(int party, int (&parent)[55], bitset<55> (&party_list)[55]){
    int pppl, input, g_parent;
    for(int i=0; i<party; i++){
        scanf("%d", &pppl);
        for(int p=0; p<pppl; p++){
            scanf("%d", &input);
            party_list[i][input] = 1;
            if(p==0) g_parent = get_parent(parent, input);
            else{
                parent[get_parent(parent, input)] = g_parent;
            }
        }
    }
    return;
}
void get_truth_bit(int ppl, int tppl, int (&parent)[55], vector<int> &truth, bitset<55> &truth_bit){

    for(int i=0; i<tppl; i++){
        int t = truth[i];
        int tp = get_parent(parent, t);
        truth_bit[t] = 1;

        for(int j=1; j<=ppl; j++){
            if(tp == get_parent(parent, j)){
                truth_bit[j] = 1;
            }
        }
    }
    return;
}

int count_lie_party(int party, bitset<55> &truth_bit, bitset<55> (&party_list)[55]){
    int cnt = 0;
    bitset<55> comp;
    for(int i=0; i<party; i++){
        comp.reset();
        comp = truth_bit & party_list[i];
        if(!comp.any()) {
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int ppl, party, tppl, input;
    int parent[55];
    vector<int> truth;
    bitset<55> truth_bit;
    bitset<55> party_list[55];

    scanf("%d %d", &ppl, &party);
    scanf("%d", &tppl);

    init(ppl, tppl, truth, parent);
    make_party_group(party, parent, party_list);
    get_truth_bit(ppl, tppl, parent, truth, truth_bit);
    int lie_party = count_lie_party(party, truth_bit, party_list);
    printf("%d\n", lie_party);

    return 0;
}