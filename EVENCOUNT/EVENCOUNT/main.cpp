
#include <iostream>
#include <string>
#include <vector>

#define X 10000019

using namespace std;

int solution(vector<vector<int>> a) {
    int answer = -1;
    vector<int> count;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[0].size(); j++) {
            if(a[i][j] == 1) {
                count[j]++;
            }
        }
    }
    int allCount = 0;
    for(int i = 0; i < count.size(); i++) {
        allCount += count[i];
    }
    if(allCount % 2 == 1 || allCount == 0) return 0;
    
    for(int i = 0; i < count.size(); i++) {
        if(count[i] != 0) {
            
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    cout << X << endl;
    return 0;
}
