//
//  main.cpp
//  KAKAO1
//
//  Created by 유병헌 on 2020/09/12.
//  Copyright © 2020 유병헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char toLower(char c) {
    c = c + 32;
    return (char)c;
}

string solution(string new_id) {
    string answer = "";
   
    for(int i = 0; i < new_id.size(); i++) {
        if((int)new_id[i] >= 65 && (int)new_id[i] <= 90) {
            new_id[i] = toLower(new_id[i]);
        }
        if((int)new_id[i] != 45 && (int)new_id[i] != 46 && (int)new_id[i] != 95 && (!((int)new_id[i] >= 48 && (int)new_id[i] <= 57))  && (!((int)new_id[i] >=97 && (int)new_id[i] <= 122)) ) {
            new_id.erase(i, 1);
            if(new_id.size() == 0) break;
            i--;
        }
        if((int)new_id[i] == 46 && (int)new_id[i+1] == 46) {
            if(i == new_id.size() -1) break;
            new_id.erase(i, 1);
            if(new_id.size() == 0) break;
            i--;
        }
    }
    if(new_id[0] == '.') {
        new_id.erase(0 , 1);
    }
    if(new_id[new_id.size() - 1] == '.') {
        new_id.erase(new_id.size() - 1, 1);
    }
    if(new_id.empty()) {
        new_id.push_back('a');
    }
    if(new_id.size() > 15) {
        new_id.erase(15);
    }
    if((int)new_id[new_id.size()-1] == 46){
        new_id.erase(new_id.size()-1, 1);
    }
    if(new_id.size() < 3) {
        while (new_id.size() < 3) {
            new_id.push_back(new_id[new_id.size()-1]);
        }
    }
    answer = new_id;
    return answer;
}
int main(int argc, const char * argv[]) {
    cout << solution("=.=");
    return 0;
}
