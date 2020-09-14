/*
 You should use the standard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int Answer;

int n, k;
vector<int> X;
vector<int> Y;


int cache[3001][3001];



int cardGame(int i, int j) {
    
    
    if(i >= n || j >= n) {
        return 1;
    }
    int& ret = cache[i][j];
    
    if(ret != -1) return ret;
    
    ret = 0;
    
    
    int sumX = 0;
    int sumY = 0;
    
    int countX = 0;
    int countY = 0;
    
    for(int index = i; index < n; index++) {
        sumX += X[index];
        countX++;
        if(sumX >= k) break;
    }

    for(int index = j; index < n; index++) {
        sumY += Y[index];
        countY++;
        if(sumY >= k) break;
    }
    if(countX == 0 && countY == 0) {
        ret = 1;
    }
    else ret = ((countX + 1) * (countY + 1)) - ((countX + countY - 1) * 2);
    
    return (ret * cardGame(i + countX, j + countY));
    
}
    




int main(int argc, char** argv)
{
    int T, test_case;
    int x, y = 0;
  
//
//    freopen("input.txt", "r", stdin);
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        memset(cache, -1, sizeof(cache));
        X.clear();
        Y.clear();
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> x;
            X.push_back(x);
        }
        for(int i = 0; i < n; i++) {
            cin >> y;
            Y.push_back(y);
        }
    
        Answer = 0;
        
        Answer = cardGame(0, 0);
        
       
        cout << "Case #" << test_case+1 << endl;
        cout <<((n+1) * (n+1) - Answer) << " " << Answer << endl;
    }
    
    return 0;//Your program should return 0 on normal termination.
}
