//
//  main.cpp
//  PROGRAMMING4
//
//  Created by 유병헌 on 2020/09/10.
//  Copyright © 2020 유병헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

#define DEVIDE  (10000000 + 19)

using namespace std;

void Combination(int n, int r, std::vector<int> &result)
{
    if (result.size() == r)
    {
        // Do something...
    }
    
    int smallest = result.empty() ? 0 : result.back() + 1;
    for (int next = smallest; next < n; next++)
    {
        result.push_back(next);
        Combination(n, r, result);
        result.pop_back();
    }
}

int solution(vector<vector<int>> a) {
    int answer = -1;
    int count[a[0].size()];
    
    for(int i = 0; i < a[0].size(); i++) {
        count[i] = 0;
    }
    
    for(int i = 0; i < a[0].size(); i++) {
        for(int j = 0; j < a.size(); j++) {
            if(a[j][i] == 1) count[i]++;
        }
    }
   
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    vector<int> com;
    vector<vector<int>> v = {{0,1,0}, {1,1,1}, {1,1,0}, {0,1,1}};
    solution(v);
    Combination(4, 2, com);
    for(int i = 0; i < com.size(); i++) {
        cout << com[i] << endl;
    }

}
