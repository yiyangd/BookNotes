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
