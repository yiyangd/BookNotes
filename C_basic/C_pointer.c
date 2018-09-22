// 菜鸟教程
//学习 C 语言的指针既简单又有趣。通过指针，可以简化一些 C 编程任务的执行，
//还有一些任务，如动态内存分配，没有指针是无法执行的。
//每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，它表示了在内存中的一个地址。
//请看下面的实例，它将输出定义的变量地址：

#include <stdio.h>
int main()
{
  int var1 = 20;
  char var2[10];
  // 用 &var 访问内存地址
  printf("Address of var1: %p \n", &var1 );  //0x7fff5cc109d4
  printf("Address of var2: %p \n", &var2 );  //0x7fff5cc109de
  
  // 指针是一个变量，其值为另一个变量的地址 type *var——name；
  // 所有数据类型的指针都是一个代表内存地址长的十六进制数
  // %p 地址identifier
  
  // 定义一个指针变量、把变量地址赋值给指针、访问指针变量中可用地址的值。
  int *ip = &var1; // 在指针变量中存储 var 的地址
  printf("Address stored in ip variable: %p \n", ip); // 在指针变量中存储的地址 = &var
  printf("Value of *ip variable: %d\n", *ip); // 使用指针访问值 = 20
  
  // NULL指针是一个定义在标准库中的值为零的常量
  int *ptr = NULL;
  printf("ptr 的地址是 %p \n", ptr);  // 0x0
  
  /*
  在大多数的操作系统上，程序不允许访问地址为 0 的内存，因为该内存是操作系统保留的。
  然而，内存地址 0 有特别重要的意义，它表明该指针不指向一个可访问的内存位置。
  但按照惯例，如果指针包含空值（零值），则假定它不指向任何东西。
  */
  
  // 指针的指针
  int **pptr = &ptr //获取ptr的地址
  printf("Value available at **pptr = %d \n", **pptr);
  
  return 0;
  
}
