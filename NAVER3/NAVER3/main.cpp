//
//  main.cpp
//  NAVER3
//
//  Created by 유병헌 on 2020/12/21.
//

#include <iostream>

using namespace std;

bool solution(string s){
    int p_num=0, y_num=0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == 'p' || s[i] == 'P') {
            p_num++;
        }
        else if(s[i] == 'y' || s[i] == 'Y') {
            y_num++;
        }
    }
    return p_num == y_num;
    
}

int main(int argc, const char * argv[]) {
    
    cout << solution("pyyp");
    return 0;
}
