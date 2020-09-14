//
//  main.cpp
//  PROGRAMMING1
//
//  Created by 유병헌 on 2020/09/10.
//  Copyright © 2020 유병헌. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    vector<int> answer;
    for(int i = 0; i < numbers.size() - 1; i++) {
        for(int k = i+1; k < numbers.size(); k++) {
            answer.push_back(numbers[i] + numbers[k]);
        }
    }
    
    
    sort(answer.begin(), answer.end());
    vector<int>::iterator it;
    

    for(it = answer.begin(); it != answer.end() - 1; it ++) {
        if(*it == it[1]) {
            answer.erase(it);
            it--;
        }
    }
    
    for(it = answer.begin(); it != answer.end(); it ++) {
        cout << *it << endl;
    }
    
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    solution({5,0,2,7});
    
    
    return 0;
}
