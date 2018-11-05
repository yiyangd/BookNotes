临界区问题的解答必须满足如下三项要求：
* 互斥：如果进程Pi在其临界区内执行，那么其他进程都不能在其临界区内执行
* progress: 如果没有进程在其临界区内执行且有进程需进入临界区，那么只有那些不在剩余区内执行的进程可参加选择，以确定谁能下一个进入临界区，且这种选择不能无限推迟
* bounded waiting：从一个进程做出进入临界区的请求，直到该请求允许为止，其他进程允许进入其临界区的次数有上限

6.3 Peterson算法
* 


6.5.2
* 二元信号量的缺点是忙等待===> 一个进程在临界区内，其他试图进入其临界区的进程都必须在其进入代码中连续的循环，在多道
* 单CPU情况下，一旦禁止中断，

6.6.2 读者-写者问题
* 一个数据库可以为多个并发进程所共享。其中，有的进程可能只需要读数据库，而其他进程可能要更新（读和写）数据库。为了区分这两种类型的进程，将前者称为读者，而将后者称为写者。显然，如果两个读者同时访问共享数据，那么不会产生什么不利的结果。然而，如果一个写者和其他线程同时访问对象，很可能混乱
* 所以： 要求写者对共享数据库有排他的访问
* 读写锁在以下情况下最为有用：
  * 当可以区分哪些进程只需要读共享数据而哪些进程只需要写共享数据
  * 当读者进程数比写进程数多时。这是因为读写锁的建立开销通常比信号量或互斥锁要大，而这一开销可以通过允许多个读者来增加并发度的方法进行弥补
  
6.6.3 哲学家进餐问题
* 需要在多个进程之间分配多个资源且不会出现死锁和饥饿的典型例子
```C
//先左后右然后吃
while(true){
  wait(chopstick[i]);
  wait(chopstick[(i + 1) % 5]);
  // Eat
  signal(chopstick[i]);
  signal(chopstick[(i + 1) % 5]);
  //
}
```

6.7 管程
* 信号量的不正确仍然会导致一些时序错误，并且难以检测，频率低
* 类型或抽象数据类型，封装了私有数据类型及操作数据的公有方法。管程类型提供了一组由程序员定义的、在管程内互斥的操作。
* 管程类型的表示包括一组变量的声明和对这些变量操作的子程序和函数的实现。
* Only process may be active within the monitor at a time
```C
monitor name{
  // shared variable declarations
  function P1(...) {...}
  ...
  function Pn(...) {...}
  
  initialization_code (...) {...}
}

```
程序员自己编写条件变量，condition x,y;
x.wait() 意味着调用操作的进程会挂起，直到另一进程调用x.signal();重新启动一个悬挂的进程，如果没有进程悬挂，那么操作signal()就没有作用

```c
monitor DiningPhilos{
  enum {THINKING, HUNGRY, EATING} state[5];
  condition self[5];
  
  void pickup (int i){
    state[i] = HUNGRY;
    test(i);
    if (state[i] != EATING)
      self[i].wait();
  }
  
  void putdown(int i){
    state[i] = THINKING;
    test((i + 4) % 5);
    test((i + 1) % 5);
  }
  
  void test(int i){
    
  
  }
}
```
