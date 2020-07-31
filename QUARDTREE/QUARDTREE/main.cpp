
#include <iostream>
#include <cstring>
#define MAX_SIZE 2048
using namespace std;

char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(string::iterator &it, int y, int x, int size) {
    char head = *(++it);
    
    if(head == 'b' || head == 'w') {
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                decompressed[x+i][y+i] = head;
            }
        }
    }
    else {
        int half = size/2;
        decompress(it, y, x, half);
        decompress(it, y, x + half, half);
        decompress(it, y + half, x, half);
        decompress(it, y + half, x + half, half);
    }
}

string reverse(string::iterator &it) {
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w') return string(1, head); //string을 head로 1만큼 채움
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
int main(int argc, const char * argv[]) {
    
    int C =0;
    cin >> C;

    string word;
    string::iterator it;
    string result[50];
    for(int i = 0; i < C; ++i) {
        cin >> word;
        it = word.begin();
        result[i] = reverse(it);
    }
    for(int i =0; i < C; ++i) {
        cout << result[i] << endl;
    }
  
    
    return 0;
}
