#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    ans = {0,0};
    
    int o;
    int d[3] = {0,0,0};
    d[0] = pow(v[0][0] - v[1][0], 2) + pow(v[0][1] - v[1][1], 2);
    d[1] = pow(v[0][0] - v[2][0], 2) + pow(v[0][1] - v[2][1], 2);
    d[2] = pow(v[2][0] - v[1][0], 2) + pow(v[2][1] - v[1][1], 2);
    
    if(d[0] > d[1] && d[0] > d[2]) {
        o = 2;
        ans[0] = v[0][0] + (v[1][0] - v[2][0]);
        ans[1] = v[0][1] + (v[1][1] - v[2][1]);
    }
    else if (d[1] > d[0] && d[1] > d[2]) {
        o = 1;
        ans[0] = v[0][0] + (v[2][0] - v[1][0]);
        ans[1] = v[0][1] + (v[2][1] - v[1][1]);
    }
    else {
        ans[0] = v[1][0] + (v[2][0] - v[2][0]);
        ans[1] = v[1][1] + (v[2][1] - v[2][1]);
    }

    return ans;
}

int main(int argc, const char * argv[]) {
    
   
    
    
    cout << solution({{1, 1}, {2, 2}, {1, 2}})[0] << " " << solution({{1, 1}, {2, 2}, {1, 2}})[1] << endl;
    
        
    
    return 0;
}
