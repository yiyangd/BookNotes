Lecture Notes:
* Threads is a `basic unit` of CPU utilization
  * A sequence of `instructions` in a function which CPU can execute as a unit
* Thread is comprised of (from OS perspective)
  * Program counter
  * Register set
  * Stack
* Process is comprised of one or more threads
* Threads belonging to same process share
  * `Code section`
  * `Data section`
  * `OS resources such as open files and signals`
> If the web server ran as a traditional single-threaded process, it would be able to service only one client at a time, and a client might have to wait a very long time for its request to be serviced. 
> One solution is to have the server run as a single process that accepts requests. When the server receives a request, it creates a separate process to service that request. In fact, this process-creation method was in common use before threads became popular. Process creation is time consuming and resource intensive, however. If the new process will perform the same tasks as the existing process, why incur all that overhead? It is generally more efficient to use one process that contains multiple threads. If the web-server process is multithreaded, the server will create a separate thread that listens for client requests. When a request is made, rather than creating another process, the server creates a new thread to service the request and resume listening for additional requests. 

* Why Multithreading? (4.1.2优点）
  * 1.Responsiveness.响应度高：部分阻塞，执行较冗长的操作，多线程程序仍可继续运行，增加了对用户的响应程度
  * 2.Resource Sharing.资源共享：线程`默认`共享所属进程的内存和资源,代码和数据共享的优点是它能允许一个应用程序在同一地址空间有多个不同的活动线程
  * 3.Economy.经济：Allocating memory and resources for process creation is costly. Because threads share the resources of the process to which they belong, it is more economical to create and context-switch threads
  * 4.Scalability.


* Thread Libraries (Page27-28 4.4)
 * A thread library provides the programmer with an API for creating and managing threads.
 * 两种方法实现线程库：
  * 1. 在用户空间中提供一个没有内核支持的库，所有的代码和数据结构都存在与用户空间中 ==>调用库中的一个函数只是导致了用户空间中的一个本地函数调用，而不是系统调用
  * 2. 执行一个操作系统直接支持的内核级的库。所有的代码和数据结构都存在于内核空间中 -->调用库中的一个API函数导致了对内核的系统调用
 * 线程库1: POSIX Pthreads
  * Pthreads, the threads Extension of the POSIX standard, may be provided as either a user-level or a kernel-level library.
  * This is a specification for thread behavior, not an implementation.
  * Operating-system designers may implement the specification in any way they wish.
 ```C
 #include <pthread.h>
 int sum; // this data is shared by the thread(s)
 // The thread will begin control in this function
 void* runner(void* param){
  int i, upper = atoi(param);
  sum = 0;
  
  for (i = 1; i <= upper; i++)
   sum += i;
  pthread_exit(0); // child thread will terminate when it calls this function and be returned
 }
 
 int main(int argc, char* argv[]){
  pthread_t tid; // the thread identifier
  pthread_attr_t attr; // set of thread attributes:stack size, scheduling info...
  
  pthread_attr_init(&attr); // default attributes
  pthread_create(&tid, &attr, runner, argv[1]);
  pthread_join(tid, NULL); //fork-join strategy: wait for child to terminate by calling this function.
  
  printf("Sum = %d\n, sum);
 }
 ```
 
 * Windows Threads
   * Implementation of the one-to-one model in kernel
 * Java
   * Java threads are managed by JVM, which is run on top of an OS
   * JVM specifies the interface, does NOT 
  >The Java thread API allows threads to be created and managed directly in Java programs. However, because in most instances the JVM is running on top of a host operating system, the Java thread API is generally implemented using a thread library available on the host system. This means that on Windows systems, Java threads are typically implemented using the Windows API; UNIX and Linux systems often use Pthreads.
* Two strategies for creating multiple threads:
> asynchronous threading and synchronous threading. With asynchronous threading, once the parent creates a child thread, the parent resumes its execution, so that the parent and child execute concurrently. Each thread runs independently of every other thread, and the parent thread need not know when its child terminates. Because the threads are independent, there is typically little data sharing between threads. Asynchronous threading is the strategy used in the multithreaded server illustrated in Figure 4.2.
>Synchronous threading occurs when the parent thread creates one or more children and then must wait for all of its children to terminate before it resumes —the so-called fork-join strategy. Here, the threads created by the parent perform work concurrently, but the parent cannot continue until this work has been completed. Once each thread has finished its work, it terminates and joins with its parent. Only after all of the children have joined can the parent resume execution. Typically, synchronous threading involves significant data sharing among threads. For example, the parent thread may combine the results calculated by its various children. All of the following examples use synchronous threading.
 
* Threading Issues (Page 29-35 4.5-4.6)
