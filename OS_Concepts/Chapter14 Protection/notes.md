## 1. Goals of Protection
* OS manages a collection of objects 对象集合
  * Hardware: CPU, memory segments, disks, printers, ...
  * Software: files, semaphores,... （信号量是软件？？）
* Each object has a name and can be accessed through a set of operations
  * Execute on CPU, read/write on files, ...
* Protection problem
  * Ensure that each object is accessed correctly and only by those processes that are allowed to do so
  
## 2. Principles of Protection
* Principle of Least Privilege 最小特权原则
  * Programs, users and systems should be given `just enough` privileges to perform their tasks
  * 规定程序、用户，甚至包括系统仅拥有它们能够完成其任务的特权
* Need to Know Principle 需要则知道
  * At any time, a process should be able to access only those resources that it currently requires to complete its task
  * 有效地限制错误进程对系统造成的伤害数量
* Policies versus mechanisms
  * Policies decide what will be done
  * Mechanisms determine how something will be done

## 3. Domain of Protection 保护域
* A process operates within a protection domain
  * Domain = set of access rights 域是访问权限的集合
  
* Access right = <object-name, rights-set>
  * rights-set is a subset of all valid operations that can be performed on the object
  * Domain D has the access right <file F, {read,write}>, then a process executing in domain D can both read and write file F.
  
* Static association 一个域和一个进程之间的静态关联
  * Process remains in its domain forever
  * Issues?
  * Difficult to maintain Need to Know Principle
* Dynamic association 动态关联
  * Processes can switch from one domain to another to access objects or perform needed operations
  *
*
## 4. Access Matrix 访问矩阵
* 

## 5. Implementation of Access Matrix 访问矩阵的实现
* Global Table

* Access Control List(`ACL`) for Objects
* Capability List for Domains

## 6. Revocation of Access Rights 访问权限的撤回

## 8. （14.3.2） Protection in UNIX
