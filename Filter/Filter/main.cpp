//
//  main.cpp
//  Filter
//
//  Created by 유병헌 on 2020/10/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
//vector<vector<int>> filter(vector<vector<int>> v) {
//    int n = (int) v[0].size();//열 개수
//    int k = (int)v.size();//행 개수
//    int x = 0; int y = 0;
//
//    vector<vector<int>> toChild;
//    while(x != n-3 || y != k-3) {
//        if(x == n -3) {
//            x = 0;
//            y ++;
//        }
//        for(int i = 0; i < 3; i++) {
//            for(int j = 0; j < 3; j++) {
//                toChild[i].push_back(v[x+i][y+j]);
//            }
//        }
//        //여기서 child에게 저 toChild 넘겨주고
//        x++;
//    }
//return toChild;
//}
void filter(int arr[6][6]) {
    int column = 6;
    int row = 6;
    
    int x = 0; int y = 0;
    int toChild[3][3];
    int count = 0;
    while (x != column - 2 || y != row -3) {
        if(x == column -2) {
            x = 0;
            y ++;
        }
        cout << "toChild matrix " <<count <<" x: "<< x << " y: " << y << endl;
        count++;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                toChild[i][j] = arr[y+i][x+j];
                cout << toChild[i][j] << " ";
            }
            cout << endl;
        }
        //여기서 child에게 toChild 넘겨줌
        x++;
    }
}
    
    
    

int main(int argc, const char * argv[]) {
   
    int arr[6][6] = {{1, 3, 3, 2, 1, 5}, {4, 4, 5, 2, 3, 4}, {2, 2, 1, 1, 5, 7}, {3, 1, 3, 2, 1, 4}, {4, 7, 4, 7, 8, 5}, {3, 8, 3, 6, 5, 5}};
    filter(arr);
    
    return 0;
}
