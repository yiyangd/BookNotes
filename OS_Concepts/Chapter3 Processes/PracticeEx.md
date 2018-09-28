3.1
* The memory pages which are used by original process are then duplicated after `fork() system call`.
  * Same between parent and child processes: image, because they have same memory as original process
  * Difference: 
    * if fork() call returns in parent process, return value will be process id of child process
    * if returns in child process, then return value = 0
    * if call `fails` and no new process created then return value will be -1
* value = 5 as child process updatres only its copy of value and after that control will be returned to parent process in which the value of value remains at 5

3.2
* Whenever a fork() called, it creates processes as child nodes of a growing binary tree. If fork() function is called two times, it will create 2^2 = 4 processes. All these 4 processes will be the child node of binary tree.
* fork function is called 3 times. This program will generate total 2^3 = 8 processes. There will be one parent process and seven child processes

3.3
* Concurrent systems

3.4 
* Multiple register sets: What happens when a context switch occurs if the new context
 * the CPU current-register-set pointer is changed to point to the set containing the new context, which takes very little time. 
* What happens if the new context is in memory rather than in a register set and all the register sets are in use?
 * If the context is in memory, one of the contexts in a register set must be chosen and be moved to memory, and the new context must be loaded from memory into the set. This process takes a little more time than on systems with one set of registers, depending on how a replacement victim is selected.

3.5
* When a process creates a new process using fork() operation, which of the following state is shared between the parent process and the child process?
 * Only the shared memory segments are shared between the parent process and the newly forked child process. Copies of the **stack** and the **heap** are made for the newly created process. 

3.9 (P10)
* Describe the actions taken by a kernel to context-switch between processes.
 * Kernel saves the state of the current process running on the system in PCB in memory
  * This method is referred as state save.
 * Kernel loads the data information of the new process from PCB into registers to run
 * After the completion of the execution of the new task, the kernel switches to the old task by loading the data information of the old task from the PCB to run
  * This method is referred as state restore.
 > The kernel would only save and load the CPU state while switching between the thread of the same process. It would save and load the process environment if the thread being interrupted and thread being scheduled to different processes




3.8 -- Chapter6 CPU Scheduling
* Describe the differences among short-term, medium-term, and long-term scheduling.
 * Short-term (CPU scheduler): selects from jobs in memory those jobs that are ready to execute and allocates the CPU to them
 * Medium-term: used especially with time-sharing systems as an intermediate scheduling level. 
  * A swapping scheme is implemented to remove partially run programs from memory and reinstate them later to continue where they left off.
 * Long-term(job scheduler) - determines which jobs are brought into memory for processing.
