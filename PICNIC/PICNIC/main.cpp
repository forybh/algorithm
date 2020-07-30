
#include <iostream>
#include <cstring>

using namespace std;

int test_case = 0;
int students = 0;
int friends = 0;
int isFriend[10][10] = {0};
int paired[10] = {0};

int countCase() {
    int index = -1;
    for(int i = 0; i < students; ++i) {
        if(paired[i] == -1) {
            index = i;
            break;
        }
    }
    if(index == -1) return 1;
    
    int result = 0;
    
    for(int i = index + 1; i<students; ++i) {
        if(paired[i] == -1 && isFriend[index][i] == 1) {
            paired[i] = 1;
            paired[index] = 1;
            result += countCase();
            paired[i] = -1;
            paired[index] = -1;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int x, y = 0;
    int result[50];
    cin >> test_case;
    if(test_case > 50 || test_case <=0) {
        return 0;
    }
    
    
    for(int i = 0; i < test_case; ++i) {
        cin >> students >> friends;
        
        memset(isFriend, -1 , sizeof(isFriend));
        memset(paired, -1, sizeof(paired));
        
        for(int j = 0; j < friends; ++j) {
            cin >> x >> y;
            isFriend[x][y] = 1;
            isFriend[y][x] = 1;
        }
        result[i] = countCase();
    }
    for(int i = 0; i < test_case; ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
