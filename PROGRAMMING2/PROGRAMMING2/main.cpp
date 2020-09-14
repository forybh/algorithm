//
//  main.cpp
//  PROGRAMMING2
//
//  Created by 유병헌 on 2020/09/10.
//  Copyright © 2020 유병헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int v[n][n];
    
    int num = 1;
    int x = 0;
    int y = 0;
    int limit = n;
    
    while(true) {
        for(int i = 0; i < limit; i++) {
            v[x][y] = num;
            x++;
            num++;
        }
        limit--;
        x--;
        y++;
        
        if(limit == 0) break;
        
        for(int i = 0; i < limit; i++) {
            v[x][y] = num;
            y++;
            num++;
        }
        y--;
        limit--;
        x--;
        y--;
        
        if(limit == 0) break;
        
        for(int i = 0; i < limit; i++) {
            v[x][y] = num;
            num++;
            x--;
            y--;
        }
        x++;
        y++;
        limit--;
        x++;
        
        if(limit == 0) break;
    }
    num--;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i+1; j++) {
            answer.push_back(v[i][j]);
        }
    }
    for(int i = 0; i < num; i++) {
        cout << answer[i] << " " ;
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    solution(4);
}
