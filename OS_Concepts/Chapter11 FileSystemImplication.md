## File System Implementation 

## On-disk Structures 磁盘结构
* Boot block 【引导控制块】: information to boot the OS
* Volume control block 【卷控制块】: information about the volume (partition)
  * Number of blocks, block size, free block count,...
  * UFS == superblock
  * NTFS = master file table
* `Directory structure`: how files are organized into directories
  * UFS == inodes 索引节点
  * NTFS stores this info in the master file table 存到主控表中
* File control block(FCB): per file, details about the file
  * Size, location of data blocks, file permissions, ownership
  * UFS == inode
  * NTFS stores this info in the master file table
  
## In-memory Structures
> 内存内信息用于文件系统管理并通过缓存来提高性能。这些数据在文件系统安装的时候被加载
* Mount table 【安装表】: Info on each mounted volume (partition)
* Directory-structure cache【目录结构缓存】: info on recently accessed directories
* System-wide open-file table 【系统范围内的打开文件表】:
  * Copy of the FCB of each open file in the system
  * Info on which process currently using which file
* Per-process open-file table 【单个进程的打开文件表】: contains an entry for each file opened by this process, which has
  * Pointer to entry in the system-wide open file table
  * Info regarding the usage of the file by this process, e.g.., current file pointer

## Opening a File
* Search the directory to find the `file control block`
  * May need to bring(from disk) multiple directory blocks into memory, if they are not already cached
* Create an entry in the `per-process open-file table` (PFT)
* Check whether the `system-wide open-file` table has an entry for this file
  * If it does
    * Increments its `reference count`
    * Make the `entry in PFT` point to this entry
  * If it does not
    * Create a new entry, set its reference count to 1
    * Make the entry in PFT point to the new entry
* Return a pointer(`file descriptor`) to the entry in PFT
  * Successive file operations (read, write, ...) use the file descriptor 【文件描述符】
  
## Creating a File
* Allocate a new file control block (FCB)
  * For faster file creation, FCBs are usually pre-allocated
    * Upon create, find a free FCB
* Read relevant directory blocks in memory
  * Update them to reflect the new file, write them back to disk
* Allocate free blocks for the data of the file
  * How? Allocation methods
  * Where? Bit map(空闲空间管理)

## Allocation methods
* Problem: Allocate free blocks to files
* Given: Disks allow `random access` of blocks
* Objectives: `Efficient` disk space utilization, and `fast` file access
* Three commomn allocation methods:

### Contiguous Allocation
* Each file occupies a set of contiguous blocks
* Needs only start address (block#) and length (number of blocks)
* 优点：Simple, Efficient sequential & random access (minimal disk head seeks)
* 缺点：External fragmentation & Files may not be able to grow

### Linked Allocation
* A file is a linked list of blocks
* Blocks could be anywhere
* Each block has a pointer to the next block
* Need start block and end block (to append to file)
* Let's say address is at Qth block in the chain, how do we get to it?
  * Traverse
* 优点：
  * Simple: need only start and end addresses
  * Doesn't waste space (except for pointers)
  * Supports dynamically growing files
* 缺点：
  * Expensive random access (need to follow pointers from the start)
  * Reliability: if one block is corrupted, the chain is broken
  
### Indexed Allocation
* Bring all pointers together into an index block
* 优点：
  * Supports random access
  * Supports dynamic growing of files
  * No external fragmentation
* 缺点：
  * Overhead of index blocks
    * File of `one or a few` data blocks would also need an entire index block
* Consider a file with one index block
* Assume each pointer takes 4 bytes, and block size is 512 bytes
* What is the maximum file size supported?


## Free-Space Management
* Bit Map
 * One bit for each block: `0 = occupied`, `1 = free`
 * 00011110 01100000 00001111 1.......1
 * Easy to find contiguous blocks
 * Supported by hardware
   * Single instruction to find offset of first bit with value 1 in a word (of 32 bits) --> fast searching
 * Disadvantages?
   * Bit map is stored on disk --> slow to access
     * Solution: cache it in memory
     * But bit maps are not small for large disks
     * Example: 400GB disk with 1KB blocks --> 400 M blocks
                --> 50 MB bitmap --> difficult to cache the entire bitmap
     * May group `multiple free blocks` to reduce bitmap size
 ![image](https://github.com/yiyangd/BookNotes/blob/master/OS_Concepts/img/12_10.jpg){:height="50px" width="50px"}
* Free-Space Management:
  * Linked List (空闲空间链表)：
    * No waste of disk space
    * Not easy to get contiguous space
  * Grouping:
    * Addresses of n free blocks are stored in the first block
    * The last block contains addresses to the following n free blocks
  * Counting:
    * Keep address of 1st free block & count of following free blocks
    * <addrFirstFreeBlock, count>
    
* Recovery
  * System failures occur anytime
    * Hardware defects, software bugs, external events
  * Crashes can leave file system in inconsistent state
    * E.g. incorrect metadata, lost data
  * File systems should have recovery mechanisms
  
  * Simple consistency checking
    * Set a bit (on disk) before metadata is to be update; reset it after metadata update is complete
    * 
