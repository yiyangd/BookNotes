* 内存太小，不能永久保存，需要外存备份内存
* 磁盘：保存信息（程序与数据），文件系统：为存储与访问磁盘上的数据与程序提供机制
* 由于设备差异很大，所以操作系统需要提供一组功能以便于应用程序控制这些设备
* 操作系统的I/O子系统的重要目的之一是为系统其他部分提供最简单的接口。
* 文件系统由两个部分组成：文件（用于存储相关数据）目录（组织系统内的文件）


## Secondary Storage Systems

## File System Challenges
* File systems involve two `design` problems 文件系统的两个设计问题
* Interface: how file system looks to users
   * Define a "file", file attributes, operations on files, and how files are organized into directories
* Implementation:
   * data structures and algorithms to map logical file system onto physical devices
      * `Block allocation`, `free-space management`. searching a directory, data caching
     

## Layered Structure 分层设计结构
* Goal：Efficiently support different types of devices and file systems
* 设计中的每层利用较低层的功能创建新的功能来为更高层服务
* application programs     
* logical file system       ==> View files as logical blocks/ Maintain metadata 管理元数据
* file-organization module  ==> Maps logical blocks to physical blocks 
* basic file system 基本文件系统 ==> View data as physical blocks present in devices
         
* I/O control            ==> Device drivers and device-specific instructions  
                         ==> Read/Write bit patterns to device controller
* devices

## Interface: File Concept
> 为了方便使用计算机系统，操作系统提供了信息存储的统一逻辑接口。
> 操作系统对存储设备的各种属性加以抽象，从而定义了逻辑存储单元(文件),再将文件映射到物理设备上
> 数据除非在文件中，否则不能写到外存
* From user's perspective, a file is a storage unit
* A file is a named collection of related information
* Information(data) stored in a file could be of various types:
    * Text, numeric data
    * Binary data 二进制
    * Source code 源代码
    * Executable programs 可执行程序


## File Attributes 10.1.1 文件属性
* Name -- only information kept in human-readable form
* Identifier -- unique tag (number) identifies file within file system
* Type -- needed for systems that support different types
* Location -- pointer to file location on device
* Size -- current file size
* Protection -- controls who can do reading, writing, executing
* Time, date, and user identification -- for protection, security, and usage monitoring

* Information about files are kept in a `directory`, which is maintained on the disk as well
    * Each file has an entry in the directory 
* 目录存放在设备上，并在需要时分若干次调入内存

## File Operations 10.1.2 文件操作
> 文件属于抽象数据类型，为了合适地定义文件，需要考虑有关文件的操作 
> 操作系统提供`系统调用`对文件进行创建、写、读、定位、删除和截短
* Create
* Write
* Read
* Reposition within file
* Delete
* Truncate
* More operations(copy) can be composed of these primitives
* To perform these operations, we `open` the file (details later)

## File System Interface: Directory Concept 10.3 
> 每个磁盘分区(sector)可以创建一个大的文件系统，这些部分可以组成更大的可称为卷(volume)的结构

* Directory is a `logical` grouping of files
    * A directory contains an entry for each file under it
    * Some systems treat directories just as files 
        * In fact, UNIX treats everything as a file

* Operations on a directory
    * Search for a file 
    * Create a file 
    * Delete a file
    * List a Directory
    * Rename a file
    * Traverse the file system 

## Directory Structure 10.3.1

* Design the directory structure to achieve
    * Efficiency - locating a file quickly
    * Naming - convenient to users
        * Two users can have same name for different files
        * The same file can have several different names (aliases, links)
    * Grouping - logical grouping of files by properties 

* Tree-structured directories are the most common
    * Paths are intuitive for users
    * Efficient searching
    * Smarter grouping -- Sub-directories
    * Things get complicated with links


## Tree-Structured Directories 10.3.5
* 树是最为常用的目录结构，树有根目录，系统内的每个文件都有唯一路径名
* 每个进程都有一个当前目录
* 
*

## Acyclic-Graph Directories 10.3.6 无环图结构
* When files get deleted, links may still point to it
    * Dangling pointers
* Solution for dangling links in UNIX
    * Symbolic link 
    * Hard link 
* Links may even create a cycles



## General Graph Directory 10.3.7
* Search for a file through directory
* Backup entire file system 
    * We may visit the same subdirectory several times
    * We may even loop for ever if we have cycles 
* Solution?
    * Bypass links during directory traversal


## File System Mounting 10.4
> 文件要先打开再使用，文件系统在被系统上的进程使用之前必须安装
> 
* A file system must be mounted before it can be accessed
    * OS is given name of the device and a mount point
    * OS checks device to make sure it has a valid file system
    * Then, OS makes the new file system available 

## Virtual File Systems 11.2.3

## File System Implementation 11.2.1
* To implement a file system, we need
    * On-disk structures
        * Directory structure, number of blocks, location of free blocks,

## On-disk

## In-MEmory
## Openning  and Reading 11.2.1
## Creating a File


