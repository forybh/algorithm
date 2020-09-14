
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int Answer;

int N, K;

vector<int> A = {0,};
vector<int> B = {0,};

int mostKal() {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> add;
    
    add.resize(K);
    
    
   
    for(int i = 0; i < K; i++) {
        add[i] = A[i] + B[K-i-1];
    }
    
    sort(add.begin(), add.end(), greater<>());
    
    return add.front();
}

int main(int argc, char** argv)
{
    
    int T, test_case;
    int a, b = 0;
    
//    freopen("input.txt", "r", stdin);
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        A.clear();
        B.clear();
        
        cin >> N >> K;
       
        for(int i = 0; i < N; i++) {
            cin >> a;
            A.push_back(a);
        }
        for(int i = 0; i < N; i++) {
            cin >> b;
            B.push_back(b);
        }
        
        Answer = 0;
        
        Answer = mostKal();
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
//    fclose(stdin);
    return 0;//Your program should return 0 on normal termination.
}
