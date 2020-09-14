

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<string> temp_vector;
    
    string temp;
    for(int i = 0; i < orders.size() -1; i++) {
        for(int ni = i+1; ni < orders.size(); ni++) {
            for(int j = 0; j < orders[i].size(); j++) {
                if(orders[ni].find(orders[i][j]) <= orders[ni].size()) {
                    temp.push_back(orders[i][j]);
                }
            }
            sort(temp.begin(), temp.end());
            temp_vector.push_back(temp);
            temp.clear();
        }
    }
    for(int i = 0; i < temp_vector.size(); i++) {
        if(temp_vector[i].size() < 2) {
            temp_vector.erase(temp_vector.begin() + i);
        }
    }

    for(int i = 0; i < temp_vector.size(); i++) {
        if(temp_vector[i].size() >2) {
            for(int j = 0; j < temp_vector[i].size() - 1; j++) {
                for(int nj = j + 1; nj < temp_vector[i].size(); nj++) {
                    temp.push_back(temp_vector[i][j]);
                    temp.push_back(temp_vector[i][nj]);
                    temp_vector.push_back(temp);
                    temp.clear();
                }
            }
        }
    }
    vector<pair<int, string>> v;
    
    for(int i = 0; i < answer.size(); i++) {
        int cnt = (int)count(answer.begin(), answer.end(), answer[i]);
        v.push_back(make_pair(cnt, answer[i]));
    }
    sort(v.begin(), v.end());
    
    vector<pair<int, string>> temp2;
    
    
    
    for(int i = 0; i < course.size(); i++) {
        for(int j = 0; j < temp_vector.size(); j++) {
            if(course[i] == temp_vector[j].size()) {
                answer.push_back(temp_vector[j]);
            }
        }
    }
    int count = 0;
    for(int i = 0; i < course.size(); i++) {
        for(int j = 0; j < answer.size() - 1; j++) {
            if(course[i] == answer[j].size()) {
                if(answer[j] == answer[j+1])
            }
        }
    }
//    for(int i = 0; i < course.size(); i++) {
//        for(int j = 0; j <v.size(); j++) {
//            if(v[j].second.size() == course[i]) {
//                temp2.push_back(v[j]);
//            }
//        }
////        for(int k = 0; k < temp2.size()-1; k++) {
////            if(temp2[k].first > temp2[k+1].first) {
////                max = temp2[k].first;
////            }
////            else max = temp2[k+1].first;
////
////        }
////        for(int r = 0; r < temp2.size(); r++) {
////            if(temp2[r].first == max) {
////                answer.push_back(temp2[r].second);
////            }
////        }
////        max = 0;
////        temp2.clear();
//    }
    
    
 
    return answer;

}

int main(int argc, const char * argv[]) {
    
    vector<string> v = solution({"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, {2, 3, 5});
    
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << endl;
    }
    
    
}
