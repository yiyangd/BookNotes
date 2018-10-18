## 1. Dr. Fraser Video1

```terminal
man pthread_create
```
```C
#include <pthread.h>
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
                   void *(*start_routine)(void *), void *arg);
/* This function starts a new thread in the calling process. 
   The new thread starts execution by invoking start_routine(); 
   arg is passed as the sole argument of start_routine().
*/
```


```C
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// Makefile: CFLAGS = -Wall -g -std=c99 -Werror -pthread

long long sum = 0;

void* sum_runner(void* arg)   // Thread function to generate sum of 0 to N
{
  long long limit_ptr = (long long*) arg;
  long long limit = *limit_ptr;
  

  for(long long i = 0; i <= limit; i++){
    sum += i;
  }
  // sum is a global variable, so other threads can access
  
  pthread_exit(0);



}

int main(int argc, char **argv){
  if (argc < 2) // only [./program]
  {
    printf("Usage: %s <num>\n",argv[0]);
    exit(-1);
  }
  
  long long limit = atoll(argv[1]);
  
  // Thread ID:
  pthread_t tid;
  
  // Create attributes
  pthread_attr_t attr;
  pthread_create(&tid, &attr, sum_runner, &limit);
  
  // Wait until thread is done its work
  pthread_join(tid, NULL);
  
  printf("Sum is %lld\n", sum);
  
  
  
  /
  
}
```

函数1: 
