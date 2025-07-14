#include "Bots.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "Thread_utils.h"
#define NUMBER_OF_BOTS 7

int main() {
    FILE *fp = fopen("Quote.txt", "w");
    if (fp == NULL) {
        perror("Failed to create Quote.txt");
        return 1;
    }

    pid_t procID = getpid();
    
    
    //This char needs debugging
    char initialWrite[30] = "Process ID: "; 
    int writeLength = strlen(initialWrite);
    snprintf(initialWrite + writeLength, 30 - writeLength, "%d", procID);
    strcat(initialWrite, " \r \n");
    fprintf(fp, initialWrite);
    fclose(fp);



    pthread_t *bots = wakeBots(NUMBER_OF_BOTS);
    sem_t FLAG;
    sem_init(&FLAG, 0, 1);
    ThreadDataT *botData = createBotData(NUMBER_OF_BOTS, &FLAG);
    int prepareSuccess = prepareBots(bots, botData, threadWork, NUMBER_OF_BOTS);
    int workSuccess = workBots(bots, NUMBER_OF_BOTS);

    free(bots);
    free(botData);
    sem_destroy(&FLAG);
    printf("Program exiting...");
    exit(0);

    return 0;
}