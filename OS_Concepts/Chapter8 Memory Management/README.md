## 1.背景
### 1.1 基本硬件
* 基地址寄存器
* 界限地址寄存器

### 1.3 逻辑地址空间与物理地址空间
* 编译&加载，同
* 执行时的地址绑定方案导致不同的逻辑地址和物理地址
* 虚拟到物理地址映射由MMU完成


## 3.连续内存分配
### 3.2 内存分配
* （课后习题8.11）
### 3.3 碎片
* 首次，最佳适应方法 ==> 外部碎片，为了避免内部碎片

## 4.分页
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
  * ！！！！ 此处有计算 明天白天看 （习题8.4 书P248 习题册P160）
  * 
* 分页技术不会产生外部碎片：每个帧都可以分配给需要它的进程。不过，分页有内部碎片
  * 最糟糕的情况：一个进程需要N个页再加1Bytes，那么就要分配 N+1个帧，这样几乎产生一个整个帧的内部碎片
* 空闲帧：在帧表中，每个条目对应着一个帧，以表示该帧是空闲还是已占用，如果占用，是被哪个（或哪些）进程的哪个页所占用

### 4.2 硬件支持
* 绝大多数操作系统都为每个进程分配一个页表，页表的指针与其他寄存器的值（如指令计数器）一起存入进程控制块中。
* 当页表小（256个条目）时，页表使用寄存器，当页表非常大的时候，必须将页表放入内存中，并将PTBR指向页表
  * 缺点？
    * 访问一个字节需要两次内存访问，page table + data/instruction
    * 慢
* 解决方案：采用小但专用且快速的硬件缓冲 ==> 转换表缓冲区(translation look-aside buffer, TLB)
  * Fast-lookup associative memory 快速的关联内存
  * TLB只包含页表中的一小部分条目（of currently running process)、
  * Lookup done in one pipeline step
* TLB entry 由标签和值组成，64 - 1024之间
* 满就替换（最少使用&随即替换）内核代码不替换
* Each entry stores ASID:
  * Identifier for process
  * Address translation checks ASID for protection
  * Entries for different processes can be held simultaneously
  



## 5.页表结构

## 6. 分段
### 6.1 基本方法

### 6.2 硬件


## 7.Intel 32 and 64-bit Architectures
* 在Pentium系统中，CPU产生逻辑地址，被赋给分段单元。分段单元为每个逻辑地址生成线性地址，然后线性地址交给分页单元，它接下来生成内存中的物理地址
* 因此，分段单元和分页单元相当于内存管理单元（MMU），负责翻译工作

### 7.1 Pentium 分段 (Segmentation Unit)
* 允许一个段的大小最多可达4GB，每个进程最多的段的数量为16K个（2^14)
  * 2^13(8k) private segments (use local descriptor table) LDT 本地描述符表
  * 2^13(8k) shared segments (use global descriptor table) GDT 全局描述符表
  * LDT和GDT的每个条目为 8 Bytes，包括一个段的详细信息，如基地址和段界限等
* 逻辑地址是一对（selector，offset）
  * 选择器（selector）是个16位数，其中，s表示段号(13bits)，g表示段是在GDT还是LDT中(1bit)，p表示保护信息(2- bits)。
  * 偏移（offset）是一个32位的数，用来表示字节（或字）在段内的位置

### 7.2 IA-32 Paging Unit （linear address --> physical address)
* 允许页的大小为4KB或4MB，二级分页方案
  * 32位线性地址被分为：
    * 10位引用最外层页表的条目，页目录
    * 页目录条目指向由线性地址中最内层的10位内容索引的内部页表
    * 最低的0～11位是页表项所指向的4KB页面内的偏移
* 页目录中的一个条目是Page Size标志，如果设置了它，表示页帧的大小为`4MB`，而不是标准的`4KB`，如果**设置了该标志**，则页目录直接指向`4MB`页帧，而绕过了内层页表，且线性地址

* IA-32 Page Address Extensions (PAE)
  * Extend beyond 4 GB memory limitation
  * Three level paging scheme
  * Page directory and page table entries extended to 64 bits
    * Base address extended from 20 to 24 bits
    * Address space increased to ?
    
* x86-64


### 习题
13. （对应知识点1.3）动态重定位是在作业的执行过程中进行的
的
### Problem Set
