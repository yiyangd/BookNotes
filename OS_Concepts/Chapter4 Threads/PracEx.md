4.1 (page21)
* Provide three programming examples in which multithreading provides better performance than a single-threaded solution.
  * Web browsers: parallel downloads
  * Web servers: handle multiple concurrent clients, services each request in a separate thread
  * Word processors: spell check in the background 
  * GUI: different threads are executed for different tasks, such as debugger where a thread is used to monitor user input, another thread represents the running application, and a third thread monitors performance.
  
4.2 (page22)
* What are two differences between `user-level threads` and `kernel-level threads`? Under what circumstances is one type better than the other?
  * User-level threads are unknown by the kernel, whereas the kernel is aware of kernel threads
  * 
