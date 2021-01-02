#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    if(numbers.size() == 0) return 0;
    int a = numbers[numbers.size()-1];
    int b = -numbers[numbers.size()-1];
    numbers.pop_back();
    a = target - a;
    b = target - b;
    if(numbers.size() == 0) {
        if(a == 0) answer++;
        if(b == 0) answer++;
        return answer;
    }
    
    return solution(numbers, a) + solution(numbers, b);
}

int main(int argc, const char * argv[]) {

    cout << solution({1, 1, 1, 1, 1}, 3);
    return 0;
}
