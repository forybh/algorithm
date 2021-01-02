//
//  main.cpp
//  JLIS
//
//  Created by 유병헌 on 2020/08/06.
//  Copyright © 2020 유병헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>

using namespace std;


int A[100], B[100];
int cache[101][101];
int sizeA, sizeB;
const long long NEGINF = numeric_limits<long long>::min();

int jlis(int indexA, int indexB) {
    int &ret = cache[indexA + 1][indexB + 1];
    if(ret != -1) return ret;
    
    ret = 0 ;
    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);
    long long maxE = max(a,b);
    
    for(int nextA = indexA + 1; nextA < sizeA; ++nextA) {
        if(maxE < A[nextA]) {
             ret = max(ret, jlis(nextA, indexB) + 1);
        }
    }
    for(int nextB = indexB + 1; nextB < sizeB; ++nextB) {
        if(maxE < B[nextB]) {
             ret = max(ret, jlis(indexA, nextB) + 1);
        }
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    
//    int C = 0;
//    cin >> C;
//
//    for(int i = 0; i < C; ++i) {
//        memset(cache, -1, sizeof(cache));
////        memset(A, 0, sizeof(A));
////        memset(B, 0, sizeof(B));
//        cin >> sizeA >> sizeB;
//        for(int j = 0; j < sizeA; ++j) {
//            cin >> A[j];
//        }
//        for(int k = 0; k < sizeB; ++k) {
//            cin >> B[k];
//        }
//        cout << jlis(-1,-1) << endl;
//
//    }
//    return 0;
    int i = -2;
    while(++i) {
        cout << "hi" << endl;
    }
    return 0;
}
