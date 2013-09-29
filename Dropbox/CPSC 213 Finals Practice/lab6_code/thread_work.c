#include <pthread.h>
#include "thread_work.h"

int comp[ARRAY_SIZE];
volatile int compHead = 0;
volatile int compTail = 0;
// STEP 1:
// declare a static pthread_mutex_t 
pthread_mutex_t mlock;

void spinlock_create(spinlock_t* lock)
{
    *lock = 0;
}

void spinlock_lock(spinlock_t* lock)
{
    int already_held;
    do {
        while(*lock);
        __asm volatile("movl  $1, %%eax\n\t"
                "xchgl %0, %%eax\n\t"
                : "=m" (*lock), "=ra" (already_held));
    } while(already_held);
}

void spinlock_unlock(spinlock_t* lock)
{
    *lock = 0;
}

void initialise()		// must initialize and destroy mutex lock.
						// since our mutex lock is static, and 
						// pthread_mutex_init takes in a pointer as its
						// first parameter, we must pass the address of
						// our static lock
{

	// STEP 2:
	// initialize the pthread_mutex_t
	pthread_mutex_init(&mlock, NULL);
	
}

void* thread_work(void *args)
{
    thread_args *ta = (thread_args *) args;
    int thread_id = ta->id;
    int total_threads = ta->tot_threads;
	
	// STEP 3:
	// Identify the shared data:
	// Through analyzing thread_drive.c, we can see that the shared
	// data are compTail, compHead, and comp array. 
	
	// STEP 4:
	// What do we need to lock?
	// As we can see, we will only run the while loop 
	// while compTail < compHead.. however, we want to print with
	// a particular order, ie. 0 prints all multiples of 7,
	// 1 prints all multiples of 7 + 1, etc. Hence, we must lock inside 
	// the while loop before anything runs.

    while (compTail < compHead) {
		// The lock:
		// Suppose all 7 threads have  entered the while loop. Only
		// one thread can grab the lock- the others will be stuck
		// inside the procedure pthread_mutex_lock. 
		
		// Suppose a thread we do not want printing has grabbed the lock
		// We want this thread both to not print anything and to unlock.
			// A thread must satisfy: thread_id = 7*n + thread_id for some n
			// In other words, if compTail % tot_threads == thread_id
			// then we have the right thread
		if ((compTail % total_threads) == thread_id) {
			pthread_mutex_lock(&mlock);
			} else { continue;}
   
   int val = comp[compTail];
        compTail = (compTail + 1) % ARRAY_SIZE;
        /* do not change the format of this printf or print anything else from
         * the files you hand in */
        printf("%d of %d : %d\n", thread_id,
                    total_threads, val);
        fflush(stdout);
		
		// After the correct one has printed, it will give up its lock.
		pthread_mutex_unlock(&mlock);
		
    }

    return NULL;
}

void finalise()
{
	// step 5: destroy lock
	
	pthread_mutex_destroy(&mlock);
}
