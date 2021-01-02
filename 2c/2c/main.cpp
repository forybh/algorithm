//
//  main.cpp
//  2c
//
//  Created by 유병헌 on 2020/12/22.
//

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int solution(int N, vector<int> sequence) {
    int answer = 0;
    
    if(sequence[0] - 1 < sequence.size() - (sequence[0] - 1)) {
        answer += sequence[0] - 1;
    }
    else answer += sequence.size() - (sequence[0] - 1);
    
    for(int i = 0; i < sequence.size()-1; i++) {
        if(abs(sequence[i] - sequence[i+1]) < abs((int)sequence.size()-(sequence[i] - sequence[i+1]))) {
            answer += abs(sequence[i] - sequence[i+1]);
        }
        else answer += abs((int)sequence.size()-(sequence[i] - sequence[i+1]));
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << solution(5, {3,5,4,1,2});
    return 0;
}
