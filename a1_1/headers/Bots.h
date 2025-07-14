#ifndef BOTS
#define BOTS

#include <pthread.h>
#include <semaphore.h>

typedef struct BotData {
    int index;
    int sleepTime;
    const char *quote;
    sem_t *flag;

} ThreadDataT;


//function that will initialize a botCount number of pthread_t
pthread_t* wakeBots(int botCount);

//function that will create a struct that will hold bot data for each bot
ThreadDataT* createBotData(int botCount, sem_t *sem);

//function that will call pthread_create on all input threads, return 0 on success
int prepareBots(pthread_t *bots, ThreadDataT *botData, void*(*routine)(void *arg), int botCount);

//function that will call pthread_join on all pthreads
int workBots(pthread_t *bots, int botCount);


#endif
