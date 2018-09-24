5.1 Background
* Why processes cooperate?
  * Information sharing
  * Computation speed-up
  * Modularity, Convenience
* Interprocess Communication (IPC) methods
  * Shared memory
  * Message passing
* Shared Memory
  * One process creates shared memory
  * Other processes attach shared memory to their own address space
  * Shared memory is treated as regular memory
  * Synchronization is needed to prevent conflicts
  * POSIX: shm_open(),mmap()
* Message Passing
  * Process A sends message to B via kernel
    * send, receive
  * Direct v/s Indirect
    * Naming
    * Ports, mailboxes

* Cooperating processes can either directly share a logical address space (that is, both code and data) or be allowed to share data only through files or messages.
* 多个进程并发访问和操作同一数据且执行结果与访问发生的特定顺序有关，称为竞争条件
* 为了避免 ==> ensure that only one process at a time can be manipulating the variable counter ==> require that the processes be synchronized in some way.
* 
