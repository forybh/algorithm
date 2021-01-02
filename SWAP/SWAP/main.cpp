//
//  main.cpp
//  SWAP
//
//  Created by 유병헌 on 2020/10/15.
//

#include <iostream>

using namespace std;

void swap(int a, int b) {
    int tmp;
    
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int i = 0;
    cout << "start" << endl;
    for( ; ; ) {
        i++;
        if(i > 10)
            break;
        if(i < 6)
            continue;
    cout << i << endl;
    }
}
