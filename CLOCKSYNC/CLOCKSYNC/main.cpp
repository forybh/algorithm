

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
#define MAX_NUM 1048576;
int clocks[16] = {0};
//vector<vector<int>> switchs{{0, 1, 2}, {3, 8, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}};

vector<vector<int> > switchs({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});

void push(int n) {
    unsigned long size = switchs[n].size();
    for(int i =0; i < size; ++i) {
        clocks[switchs[n][i]] += 3;
        if(clocks[switchs[n][i]] == 15) {
            clocks[switchs[n][i]] = 3;
        }
    }
}

bool aligned() {
    bool all = true;
    for(int i = 0; i < 16; ++i) {
        if(clocks[i] != 12) {
            all = false;
            break;
        }
    }
    return all;
}

int solve(int n) {
    if(n == 10) {
        if(aligned()) return 0;
        else return MAX_NUM;
    }
    int result = MAX_NUM;
    
    for(int i = 0; i < 4; ++i) {
        result = min(result, i + solve(n+1));
        push(n);
    }
    return result;
}


int main(int argc, const char * argv[]) {
    
    int c = 0;
    cin >> c;
    
    int result[30] = {0};
    for(int j = 0; j < c; j++) {
        memset(clocks, 0, sizeof(clocks));
        for(int i = 0; i < 16; ++i) {
            cin >> clocks[i];
        }
        result[j] = solve(0);
    }
    
    for(int i =0; i < c; i++) {
        if(result[i] == 1048576) {
            cout << -1 << endl;
        }
        else cout << result[i] << endl;
    }
    
    
    
    return 0;
}
