
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cstring>

using namespace std;

int n = 0;
vector<int> str_length;


int concat() {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < str_length.size(); i++) {
        pq.push(str_length[i]);
    }

    int ret = 0;
    
    while(pq.size() >1) {
        int min1 = pq.top(); pq.pop();
        int min2 = pq.top(); pq.pop();
        pq.push(min1+min2);
        ret += (min1 + min2);
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    int C = 0;
    int temp = 0;
    cin >> C;
    for(int i = 0; i < C; i++) {
        str_length.clear();
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> temp;
            str_length.push_back(temp);
        }
        cout << concat() << endl;
    }
    
}
