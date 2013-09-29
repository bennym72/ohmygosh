#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include "thread_work.h"

#define NUM_THREADS  7 

extern int comp[];
extern int compHead;
extern int compTail;

void enqueue(int data)
{
    comp[compHead] = data;
    compHead = (compHead + 1) % ARRAY_SIZE;
}

int main (int argc, char** argv)
{
    int i;
    pthread_t threads[NUM_THREADS];
    thread_args targs[NUM_THREADS];
    void *status;

    initialise();

    for ( i = 0; i < 29; i++ )
        enqueue(i); // enqueues onto comp array
		
		// enqueuing items into a stack
		// Since threads haven't been created yet, this doesn't need to be touched.
		

    for ( i = 0; i < NUM_THREADS; i++)
    {
		// creating the threads:
		// must assume all are initialized at the same time,
		// and can't make any assumptions about what runs first
        targs[i].id = i;
        targs[i].tot_threads = NUM_THREADS;
		// first parameter will become a pointer to the first thread
		// so the third thread will be &threads[2]
        pthread_create(&threads[i], NULL,		
                thread_work, (void *) &targs[i]);
    }

    for ( i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], &status);

    finalise();
}