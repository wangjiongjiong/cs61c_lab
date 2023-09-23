# cs61c_lab02

## 练习 0：Makefile

正如您在实验 01 中看到的，在终端中编译 C 程序是一项繁琐且耗时的操作，需要运行带有长串参数的多个命令。虽然这对于简单的 C 程序来说是可行的，但对于通常具有数十个文件和依赖项的更大、更复杂的程序来说，这很快就会变得相当不方便。

对于大型、复杂的程序，大多数 C 程序员都会编写所谓的“makefile”来帮助编译。makefile 是代码目录中的一个文本文件（字面上标记为“Makefile”），其中包含一组规则，每个规则都有为其编译 C 程序的命令。每个makefile 可以包含多个规则，每个规则编译一个或多个目标（例如可执行文件）或执行不同的目标。要编译目标，程序员只需输入“make”进入他们的命令终端。

查看本实验中包含的“Makefile”，并尝试回答“make.txt”中的以下问题。请随意使用互联网来解决其中一些问题。

1. 哪个目标是删除所有已编译程序的规则的一部分？
2. 哪个目标是生成所有编译程序的规则的一部分？
3. 目前使用的是哪个编译器？
4. 我们目前使用什么C标准？
5. 我们如何在 makefile 中引用变量 FOO？
6. “达尔文”一词代表什么操作系统？
7. 哪一行从目标文件创建 lfsr 程序？（给出其行号。）

Makefile 看起来令人畏惧，但实际上是一个神奇的工具，可以帮助节省大量时间！

## 练习 1：位运算

对于本练习，您将`bit_ops.c`通过实现位操作函数`get_bit`、`set_bit`和`flip_bit`（如下所示）来完成。您只能使用按位运算，例如与 (&)、或 (|)、异或 (^)、非 (~)、左移 («) 和右移 (»)。您不得使用任何 for/while 循环或条件语句。此题也不得使用模 (%)、除法、加减法或乘法。

```
// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x, unsigned n);

// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned *x, unsigned n, unsigned v);

// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned *x, unsigned n);
```

**行动项目**：完成实施`get_bit`、、`set_bit`和`flip_bit`。

完成这些功能后，您可以使用以下命令编译并运行代码：

```
$ make bit_ops
$ ./bit_ops
```

这将打印出一些有限测试的结果。

练习1考验了对于c语言的基本运算符的考察 <<为左移向右补0；>>为右移向左补0 ;^异或运算为相同为0不同为1这些运算都是c语言的基础运算符，但是通过实验发现对于c语言的掌握并不是很扎实，在后面的学习中要继续巩固c语言的学习。

## 习 2：线性反馈移位寄存器

在本练习中，您将实现一个`lfsr_calculate()`函数来计算线性反馈移位寄存器 (LFSR) 的下一次迭代。使用 LFSR 的应用有：数字电视、CDMA 手机、以太网、USB 3.0 等等！该函数将使用按位运算符生成伪随机数。有关更多背景信息，请阅读[维基百科有关线性反馈移位寄存器的文章](https://en.wikipedia.org/wiki/Linear-feedback_shift_register)。在 中`lfsr.c`，填写该函数`lfsr_calculate()`，使其执行以下操作：

![image-20230920161909137](C:\Users\29847\AppData\Roaming\Typora\typora-user-images\image-20230920161909137.png)

### 解释

- 每次调用 时`lfsr_calculate`，您都会将寄存器的内容右移 1 位。
- 这种移位既不是逻辑移位也不是算术移位。在左侧，您将移入一位，该位等于最初位于位置 0、2、3 和 5 的位的异或 (XOR)。
- 弯曲的头灯形状的物体是一个 XOR，它接受两个输入 (a, b) 并输出 a^b。
- 如果实现`lfsr_calculate()`正确，它应该在循环回起始数字之前输出所有 65535 个正 16 位整数。
- 请注意，最左边的位是 MSB，最右边的位是 LSB。

**行动项目**：实施`lfsr_calculate()`、编译`lfsr`并运行它。验证输出是否如下所示：

```
$ make lfsr
$ ./lfsr
My number is: 1
My number is: 5185
My number is: 38801
My number is: 52819
My number is: 21116
My number is: 54726
My number is: 26552
My number is: 46916
My number is: 41728
My number is: 26004
My number is: 62850
My number is: 40625
My number is: 647
My number is: 12837
My number is: 7043
My number is: 26003
My number is: 35845
My number is: 61398
My number is: 42863
My number is: 57133
My number is: 59156
My number is: 13312
My number is: 16285
 ... etc etc ...
Got 65535 numbers before cycling!
Congratulations! It works!
```

实验思路，因为实验要求0235位相互异或因此首要的目的是要获取到0235各个位置的数，考虑将原来的16位数依次右移来获取对应的位数同时使用&1来获取数，因为任何数与1&还是他本身无论0，1。在异或之后我们获取到了最后16位数右移后补的数，因此考虑将16位数右移一位，将获得的数左移15位并将两个数进行|运算，因为16位数右移之后最高位一定是0因此我们使用|运算可以将想要插入的数进行补位。这个练习还是在练习c语言的基础运算符，在实验过程中发现对于>>和<<运算的理解还是有欠缺，比如最后一步时由于理解错误将16位数的右移写成了左移导致一直debug浪费了太多时间，因此这块是我比较薄弱的内容需要重点注意了。

## 练习 3：链接列表

对于本练习，您将填写函数`append_node()`和。不要忘记查看节点结构的定义以及简单 .h（头）文件的一般格式！`reverse_list()``list.c``list.h`

在 中`append_node()`，您将向链表的末尾追加一个节点。

在 中，您将**就地**`reverse_list()`反转链接列表（即不创建新列表）。例如，列表将变为. 提示：在遍历链表的循环的每次迭代中，请考虑在反转链接之前需要在变量中存储哪些信息，以便您仍然可以成功地继续迭代列表并反转链接。这是 C 语言中相当困难的练习；如果您遇到困难，我们建议您画一张图，因为这样做往往会使双指针看起来不那么令人生畏。在向助教寻求帮助之前，请写下您认为应该采用的算法。**您可以将双指针简单地视为指向节点指针列表的指针。**`1->2->3->4->5``5->4->3->2->1`

为什么这两个函数都接受 a`node**`而不是 a `node*`？考虑内存管理；如果输入是节点*，是否可以修改从 main() 函数传递到函数的指针？请记住，C 是按值传递的！

**行动项目**：完成实施`append_node()`并`reverse_list()`。

完成这些功能后，您可以使用以下命令编译并运行代码。如果您进行**任何**更改，请确保按顺序再次运行以下**所有命令。**

**如果您在本地编译并运行，测试可能会打印出节点的下一个属性是 0x0，并且测试失败。这完全没问题；您的测试将通过自动评分器。如果您想完全确定您的测试在本地通过，请在 hive 计算机上编译并运行您的代码**。

```
$ gcc -c list.c
$ gcc -c test_list.c
$ gcc -g -o test_list test_list.o list.o       # This will create an executable by linking test_list.o and list.o.
$ ./test_list
```

这将打印出测试结果。要进行调试，您可以运行 CGDB 并在`test_list.c`.

这个实验是一个比较经典的c语言指针练习，主要思路为prev指针主要指向前一个节点，next指向下一步需要进行的操作的节点。

## 练习 4：内存管理

本练习使用`vector.h`、`vector_test.c`和`vector.c`，我们为您提供了实现可变长度数组的框架。本练习旨在帮助您熟悉 C 结构和 C 中的内存管理。

**行动项目**：解释为什么`bad_vector_new()`和`also_bad_vector_new()`不好，并填写函数`vector_new()`、`vector_get()`、`vector_delete()`和`vector_set()`in `vector.c`（以及 中的函数头`vector.h`），以便我们的测试代码`vector_test.c`运行时不会出现任何内存管理错误。`vector_test`另外，在 makefile 中为目标实施规则。

代码中的注释描述了函数应该如何工作。查看我们填写的函数，了解应如何使用数据结构。为了保持一致性，*除非用户设置，否则假设向量中的所有条目均为 0。请记住这一点，因为`malloc()`不会将其分配的内存清零。*

为了解释为什么这两个坏函数不正确，请记住，其中一个函数实际上会正确运行（假设正确修改了`vector_new`、`vector_set`等），但可能存在其他问题。**提示**：考虑内存使用情况。

**行动项目**：测试`vector_new()`、`vector_get()`、`vector_delete()`、 和的实现`vector_set()`的正确性和内存管理（详细信息如下）。

```
# 1) to check correctness
$ make vector_test
$ ./vector_test

# 2) to check memory management using Valgrind:
$ make vector-memcheck
```

该`vector-memcheck` [规则](https://www.gnu.org/software/make/manual/make.html#Rule-Introduction)所做的就是在我们的可执行文件上运行以下 valgrind 命令。如需回顾，请通读[实验 1](https://inst.eecs.berkeley.edu/~cs61c/su20/labs/lab01/)中的练习 4 。向自己解释每个标志的含义。

```
$ valgrind --tool=memcheck --leak-check=full --track-origins=yes [OS SPECIFIC ARGS] ./<executable>
```

valgrind 输出中的最后一行将一目了然地表明是否出现问题。下面是一个有缺陷的程序的输出示例：

```
==47132== ERROR SUMMARY: 1200039 errors from 24 contexts (suppressed: 18 from 18)
```

如果您的程序有错误，您可以在命令行输出中向上滚动以查看每个错误的详细信息。出于我们的目的，您可以安全地忽略所有涉及被抑制错误的输出。在无泄漏程序中，您的输出将如下所示：

```
==44144== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 18 from 18)
```

同样，任何数量的抑制错误都可以；它们不会影响我们。

您也可以随意使用 CGDB 或添加`printf`语句`vector.c`来`vector_test.c`调试您的代码。

本实验重点练习了对内存的管理

在创建vector的函数中首先对vector数组指针进行malloc分配内存，同时在分配时需要对分配是否成功进行判断

其次在vector的data数组中结构体定义也为指针所以同时需要对data进行malloc申请空间。重要的是如果申请空间失败一定要及时free掉空指针避免造成内存垃圾这是创建vector函数中需要注意的几个地方。

同时本实验的另一个难点问题就是set函数，该函数的目的是要对vector数组进行赋值，如果在vector现存的长度内那么问题很好考虑我们只需要让data数组相对应的值等于我们所要赋的值即可，但如果我们想要插入的长度大于我们vector现存的长度，我们需要对data指针进行realloc操作即继续申请空间，同时与创建vector函数相同的是需要判断data空间是否申请成功，用来做异常判断。

## 总结

本次lab主要练习的还是c语言的基础内容包括c语言基础运算符这一部分我掌握的不是很好，后续需要对此进行加强，同时本实验还练习了对指针的操作，这一部分要重点掌握，练习四中对vector进行了自己的实现，对STL模板库有了初步的了解，希望后续可以勤加练习，c语言是一门比较难的语言，学好c语言对后续的学习有着很大的帮助。

