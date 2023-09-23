

# CS61C lab01

需要从github下拉取代码

```
git remote add starter https://github.com/61c-teach/su20-lab-starter.git
```

```
git pull starter master
```

## lab01实验目标

- TSWBAT（“**学生**将**能够**”）在 EECS 教学计算机上编译和运行 C 程序，并检查C中不同**类型的**控制流
- TSWB（“ **The** Student **Will** Be ”）介绍了 C**调试**器并获得使用 gdb 调试 C 程序的实践**经验**
- TSWBAT 使用整数、字符、布尔表达式和位运算符来模拟 C 中的正则表达式。

编译c程序 可以使用gcc编译器进行编译但本人在进行CS61C 的lab中选择在本地使用vscode进行编译，编译器使用MINGW

## 练习 1：看看你能做什么 C

现在，查看 中包含的代码`eccentric.c`。**请注意**基本 C 控制流的四个不同示例。（思考：它们是什么？）另外，你认识这些古怪的说法和来自伯克利的人吗？:)

首先编译并运行该程序，看看它做了什么。尝试使用四个宏的常量值：V0 到 V3。了解更改它们中的**每一个**如何改变程序输出。

![image-20230919184512704](C:\Users\29847\AppData\Roaming\Typora\typora-user-images\image-20230919184512704.png)

那么如何编译这个文件那

gcc eccentric.c 这个命令使得eccentric.c文件可以生成一个a.exe可执行文件

./a.exe执行这个可执行文件 ./代表为当前目录

```
gcc -o program program.c
```

同时如果你想要自己定义exe文件的名称就可以使用上面那行命令

![image-20230919184854801](C:\Users\29847\AppData\Roaming\Typora\typora-user-images\image-20230919184854801.png)

## 练习 2：找出那些 bug！

调试**器**，顾名思义，是一个专门设计来帮助您查找代码中的错误或逻辑错误和错误的程序（旁注：如果您想知道为什么错误被称为错误，请看这里[）](https://www.quora.com/Why-are-errors-in-software-codes-called-bugs)。不同的调试器具有不同的功能，但所有调试器通常都能够执行以下操作：

1. 在程序中设置断点。断点是代码中您想要停止执行程序的特定行，以便您可以查看附近发生的情况。

2. 逐行执行程序。代码只会逐行执行，但它发生得太快，我们无法找出哪些行导致错误。能够逐行浏览代码可以让您准确地找出导致程序错误的原因。

3. GDB 代表“GNU De-Bugger”。`hello.c`使用标志编译`-g`：

4. ```
   $ gcc -g -o hello hello.c
   这会导致 gcc 将信息存储在可执行程序中以便gdb理解它。现在启动我们的调试器 (c)gdb：
   $ cgdb hello
   ```

在本机中由于没有ucb课程中的hive机器因此考虑使用本机的gdb也可以完成后续实验

```
$ gdb hello
```

使用这行代码也可以完成实验要求。

### 行动项目

通过执行以下操作逐步完成整个程序：

1. 在main处设置断点
2. 使用gdb的运行命令
3. 使用gdb的单步命令

从 gdb 中键入 help 来查找执行这些操作的命令，或者使用参考卡。

**如果您看到类似 printf.c: No such file or directory 的错误消息，请查看此处。** 您可能进入了 printf 函数！如果你继续前进，你会觉得你哪儿也去不了！CGDB 正在抱怨，因为您没有定义 printf 的实际文件。这很烦人。要摆脱这个黑洞，请使用命令 finish 运行程序，直到当前帧返回（在本例中，直到 printf 完成）。下**一次**，使用 next 跳过使用 printf 的行。

### 注意：cgdb 与 gdb

在本练习中，我们使用 cgdb 来调试我们的程序。cgdb 与 gdb 相同，只是它提供了一些额外的好功能，使其在实践中使用起来更加愉快。参考表中的所有命令都可以在 gdb 中使用。

在 cgdb 中，您可以按`ESC`进入代码窗口（顶部）并`i`返回命令窗口（底部）——类似于 vim。您可以在底部命令窗口中输入 gdb 命令。

在main处设置断点 break hello.c:3

run命令为运行

setp 【count】命令为单步执行count为想要执行的次数

https://inst.eecs.berkeley.edu/~cs61c/sp21/resources-pdfs/gdb5-refcard.pdf 附上gdb的指导手册可以查看所有gdb的命令



## 练习 3：使用 YOU 进行调试（ser 输入）

让我们看看如果您的程序需要用户输入并且您尝试在其上运行 GDB，会发生什么情况。首先，运行 定义的程序来与`interactive_hello.c`一个过于友好的程序进行对话。

```
$ gcc -g -o int_hello interactive_hello.c
$ ./int_hello
```

现在，我们将尝试调试它（即使确实没有错误）。

```
$ cgdb int_hello
```

## 练习 5：C 中的指针和结构

这是一个可以在面试中帮助您的方法。在 中`ll_cycle.c`，完成函数 `ll_has_cycle()`来实现以下检查单向链表是否有环的算法。

1. 从列表头部的两个指针开始。我们称第一个为乌龟，第二个为兔子。
2. 将兔子前进两个节点。如果由于空指针而无法做到这一点，则我们已找到列表的末尾，因此该列表是非循环的。
3. 将乌龟前进一节点。（空指针检查是不必要的。为什么？）
4. 如果乌龟和兔子指向同一个节点，则该链表是循环的。否则，返回步骤 2。

如果要查看`node`结构体的定义，请打开`ll_cycle.h` 头文件。

### 行动项目

实施`ll_has_cycle()`. 完成此操作后，您可以执行以下命令来运行代码测试。如果您进行**任何**更改，请确保按顺序再次运行以下**所有命令。**

```
$ gcc -c ll_cycle.c
$ gcc -c test_ll_cycle.c
$ gcc -o test_ll_cycle test_ll_cycle.o ll_cycle.o
$ ./test_ll_cycle
```

![image-20230920115638104](C:\Users\29847\AppData\Roaming\Typora\typora-user-images\image-20230920115638104.png)

控制台打印实验完成。

## 总结

本实验重点练习了，在本地计算机上如何使用gcc编译器进行编译程序，同时对c语言的一些基础内容进行回顾，内容相对比较简单。