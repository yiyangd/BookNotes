## 1. 背景
###

* 如果有一个页面（内存数据，指令）只有真正需要，才加载到内存
  * 降低I/O操作（读硬盘消耗时间很大）

* Handling Page Fault
* Page Fault Rate, 0 = no page faults; 1 = every reference is a fault
* Effective Access time?
8 毫秒 == 0.008 秒

* We should minimize number of page faults because they are very very costly



## 2.

## 3. Copy-on-Write 写时复制
* process1 fork出 process2时 共享页面！
* 改数据怎么办？
* 页表对页面有权限指定：只读、读写权限、执行权限
* If either process modifies a shared page, page is copied
