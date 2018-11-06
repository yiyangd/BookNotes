## 1 背景
### 1.1 基本硬件
* 基地址寄存器
* 界限地址寄存器

### 1.3 逻辑地址空间与物理地址空间
* 编译&加载，同
* 执行时的地址绑定方案导致不同的逻辑地址和物理地址
* 虚拟到物理地址映射由MMU完成


## 3 连续内存分配
### 3.2 内存分配
* （课后习题8.11）
### 3.3 碎片
* 首次，最佳适应方法 ==> 外部碎片，为了避免内部碎片

## 4 分页
* 分页内存管理方案允许进程的物理地址空间可以是非连续的。
### 4.1 基本方法
* 将物理内存分为固定大小的块 == Frames
  * Size is power of 2 (typically 512 bytes to few GBs)
    * 方便地将逻辑地址转换为页号和页偏移
    * Because it is efficient for hardware to identify the `page number and offset` by simply selecting the correct set of bits from the address (split address bits as even number of bits)
* 将逻辑内存也分为同样大小的块 == Pages
* 由CPU生成的每个（逻辑）地址分为两个部分： 页号(p)和页偏移(d)。
  * 页号作为`页表`中的索引，页表包含每页所在物理内存的基地址，这些基地址与页偏移的组合就形成了物理地址，
  * Page Table to translate logical to physical addresses
  ！！！！ 此处有计算 明天白天看 （习题8.4 书P248 习题册P160）
  
* 4.2 



## 6


### 习题
13. （对应知识点1.3）动态重定位是在作业的执行过程中进行的

### Problem Set
