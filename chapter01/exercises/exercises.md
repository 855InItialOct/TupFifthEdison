# 习题

## 1. 什么是程序？什么是程序设计？

- 程序：就是一组计算机能识别和执行的指令的集合。  
- 程序设计：是一个从确定任务到得出结果、写出文档的过程。

## 2. 为什么需要计算机语言？高级语言有哪些特点？

- 计算机语言解决了人和计算机的交流问题。  
- 特点：
  - 很接近人们使用的自然语言和数学语言；
  - 有丰富的数据结构；
  - 与计算机的内部结构和工作原理的关联不密切。

## 3. 正确理解一下名词及其含义

1. 源程序，目标程序，可执行程序。  
    - 源程序：是一组按特定的程序设计语言规范来书写的可读的计算机指令。  
    - 目标程序：源程序经编译器编译生成的以.obj为后缀的机器码集合。  
    - 可执行程序：是将所有目标模块与函数库连接后生成的计算机可以执行的程序，以.exe为后缀。
2. 程序编辑，程序编译，程序连接。  
    - 程序编辑：程序设计人员按一定的程序设计语言规范编写的文本文件。  
    - 程序编译：程序编译系统先用预处理器对程序中的预处理指令进行编译预处理，由预处理得到的信息和程序其他部分一起组成一个完整的、可用来进行正式编译的源程序，然后由编译系统对源程序进行检查，判断有无语法错误，如无语法错误，编译程序自动把源程序转换成二进制形式的目标程序。  
    - 程序连接：连接编辑程序把经过编译得到的二进制目标文件所组成的目标模块连接装配起来，再与函数库相连接成一个整体，生成一个可供计算机执行的目标程序。
3. 程序，程序模块，程序文件。  
    - 程序：就是一组计算机能识别和执行的指令的集合。  
    - 程序模块：可由汇编程序、编译程序、装入程序或翻译程序作为一个整体来处理的一级独立的、可识别的程序指令。  
    - 程序文件：存放程序的文件，包括源程序和可执行程序。
4. 函数，主函数，被调用函数，库函数。  
    - 函数：用来实现一定功能的代码模块。  
    - 主函数：程序的执行入口。  
    - 被调用函数：被另一个函数调用的函数。  
    - 库函数：编译程序提供的可被调用的函数。
5. 程序调试，程序测试。  
    - 程序调试：是一个程序运行前，由编译程序或人为等方法进行测试，来修正语法错误和逻辑错误的过程。
    - 程序测试：是对一个在完成了全部或部分功能、模块的计算机程序在正式使用前进行检测的过程。

## 4. 编写一个C程序，运行时输出："Hello World!"

`xt1-4.c`

## 5. 编写一个C程序，运行时输出以下图形

    *****  
      *****  
       *****  
         *****  
`xt1-5.c`

## 6. 编写一个C程序，运行时输入a,b,c三个值，输出其中最大值

`xt1-6.c`