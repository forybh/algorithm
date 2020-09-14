//
//  main.cpp
//  MINASTIRITH
//
//  Created by 유병헌 on 2020/08/14.
//  Copyright © 2020 유병헌. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

struct post {
    float x;
    float y;
    float r;
}post;

struct post p[100];

vector <pair<float, int>> len;

vector <pair<float, float>> be;

void initP() {
    for(int i = 0; i < 100; i++) {
        p[i].r = 0;
        p[i].x = 0;
        p[i].y = 0;
    }
}
void beginEnd() {
    float begin, end, a, theta = 0;
    
    for(int i = 0; i < n; i++) {
        a = atan(p[i].y / p[i].x);
        if(p[i].y < 0 ) {
            a += M_PI;
        }
        theta = 2 * asin(p[i].r / 16);
        begin = 8 * (a - theta);
        end = 8 * (a + theta);
        pair<float, float> pair = {begin, end};
        be.push_back(pair);
    }
}

bool inRange(float start, pair<float, float> beginEnd) {
    return (start >= beginEnd.first && start <= beginEnd.second);
}
int run() {
    float end = 16 * M_PI;
    float start = 0;
    vector<pair<float, float>> v;
    for(int i = 0; i < n; i++) {
        if(inRange(start, be[i])) {
            v.push_back(be[i]);
        }
    }
    if(v.empty()) return -1;
    
    sort(v.begin(), v.end(), greater<>());
    start = v[0].first;
    end = v[0].second;
   
    while(start <= end) {
        
    }
    
}
//void length() {
//    float leng = 0;
//
//    for(int i = 0; i < n; i++) {
//        vector<float> bE = beginEnd(p[i]);
//        leng = bE[1] - bE[0];
//        if(leng < 0) leng += 16 * M_PI;
//        len.push_back(make_pair(leng, i));
//    }
//}
//
//void decreaseLength(struct post post) {
//    for(int i = 0; i < n; i++) {
//        if(beginEnd(post)[0] > beginEnd(p[i])[0] && beginEnd(post)[0] < beginEnd(p[i])[1]) {
//            len[i].first = beginEnd(post)[0] - beginEnd(p[i])[0];
//        }
//        else if(beginEnd(post)[0] <= beginEnd(p[i])[0] && beginEnd(post)[1] >= beginEnd(p[i])[1]) {
//            len[i].first = 0;
//        }
//        else if(beginEnd(post)[1] > beginEnd(p[i])[0] && beginEnd(post)[1] < beginEnd(p[i])[1]) {
//            len[i].first =  beginEnd(p[i])[1] - beginEnd(post)[1];
//        }
//    }
//}
//
//int countPost() {
//    float remain  = 16 * M_PI;
//
//    sort(len.begin(), len.end(), greater<>());
//
//    int ret = 0;
//
//    for(int i = 0; i < n; i++) {
//        int post = len[0].second;
//        remain -= len[0].first;
//        len[0].first = 0;
//        decreaseLength(p[post]);
//        sort(len.begin(), len.end(), greater<>());
//        ret++;
//        if(remain <= 0) {
//            return ret;
//        }
//    }
//
//    return -1;
//}

int main(int argc, const char * argv[]) {
    
    int C = 0;
    cin >> C;
    
    int result[50];
    
    for(int i = 0; i < C; i++) {
        initP();
        len.clear();
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> p[j].y >> p[j].x >> p[j].r;
        }
        length();
        result[i] = countPost();
    }
    for(int i = 0; i < C; i++) {
        if(result[i] == -1) {
            cout << "IMPOSSIBLE" << endl;
        }
        else cout << result[i] << endl;
    }
}
