
#include <iostream>
#include <cstring>

using namespace std;
const int MOD = 1000000007;
int cashe[101];

int tiling(int width) {
    if(width <=1) return 1;
    
    int& ret = cashe[width];
    if(ret != -1) return ret;
    return ret = (tiling(width-1) + tiling(width-2)) %  MOD;
}

int asymmetric(int width) {
    if(width % 2 == 1) {
        return (tiling(width) - tiling(width/2) + MOD) % MOD;
    }
    int ret = tiling(width);
    ret = (ret - tiling(width/2) + MOD) % MOD;
    ret = (ret - tiling((width-2) / 2) + MOD) % MOD;
    return ret;
    
}

int main(int argc, const char * argv[]) {
    int C = 0;
    cin >> C;
    
    int result[50];
    int n = 0;
    for(int i = 0; i < C; ++i) {
        memset(cashe, -1, sizeof(cashe));
        cin >> n;
        result[i] = asymmetric(n);
    }
    for(int i = 0; i < C; ++i) {
        cout << result[i] << endl;
    }
}
