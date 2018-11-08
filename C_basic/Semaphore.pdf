

# 1.信号量
常用于保护一段代码，使其每次只被一个执行线程运行
* 信号量的数据类型为结构`sem_t`，本质上是一个长整型的数
* 

# 2.信号量的接口函数
## sem_init函数创建信号量
```C
int sem_init(sem_t *sem, int pshared, unsigned int value);
```
该函数初始化由sem`指向的`信号对象，设置它的共享选项，并给它一个初始的整数值。
`pshared`控制信号量的类型，如果其值为0，就表示这个信号量是当前进程的局部信号量，否则（不为0）信号量就可以在多个进程之间共享，
`value`为sem的初始值，调用成功返回0，失败返回-1

## sem_wait函数将信号量减一
## sem_post将信号量加一

```C
// testSem.c -o testSem -lpthread
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void func1(void* arg)
{
    sem_wait(&sem);                   //sem-- ==> sem < 0 等待
    int *running = arg;
    printf("thread1 is running\n");
    printf("%d\n",*running);
}

void func2(void*arg)
{
    printf("thread2 is running\n");
    sem_post(&sem);                   //sem++
}

int main()
{
    sem_init(&sem,0,0);
    pthread_t thread[2]; //构建pid数组
    int a = 5;
    pthread_create(&(thread[0]), NULL, (void*)func1, (void*)&a); // gonna be wait because sem = 0
    printf("main thread running\n");
    sleep(10);
    pthread_create(&(thread[1]), NULL, (void*)func2, (void*)&a); // sem++ 后 func1线程才运行
    printf("main thread running2\n");
    
    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);
    sem_destroy(&sem);
    
    return 0;
}

/*
编译：
gcc testSem.c -o testSem -lpthread
./testSem

输出：
main thread running
main thread running2
thread2 running
thread1 running
5
*/
```
