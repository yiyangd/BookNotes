### 2.4 Transaction Processing

* A transaction is 

### ACID:
- Atomic:
  * 
- Consistent:
  * 
- Isolated:
- Durable:



#### Transaction Management

## Chapter 18. Concurrency Control
* The DBMS must handle concurrency such that
  * Isolation is maintained
  * Consistency is maintained

#### Interleaving 交叉，交错
* Need to swap the control of transaction execution between multiple simultaneous transaction
  * Example: 
    *  
    2.d 
* This is done for many simultaneous transactions
* This action is called as 
#### Scheduling
* A serial schedule is one that does not interleave the actions of different transactions
* A **serializable schedule** is a schedule that is equivalent to **some** serial schedule
* Two schedules are equivalent if, for any database state, the effect of executing them on database is **identical**
