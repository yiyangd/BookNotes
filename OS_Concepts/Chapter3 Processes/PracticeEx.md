3.1
* The memory pages which are used by original process are then duplicated after `fork() system call`.
  * Same between parent and child processes: image, because they have same memory as original process
  * Difference: 
    * if fork() call returns in parent process, return value will be process id of child process
    * if returns in child process, then return value = 0
    * if call `fails` and no new process created then return value will be -1
* value = 5 as child process updatres only its copy of value and after that control will be returned to parent process in which the value of value remains at 5
