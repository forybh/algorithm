//
//  main.cpp
//  TODEMICAL
//
//  Created by 유병헌 on 2020/10/08.
//  Copyright © 2020 유병헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    stack<int> s;
    stack<int> s2;
    while(n >= 1) {
        s.push(n % 3);
        n = n/3;
    }
    while (!s.empty()) {
        s2.push(s.top());
        s.pop();
    }
    while (!s2.empty()) {
        answer += s2.top() * pow(3, s2.size()-1);
        s2.pop();
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    cout << solution(125);
    
    return 0;
}
