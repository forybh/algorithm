//
//  main.cpp
//  CCCC
//
//  Created by 유병헌 on 2020/12/22.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int a = 0;

int solution(vector<int> arr) {

    int count = 1;
    vector<int> new_arr;
    
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == arr[i+1]) {
            if(i != arr.size()-1) count++;
            else {
                count++;
                new_arr.push_back(count);
            }
        }
        else {
            new_arr.push_back(count);
            count = 1;
        }
    }
    if(new_arr.size() == 1 && new_arr[0] == 1) {
        return a + 1;
    }
    a++;
    
    return solution(new_arr);
}

int main(int argc, const char * argv[]) {
    cout << solution({2});
    //cout << solution({1, 1, 3, 3, 2, 2, 4, 5, 1, 1, 1, 3, 3, 3});
    
}
