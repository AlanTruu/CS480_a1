#include "Thread_utils.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void* threadWork(void *arg) {
    ThreadDataT *arguments = (ThreadDataT*)arg;

    for (int i = 0; i < 8; i++) {
        writeQuote(arg);
    }

    return NULL;
}

void writeQuote(ThreadDataT *data) {
    sleep(data->sleepTime);
    
    int botID = data->index;
    
    sem_t *sem = data->flag;
    sem_wait(sem);
    
    int fd = open("Quote.txt", O_WRONLY | O_APPEND);
    if (fd == -1) perror("File open failure: Thread_utils.c line 18");
   
    //This char needs debugging
    char output[80] = "Thread ID: ";
    int outLen = strlen(output);
    snprintf(output + outLen, 80 - outLen, "%d", botID);

    // strcat(output, data->quote);

    strcat(output, "\r \n");

    int writeStatus = write(fd, output, strlen(output));
    printf(output);
    if (writeStatus == -1) perror("Write failure: Thread_utils.c line 33");

    //printf("Thread %d is running \n", botID);
    if (close(fd) < 0) perror("File close failure: Thread_utils.c line 37");

    sem_post(sem);


}