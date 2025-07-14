#include "Bots.h"
#include <stdlib.h>

//function dynamically allocates a number of pthreads and assigns to an array, returns array
pthread_t* wakeBots(int botCount) {
    pthread_t *employed = malloc(botCount * sizeof(pthread_t));

    return employed;
}


//dynamically allocate array of threadDataT pointer structs
//assign their index, sleeptime, quote, and each should carry the flag semaphore
//return this array
ThreadDataT* createBotData(int botCount, sem_t *sem) {
    ThreadDataT *employeeData = malloc(botCount * sizeof(ThreadDataT));

    for (int i = 0; i < botCount; i++) {
        int botID = i + 1; //get the bot's id by adding 1 to i
        int even = botID % 2 == 0 ? 1 : 0; //even = 1 if botID is an even number, 0 otherwise
        employeeData[i].index = botID; //set bot's index
        employeeData[i].sleepTime = even == 1 ? 2 : 3; //sleepTime is 2 if bot is even, 3 otherwise
        employeeData[i].flag = sem; //set semaphore for each thread

        //TODO: assign quote
    }

    return employeeData;
}

//call pthread_create on all pthread_t, with botData and chosen function
int prepareBots(pthread_t *bots, ThreadDataT *botData, void*(*routine)(void *arg), int botCount) {
    for (int i = 0; i < botCount; i++) {
        pthread_create(&(bots[i]), NULL, routine, (void*)&botData[i]);

        //TODO check if pthread_create fails, return 1 if so
    }

    return 0;
}

int workBots(pthread_t *bots, int botCount) {
    for (int i = 0; i < botCount; i++) {
        pthread_join(bots[i], NULL);

        //TODO check if pthread_join fails, return 1 if so
    }

    return 0;
}