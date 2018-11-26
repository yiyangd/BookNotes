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
  * Difficult to maintain `Need to Know Principle`
  
* Dynamic association 动态关联
  * Processes can switch from one domain to another to access objects or perform needed operations
  * 
* Realizing Domain 实现域
  * Each user is a domain
    * Access depends on user's id 可以访问的对象集取决于用户的身份
    * Domain switching: user switching (or logout/login) 一般的情形是一个用户登出，另一个用户登入
  * Each process is a domain:
    * Access depends on process's id
    * Domain switching: message passing between processes 一个进程发送给另外一个进程并等待回复
  * Each procedure is a domain:
    * Access depends on local variables in procedure
    * Domain switching: procedure calls 过程调用发生时域切换
    
## 4. Access Matrix 访问矩阵
* View protection as a matrix (access matrix)
  * Rows represent domains; columns represent objects
  * Entry (i,j): define the set of operations that a process executing in domain i can invoke on object j
* Need to allow a process to `switch` domains
  * Consider domains as objects (add them to access matrix)
  * If it has a "`switch`" right on these domains
  
  
## 5. Implementation of Access Matrix 访问矩阵的实现
* Global Table

* Access Control List(`ACL`) for Objects 对象的访问列表
* Capability List for Domains 域的权限列表

## 6. Revocation of Access Rights 访问权限的撤回

## 7. Combination of Capabilities and ACL 访问&权限列表结合
* When process tries to access object, ACL is searched
* If approved, a capability is created and attached to process
* Subsequent accesses use the capability (for faster check)


## 8. （14.3.2） Protection in UNIX
