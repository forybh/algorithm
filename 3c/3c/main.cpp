//
//  main.cpp
//  3c
//
//  Created by 유병헌 on 2020/12/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> convert(int num) {
    vector<int> result;
    for(int i = 1; num>0; i*=10) {
        int binary = num % 2;
        result.insert(result.begin(), binary);
        num /=2;
    }
    return result;
}
int comb(int a, int b) {
    int ret = 1;
    for(int i = 0; i < b; i++) {
        ret *= a;
        a--;
    }
    for(int i = 0; i < b; i++) {
        ret /= b;
        b--;
    }
  
    return ret;
}
int solution(int n) {
    int answer = 0;
    int count = 0;
    vector<int> b = convert(n);
    
    for(int i = 0; i < b.size(); i++) {
        
        if(b[i] == 1) {
            count ++;
        }
    }
    
    cout << count << endl;
    for(int i = 0; i < b.size(); i++) {
        if(b[i] == 1) {
            cout << "b.size : " << b.size();
            cout << "count : " << count;
            answer += comb((int)b.size()-1, count);
            cout << " comb : " << answer;
            b.erase(b.begin());
            count--;
        }
    }
    return answer;
}


int main(int argc, const char * argv[]) {
   
    cout << solution(9);
    
    return 0;
}
