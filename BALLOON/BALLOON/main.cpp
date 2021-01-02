
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int left = 0;
    int right = (int)a.size() -1;
    if(a.size() < 3) {
        return 0;
    }
    
    for(int i = 0; i < a.size() - 1; i++) {
        if(a[i] > a[i+1]) {
            left = i+1;
        }
        else break;
    }
    for(int i = (int)a.size(); i > 0; i--) {
        if(a[i-1] > a[i-2]) {
            right = i-2;
        }
        else break;
    }
    
    if(left == right) {
        right ++;
    }
    vector<int> temp;
    temp.assign(a.begin() + left + 1, a.begin() + right - 1);
//    for(int i = left + 1; i < right; i ++) {
//        if(a[i] > a[left] && a[i] > a[right]) {
//            a.erase(a.begin() + i);
//            i--;
//        }
//    }
    
    
//    cout << solution(temp) << endl;
    answer = (int)a.size() - (right - left - 1) + solution(temp);
    
   
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    cout << solution({9,-1,-5});
}
