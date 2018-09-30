6.1 Basic Concepts
* Single-processor system, only one process can run at a time. Other must wait until the CPU is free and can be rescheduled.
* The objective of multiprogramming is to have `some process` `running at all times`, to `maximize CPU utilization`.
* A process is executed until it must wait, typically for the `completion of some I/O request`. In a simple computer system, the CPU then just sits idle.
  * With multiprogramming, we try to use this time productively.
  * Several processes are kept in memory at one time. When one process `has to wait`, the operating system `takes the CPU away` from that process and gives the CPU to another process.
* 调度是操作系统的基本功能。几乎所有的计算机资源在使用前都要调度。CPU是最重要的计算机资源之一。因此CPU调度对于操作系统设计来说很重要

6.1.1 CPU-I/O Burst Cycle 区间周期
* Process execution consists of a `cycle` of CPU execution and I/O wait. Processes alternate between these two states.
  * Begin with a CPU burst, followed by an I/O burst.. CPU burst.. I/O burst.
  * Eventually, the final CPU burst ends with a `system request` to terminate execution
* The durations of CPU bursts vary greatly from process to process and from computer to computer, they tend to have a frequency curve --
  * which is generally characterized as exponential or hyperexponential, with a large number of short CPU bursts and a small number of long CPU bursts.
* An I/O-bound program typically has many short CPU bursts. A CPU-bound program might have a few long CPU bursts
> I/O bound指的是系统CPU效能相对硬盘和内存好很多，此时大部分CPU在等io的读写，此时CPU Loading不高。
CPU bound指的是系统的硬盘和内存的性能，相对于CPU的性能要好很多，此时系统运作CPU Loading 100% ，CPU要读写，I/O在很短时间完成，而CPU还有很多运算要处理，CPU Loading很高。

6.1.2  CPU调度程序
* Whenever the CPU becomes idle, the operating system `must` select one of the processes in the `ready queue` to be executed. The selection process `is carried out by` the short-term scheduler, or CPU scheduler.
* The scheduler selects a process from the processes in memory that are ready to execute and allocates the CPU to that process.

习题3.8 (Page 5-6)
* Describe the differences among short-term, medium-term, and long-term scheduling.
 * Short-term (CPU scheduler): selects from jobs in memory those jobs that are ready to execute and allocates the CPU to them
 * Medium-term: used especially with time-sharing systems as an intermediate scheduling level. 
  * A swapping scheme is implemented to remove partially run programs from memory and reinstate them later to continue where they left off.
 * Long-term(job scheduler) - determines which jobs are brought into memory for processing.


6.1.3 Preemptive Scheduling 抢占调度 （Page7-8)
* Selects one process from ready queue to run on CPU
* Scheduling can be:
  * Nonpreemptive: 非抢占的
    * Once a process is allocated the CPU, it `does not leave` unless:
      * 1. it has to wait, (eg. for I/O request or for a child to terminate)
      * 2. it terminates
  * Preemptive: 抢占的
    * OS can `force (preempt)` a process from CPU at anytime
      * Say, to allocate CPU to another higher-priority process
    * Difficult to implement:
      * Need to maintain consistency of data shared between processes, and more importantly, **kernel data structures**(e.g. `I/O queues`)
      * Preemption while kernel is executing a sys call on behalf of a process (many OSs, wait for sys call to finish)
      * Need hardware support (like timers)

6.1.4 Dispatcher 分派程序 (Page 9)
* Scheduler: selects one process to run on CPU
* Dispatcher: allocates CPU to the selected process, which involves:
  * switching context
  * switching to user mode
  * jumping to the proper location (in the selected process) and restarting it

6.2 Scheduling Criteria (Page 10)

6.3 Scheduling Algorithms (Page 11)
