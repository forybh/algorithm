

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int warm_time[10000];
int eat_time[10000];

int lunchTime() {
    vector <pair<int, int>> order;
    
    for(int i = 0; i < n; i++) {
        order.push_back(make_pair(-eat_time[i], i));
    }
    sort(order.begin(), order.end());
    
    int ret = 0, beginEat = 0;
    
    for(int i = 0; i < n; i++) {
        int box = order[i].second;
        beginEat += warm_time[box];
        ret = max(ret, beginEat + eat_time[box]);
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    
    int C = 0;
    cin >> C;
    
    for(int i = 0; i < C; i++) {
        cin >> n;
        memset(warm_time, 0, sizeof(warm_time));
        memset(eat_time, 0, sizeof(eat_time));
        for(int j = 0; j < n; j++) {
            cin >> warm_time[j];
        }
        for(int k = 0; k < n; k++) {
            cin >> eat_time[k];
        }
        cout << lunchTime() << endl;
    }
}
