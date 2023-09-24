# CS61C 03 discussion

## True or False. The goals of floating point are to have a large range of values, a low amount of precision, and real arithmetic results

浮点的目标是具有大范围的值、低精度和真实的算术结果

对于这个回答我觉得是错误的，浮点数其实是可以表示很大的范围的数同时也可以表示很小范围的数，在之前的课程中已经提到过这个，浮点数是可以表示正无穷，负无穷等这类数的，同时浮点数也可以表示很小的数，这其实给我们带来了很大的遍历。同时浮点数是具有很高的精度。

## The distance between floating point numbers increase as the absolute value of the numbers increase.

两个浮点数之间的距离会随着数的绝对值增加而增加

这个说法应该是正确的

## Floating Point addition is associative.

浮点数加法满足结合律

这个说法是错误的，因为浮点数其实有效数字位数只有23位因此，当我们将一个大数与一个小数相加再与一个大数相加，这样的结果是会与两个大数相加再加上一个小数结果不同，因为有效数字的位数23位限制了和截断了我们小数的后面的数字，因此其实是不满足加法结合律。

