# CS61C discussion 01



## Depending on the context, the same sets of bits may represent different things.



依据上下文，相同的位可能表示出不同的数字

正确的，相同的位确实可以表示出不同的位，例如一组相同的位的数既可以表示有符号数也可以表示无符号数，如果第一位是1那么对于有符号数这个数有可能就是负数了，但对于无符号数就表示一个正数，同时如果相同的位也可以用很多表示形式例如补码，移码等，都可以解释这个问题。、

## It is possible to get an overflow error in Two’s Complement when adding numbers of opposite signs.

有一个可能的溢出错误当两个二进制补码进行相加的时候

这个说法是不正确的，溢出错误是指运算完的数字超出正确的数字范围，二进制补码的范围为![image-20230923150916365](C:\Users\29847\AppData\Roaming\Typora\typora-user-images\image-20230923150916365.png)超出这个范围我们可以说结果溢出，但是题目给出的是两个符号相反的数进行运算，因此不会发生溢出，如果两个数为相同符号的数，则有可能在运算完之后发生溢出。

## If you interpret a N bit Two’s complement number as an unsigned number, negative numbers would be smaller than positive numbers.

如果将 N 位二进制补码数解释为无符号数，则负数将小于正数。

这个说法是错误的，因为在二进制补码中第一位也就是MSB依然为符号位负数为1，而正数为0，将补码解释为无符号数则显然负数将大于正数。

## If you interpret an N bit Bias notation number as an unsigned number (assume there are negative numbers for the given bias), negative numbers would be smaller than positive numbers.

如果将 N 位偏差表示法数字解释为无符号数（假设给定偏差有负数），则负数将小于正数。

这个说法是正确的，因为n位偏差会使得所有的数加上偏差值来表示，因此正数加上一个数仍然会比负数大。

## Convert the following numbers from their initial radix into the other two common radices

二进制，十进制，十六进制转换

0b 1001 0011 = 147 = 0x 93

63 = 0b 0011 1111 = 0x 3F

0b 0010 0100 = 0x 24 = 36

39 = 0b 0010 0111 = 0x 23

437 = 0b 0001 1011 0101 = 0x 1B5

0x 0123 = 291 = ob 0000 0001 0010 0011

0x D3AD = 0b 1101 0011 1010 1101 = 54189 

0x B33F = 0b 1011 0011 0011 1111 = 45887 

0x 7EC4 = 0b 0111 1110 1100 0100 = 32452