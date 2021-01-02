#include <stdio.h>
#include <stdlib.h>



int arr2[3][3] = { {1,2,3}, {4,5,6}, {7,8,9}};


int (*func(int x, int y))[3] {
    static int arr[3][3] = {0};
    
//    for(int i = 0; i < 9; i++) {
//        *(arr[0] + i) = i + 1;
//    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            arr[i][j] = i + j;
        }
    }
        return arr;
}
int func2(int arr[3][3]) {
    return arr[0][0];
}

int f1(int arr[4]) {
    int result = arr[0];
    for(int i = 0; i < 3; i++) {
        if(arr[i] < arr[i+1]) {
            result = arr[i+1];
        }
    }
    return result;
}
int main(int argc, const char * argv[]) {
    
    int arr[4];
    arr[0] = 1000;
    arr[1] = 100;
    arr[2] = 2000000;
    arr[3] = 300000000;
    int result = f1(arr);
    printf("%d", result);
}
