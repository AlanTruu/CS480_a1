#ifndef THREAD_UTILS
#define THREAD_UTILS

#include "Bots.h"

//function to conduct work
void* threadWork(void *arg);

//function that will be called by threadWork
void writeQuote(ThreadDataT *data);



#endif