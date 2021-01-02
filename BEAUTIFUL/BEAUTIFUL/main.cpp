//
//  main.cpp
//  BEAUTIFUL
//
//  Created by 유병헌 on 2020/10/08.
//  Copyright © 2020 유병헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int maxI(string s) {
//    vector<int> max;
//    max.push_back(0);
    int max = 0;
    for(int i = 0; i < s.size()-1; i++) {
//        for(int j = i+1; j <s.size(); j++) {
//            if(s[i] != s[j]) {
//                max.push_back(j-i);
//            }
//        }
        for(int j = (int)s.size() - 1; j > i; j--) {
            if(s[i] != s[j]) {
//                max.push_back(j-i);
                if((j-i) >= s.size() - i - 1) return j-i;
                if((j-i) > max) {
                    max = j - i;
                }
                break;
            }
        }
//        if((temp-i) >= s.size() - i -1) break;
    }
//    sort(max.begin(), max.end(), greater<>());
//    return max[0];
    return max;
}

long long solution(string s) {
    long long answer = 0;
    
    for(int i = 0; i < s.size()-1; i++) {
        for(int j = 2; j <= s.size() - i; j++) {
            answer += maxI(s.substr(i,j));
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    
    cout << solution("baby") << endl;
    return 0;
}
