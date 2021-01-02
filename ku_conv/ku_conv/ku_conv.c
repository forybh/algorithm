#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include "sys/types.h"
#include "sys/ipc.h"
#include "sys/msg.h"

#define MAX_ID 5

key_t ipckey;
int mqdes, i;
size_t buf_len;
int X, Y;
int Cslice_cnt;

struct{
    long id;
    int value[];
}mymsg;

void C_slice(int** arr){
    int col = 0, row = 0;
    int tmp[3][3];
    int count = 0;

    while(col != X-2 || row != Y-3){
        if(col == X-2){
            col = 0;
            row++;
        }
        count++;
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                tmp[i][j] = arr[row + i][col + j];
            }
        }
        // here message queue
        col++;
        Cslice_cnt++;
    }
}

//void receive_func(){
//    if(mqdes < 0){
//        perror("msgget()");
//        exit(0);
//    }
//
//    for(i = 0; i<= Cslice_cnt; i++){
//        if(msgrcv(mqdes, &mymsg, buf_len, i+1, 0) == -1){
//            perror("msgrcv()");
//            exit(0);
//        }else{
//            printf("Received (val : %d, id: %ld)\n", mymsg.value, mymsg.id);
//        }
//    }
//}
//
//void send_func(int** value){
//    if(mqdes < 0){
//        perror("msgget()");
//     }
//
//
//    //for(i = 0; i<= Cslice_cnt; i++){
//    //    mymsg.id = i+1;
//    //    mymsg.value = i*3;
//    //    printf("Sending  (val : %d, id: %ld)\n", mymsg.value, mymsg.id);
//
//        if(msgsnd(mqdes, &mymsg, buf_len, 0) == -1){
//            perror("msgsnd()");
//            exit(0);
//        }
//    }
//}

void makeMatrix(int **matrix, int X, int Y);


int main(int argc, char** argv){
    int a = atoi(argv[1]);
//    //printf("a = %d", a);

    X = a;
    Y = a;

//    buf_len = sizeof(mymsg.value);

//    ipckey = ftok("./tmp/foo", 1946);
//    mqdes = msgget(ipckey, IPC_CREAT|0600);
//
    //int * value = malloc(sizeof(int)*9);

//    receive_func();

    int** sample;

    sample = (int**) malloc(sizeof(int*) * X);
    for(int i = 0; i < X; i++){
        sample[i] = (int*) malloc(sizeof(int) * Y);
    }

    makeMatrix(sample, X, Y);



    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            printf("%d ", sample[i][j]);
        }
        printf("\n");
    }
//    //printf("\n");

    C_slice(sample);

    pid_t pid;

    for(int i = 0; i < X; i++){
        free(sample[i]);
    }
    free(sample);

    return 0;
}

