#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), less<int>());
    
    vector<int> count(citations.size());
    for(int i = 0; i < citations.size(); i ++) {
        if(citations[i] >= citations.size() - i) {
            count.push_back((int)citations.size() - i);
        }
        else {
            count.push_back(citations[i]);
        }
    }
    sort(count.begin(), count.end(), greater<int>());
    answer = count.front();
    
    return answer;
}

int main() {
    cout << solution({3, 0, 6, 1, 5}) << endl;
}
ㅌㅌ
