//BaekJoon_2467
//용액
/*
* 제한 시간 : 1s
* 정답 비율 : 32.766%
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define ll long long
using namespace std;

// 절댓값 정렬
bool abs_comp(ll n, ll m){
    return abs(n) < abs(m);
}

// get input & sort
void init(int &n, vector<ll> &num){
    ll input;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", &input);
        num.push_back(input);
    }
    sort(num.begin(), num.end(), abs_comp);
    return;
}

pair<ll, ll> resolution(int n, vector<ll> &num){
    ll temp, min_resol = num[0]+num[1];
    pair<ll, ll> result = make_pair(num[0], num[1]);

    for(int i=1; i<n-1; i++){
        temp = num[i] + num[i+1];
        if(abs_comp(temp, min_resol)){
            min_resol = temp;
            result = make_pair(num[i], num[i+1]);
        }
    }
    return result;
}
int main(){
    int n;
    vector<ll> num;
    init(n, num);
    pair<ll, ll> result = resolution(n, num);
    if(result.first < result.second){
        cout << result.first << " " << result.second << endl;
    }
    else cout << result.second << " " << result.first << endl;
    
    return 0;
}