//
//  main.cpp
//  CHELLENGE3-1
//
//  Created by 유병헌 on 2020/11/05.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//vector<int> solution(string s) {
//    vector<int> answer = {0, 0};
//    if(s == "1") return {0,0};
//
//    for(int i = 0; i < s.size(); i++) {
//        if(s[i] == '0') {
//            answer[1]++;
//            s.erase(s.begin() + i);
//            i--;
//        }
//    }
//    answer[0]++;
//
//    int temp = (int)s.size();
//    int n = 1;
//    int newS = 0;
//    while(temp >= 1) {
//        newS += temp%2 * n;
//        temp /= 2;
//        n *= 10;
//    }
////    cout << "newS : " << newS << endl;
//    answer[0] += solution(to_string(newS))[0];
//    answer[1] += solution(to_string(newS))[1];
//    return answer;
//}

vector<int> solution(string s) {
    vector<int> answer = {0,0};
    int zeroCount = 0;
    int binCount = 0;
    int oneCount = 0;
    
    if(s == "1") return {0, 0};
    
    while(s != "1") {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                s.erase(s.begin() + i);
                zeroCount++;
                i--;
            }
            else oneCount++;
        }
//        cout << "s : " << s << " oneCount : " << oneCount<< endl;
        binCount++;
        if(s == "1") break;
        s.clear();
        
        while(oneCount >= 1) {
            if(oneCount%2 == 1) {
                s+= '1';
            }
            else s += '0';
            oneCount /= 2;
        }
        reverse(s.begin(),s.end());
        oneCount = 0;
//        cout << "bincount : " << binCount << "s : " << s << endl;
    }
//    cout << "Last bincount : " << binCount << "Last zeroCount : " << zeroCount << endl;
    answer[0] = binCount;
    answer[1] = zeroCount;
    return answer;
}

int main(int argc, const char * argv[]) {
   
//    solution("1111111");
    cout << "[0] : " << solution("10")[0] << " [1] : " << solution("10")[1];
    return 0;
}
