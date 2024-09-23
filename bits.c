/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
//bit-level
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // 由德摩根律: (x & ~y) | (y & ~x) = ~(~(x & ~y) & ~(y & ~x))
  return ~(~(x & ~y) & ~(y & ~x));
}

/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  // n << 3 = n * 8
  // x 右移 n 个字节的位, 最后和掩码 0x000000ff 按位与
  return (x >> (n << 3)) & 0xff;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  int sign = (x & (0x1 << 31));

  // x > 0, mask = 0xffffffff; x < 0, mask = (n个0, 32-n个1)
  int mask = ~((sign >> n) << 1);
  return (x >> n) & mask;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int _mask1 = 0x55 | (0x55 << 8);
  int mask1 = _mask1 | (_mask1 << 16); // 0x55555555
  int _mask2 = 0x33 | (0x33 << 8);
  int mask2 = _mask2 | (_mask2 << 16); // 0x33333333
  int _mask3 = 0x0f | (0x0f << 8);
  int mask3 = _mask3 | (_mask3 << 16); // 0x0f0f0f0f
  int mask4 = 0xff | (0xff << 16); // 0x00ff00ff
  int mask5 = 0xff | (0xff << 8); // 0x0000ffff
  // x & 0x55555555 只留下奇数位的 1
  // (x >> 1) & 0x55555555 只留下偶数位的 1, 并且因为向右移 1 位, 导致和奇数位留下的 1 对齐
  // 因此它们相加后, 每两位的值代表原 x 中那两位 1 的个数
  x = (x & mask1) + ((x >> 1) & mask1);
  // 同理, 这里相加的结果是: 每四位是原 x 中对应那四位中 1 的个数
  x = (x & mask2) + ((x >> 2) & mask2);
  // 以此类推: 每八位是原 x 中对应那八位中 1 的个数
  x = (x & mask3) + ((x >> 4) & mask3);
  // 以此类推: 每十六位是原 x 中对应那十六位中 1 的个数
  x = (x & mask4) + ((x >> 8) & mask4);
  // 以此类推: 每三十二位是原 x 中对应那三十二位中 1 的个数, 即我们要求的 bitCount
  x = (x & mask5) + ((x >> 16) & mask5);
  return x;
}

/*
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */

int conditional(int x, int y, int z) {
  // 真, 选 y, x != 0, !x = 0x00, mask = 0xffffffff
  // 假, 选 z, x == 0, !x = 0x01, mask = 0x00000000
  int mask = !!x << 31 >> 31;
  return (y & mask) | (z & ~mask);  // 如果 mask 为全 1, 返回 y; 如果 mask 为全 0, 返回 z
}
//two's complement
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // 最小的数: -2147483648 = 0x800000000 = 0b10000000000000000000000000000000
  return (0x1) << 31; // 1 后面 31 个 0
}

/*
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  // n >= 0, ~n = (-n) 的反码 = (-n) 的补码 - 1 = -n - 1 = - (n + 1)
  // -n = ~n + 1
  // 32 - n = 32 + ~n + 1
  int b = 32 + ~n + 1; // 移动位数 32 - n 位
  // 0..0101 = 5 向左移动 32 - 3 = 29 位, 得到 1010..0, 再右移 29 位得到 1..1101, 错误
  // 1..1100 = -4 向左移动 29 位, 得到 1000..0, 再右移 29 位得到 1..1100, 和原数相同
  int t = x << b >> b;
  return !(x ^ t); // !(x ^ y) => x == y
}

/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n) {
  // 题目要求是向零舍入, 也就是正数向下舍入, 负数向上舍入
  int mask = (0x1 << n) + ~0; // 得到最低位开始的连续 n 个 1
  int sign = x >> 31; // 符号位

  // 正数, mask 最低位变为 0; 负数, mask 不变
  int bias = sign & mask; // 偏正的因子

  // x + 偏移因子后，负数会向上取整
  return (x + bias) >> n;
}

/*
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // x 先异或相邻的数，可以把前面的一长串 0 或 1 全部变为 0
  // 如 (12)0..01010，经过异或后变为 0..011110，最高位为 4，加上符号位为 5，即为答案
  // 如 (-5)1..1011，经过异或后变为 0..01100，最高位为 3，加上符号位为 4，即为答案
  int y = x ^ (x << 1);

  // 寻找 y 最高位
  int mask = ~0; // 0xffffffff
  int count = 0;
  count += (!!(y & (mask << 16))) << 4;
  count += (!!(y & (mask << (count + 8)))) << 3;
  count += (!!(y & (mask << (count + 4)))) << 2;
  count += (!!(y & (mask << (count + 2)))) << 1;
  count += (!!(y & (mask << (count + 1))));

  // 最后 +1, 补上符号位的一位
  return count + 1;
}

/*
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // => x <= y ? 1 : 0
  // => x - y > 0 ? 0 : 1
  // => x + ~y + 1 > 0 ? 0 : 1
  // int ans = x + ~y + 1;

  // ans > 0 => ans 的最高位为 0 且 ans 不为 0
  // => (ans & (0x1 << 31)) == 0 && ans & (0xffffffff) != 0
  // => !(ans & (0x1 << 31)) == 1 && !!(ans & (0xffffffff)) == 1
  // => ((!(ans & (0x1 << 31))) & (!!(ans & (0xffffffff)))) == 1

  // 由于 ans > 0, 输出 0, 因此最后给整个 ((!(ans & (0x1 << 31))) & (!!(ans & (0xffffffff)))) 加上 !
  // isLessOrEqual(int x, int y) = !((!(ans & (0x1 << 31))) & (!!(ans & (0xffffffff))));
  // 使用 x + ~y + 1 替换 ans, 使用 ~0 替换 0xffffffff:
  // return !((!(x + ~y + 1 & (0x1 << 31))) & (!!(x + ~y + 1 & (~0))));
  // 上面的方法会有溢出的风险, 比如 x = 0x80000000, y = 0x7fffffff, 最后结果溢出, 导致答案错误

  // x <= y
  // => x < y + 1
  // => x - y - 1 = x + ~y < 0
  // val = 1 时, 为真
  int val = !!((x + ~y) >> 31);
  x = x >> 31;
  y = y >> 31;
  // 先判断 x 与 y 的符号, 
  // 如果 x 为负, y 为正, 直接返回 1; !!x & !y = 1
  // 如果 x 为正, y 为负, 直接返回 0; !x & !!y = 1
  // 然后就是全正数和全负数的减法, 这样不会溢出
  // (x 为负, y 为正) | (非(x 为正, y 为负) & val)
  return (!!x & !y) | (~(!x & !!y) & val);
}

/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x) {
  int mask = ~0; // 0xffffffff
  int count = 0;
  // 判断 x 16~31 位是否有数, 有则使用 !! 将其变为 1, 并且 1<<4=16, 为 count 赋初值 16
  count += (!!(x & (mask << 16))) << 4;
  // 若此时 count = 16, 说明最高位 >= 16, 因此需要进一步向上试探
  // - 再使用“折半法”, 试探前四分之一, 即 24~31 是否有数, 有则 count+8=24, 意为 x 的最高位 >= 24
  // 若此时 count = 0, 说明 x 的前 16 位均为 0, 因此试探第 8~15 位是否有数
  // - 有则 count+8=8, 说明 x 的最高位在 8~15 位
  count += (!!(x & (mask << (count + 8)))) << 3;
  // 以此类推, 直到最小区间变为 1, 即只需判断最后一位是否为 1。
  // 总体思路: 将判断 x 是否有数的区间大小, 从 16 -> 8 -> 4 -> 2 -> 1, 最终得到精确的位
  count += (!!(x & (mask << (count + 4)))) << 2;
  count += (!!(x & (mask << (count + 2)))) << 1;
  count += (!!(x & (mask << (count + 1))));

  return count;
}
//float
/* 
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
  // NaN 直接返回自身，判断 NaN 的依据是指数部分全为 1，且小数部分不全为 0
  if (!((uf & 0x7f800000) ^ 0x7f800000) && (uf & 0x007fffff))
    return uf;

  // 不是 NaN 则直接改变符号位为 0
  return uf & 0x7fffffff;
}

/*
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale1d2(unsigned uf) {
  unsigned sign = uf & 0x80000000; // 提取符号位
  unsigned exp = (uf >> 23) & 0xff; // 提取指数位

  // 如果为 INF(指数为 0xff 且小数部分为 0) 或 NaN(指数为 0xff 且小数部分 > 0)
  if (exp == 0xff) {
    return uf; // NaN 或无穷大，直接返回原值
  }

  // exp > 1，直接 exp - 1
  if (exp > 1)
    return (uf & 0x807fffff) | (--exp) << 23;

  // 小数部分移位后需要向上取整，因此最低位若为 011，则移位后应变为 010 而不是 001
  // 进行特殊处理：
  // 011 + 010 = 101，101 经过 >> 1 后变为 010，成功向上取整
  if ((uf & 0x3) == 0x3)
    uf = uf + 0x2;

  // 此时指数位为 0 或 1；
  // 若为 0，则直接右移经过特殊处理后的小数部分
  // 若为 1，则把指数位最低位的 1，移动到小数部分的最高位
  // 因此操作为 uf >> 1，但是要避免符号位为 1 时影响指数位最高位，因此结果要 & 0x3fffffff，使指数位最高位为 0
  return ((uf >> 1) & 0x3fffffff) | sign; // 0x3fffffff 的指数位的最高位必为 0，否则 >> 1 后会受到符号位影响
}

/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int sign = uf >> 31; // sign 仅有符号这一位
  int exp = ((uf & 0x7f800000) >> 23) - 127; // exp 为减去偏移量 127 后的结果，-127 <= exp <= 128
  int frac = (uf & 0x007fffff) | 0x00800000; // frac 为小数部分加上整数部分的 1

  // exp >= 32，超过 int 的上限，返回 0x80000000
  if (exp > 31)
    return 0x80000000;

  // exp < 0 或 uf == 0, 返回 0
  if (exp < 0 | !(exp | frac))
    return 0;

  // 将小数部分移动合适的位数，变为整数，exp > 23 则左移使 frac 继续变大
  if (exp > 23)
    frac <<= (exp - 23);
    // exp <= 23 则右移，使 frac 缩小
  else
    frac >>= (23 - exp);

  // 若为正数，则直接返回 frac
  if (!(sign ^ 0x0))
    return frac;
  // 负数则返回补码，负数的补码等于绝对值取反 + 1
  else
    return ~frac + 1;
}
