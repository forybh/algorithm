

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> h;

int solve(int left, int right) {
    if(left == right) return h[left];
    
    int mid = (left + right) / 2;
    
    int result = max(solve(left, mid), solve(mid + 1, right));
    
    int high = mid + 1;
    int low = mid;
    
    int height = min(h[high], h[low]);
    
    result = max(result, height * 2);
    
    while (left < low || high < right) {
        if(high < right && ((low == left) || h[high+1] > h[low-1])) {
             ++high;
            height = min(height, h[high]);
        }
        else {
             --low;
            height = min(height, h[low]);
        }
        result = max(result, height * (high - low + 1));
    }
    return result;
}


int main(int argc, const char * argv[]) {
    
    int C;
    cin >> C;
    
    int N;
    int result[50];
    for(int i = 0; i < C; ++i){
        cin >> N;
        for(int j = 0; j < N; ++j) {
            int temp = 0;
            cin >> temp;
            h.push_back(temp);
        }
        result[i] = solve(0, N-1);
        h.clear();
    }
    for(int i = 0; i < C; ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
