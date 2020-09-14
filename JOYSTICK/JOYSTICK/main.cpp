//
//  main.cpp
//  JOYSTICK
//
//  Created by 유병헌 on 2020/09/05.
//  Copyright © 2020 유병헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find(string name, int index) {
   
    for(int i = 0; i < name.size(); i++) {
        
    }
    return 0;
}

int solution(string name) {
    int answer = 0;
    
   
    if(name[0] == 'A') answer ++;
    
    for(int i = 0; i < name.size(); i ++) {
        if(name[i] == 'A') {
            answer --;
        }
        else if((int)name[i] <= 78) {
            answer += (int)name[i] - 65;
            name[i] = 'A';
        }

        else {
            answer += 91 - (int)name[i];
            name[i] = 'A';
        }
        answer ++;
    }
    answer --;
    return answer;
}

int main(int argc, const char * argv[]) {
    
    cout << solution("BBAAAB") << endl;
    return 0;
}
