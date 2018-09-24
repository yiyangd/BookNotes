5.1 Background
* Cooperating processes can either directly share a logical address space (that is, both code and data) or be allowed to share data only through files or messages.
*多个进程并发访问和操作同一数据且执行结果与访问发生的特定顺序有关，称为竞争条件
*为了避免 ==> ensure that only one process at a time can be manipulating the variable counter ==> require that the processes be synchronized in some way.
