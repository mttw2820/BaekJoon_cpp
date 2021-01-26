#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void find_start_index(vector<int> &start_index, string &pattern, int pattern_len){
    int j=0;

    for(int i=1; i<pattern_len; i++){
        while(j > 0 && pattern[j] != pattern[i]){
            j = start_index[j-1];
        }
        if(pattern[j] == pattern[i]){
            start_index[i] = ++j;
        }
    }

    return;
}

// KMP algorithm
queue<int> compare_pattern(vector<int> &start_index, string &text, string &pattern, int text_len, int pattern_len){
    int p = 0;
    queue<int> q_sp;

    for(int t=0; t<text_len; t++){
        while(p>0 && text[t] != pattern[p]){
            p = start_index[p-1];
        }
        if(text[t] == pattern[p]){
            if(p == pattern_len - 1){
                q_sp.push(t - pattern_len + 1);
                p = start_index[p];
            }
            else{
                p++;
            }
        }
    }

    return q_sp;
}

void print_result(queue<int> &result){
    int q_size = result.size();
    printf("%d\n", q_size);
    for(int i=0; i<q_size; i++){
        printf("%d ", result.front() + 1);
        result.pop();
    }
    return;
}

int main(){
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();
    vector<int> start_index(m, 0);
    find_start_index(start_index, pattern, m);
    queue<int> result = compare_pattern(start_index, text, pattern, n, m);
    print_result(result);

    return 0;
}