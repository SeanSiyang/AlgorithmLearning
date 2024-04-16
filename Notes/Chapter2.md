# 算法效率评估

渐近复杂度分析 asymptotic complexity analysis

复杂度分析能够体现算法运行所需的时间和空间资源与输入数据大小之间的关系。**它描述了随着输入数据大小的增加，算法执行所需时间和空间的增长趋势。**

- “时间和空间资源”分别对应「时间复杂度 time complexity」和「空间复杂度 space complexity」。
- “随着输入数据大小的增加”意味着复杂度反映了算法运行效率与输入数据体量之间的关系。
- “时间和空间的增长趋势”表示复杂度分析关注的不是运行时间或占用空间的具体值，而是时间或空间增长的“快慢”。

# 迭代与递归

## 迭代

迭代是**重复执行某个任务的控制结构**

在迭代中，程序会在满足一定的条件下重复执行某段代码，直到这个条件不再满足。

### for 循环

如果事先知道迭代次数时，适合使用 for 循环

```c++
/* for 循环 */
int forLoop(int n)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += i;
    }
    return res;
}
```

```python
def for_loop(n: int) -> int:
    """for循环"""
    res = 0
    for i in range(1, n + 1):   # range 左闭右开
        res += i
    return res
```

### while 循环

在 while 循环中，程序每轮都会先检查条件，如果条件为真，则继续执行，否则就结束循环。在 while 循环中，条件变量的初始化和更新步骤都是非常自由的。

```c++
/* while 循环（两次更新） */
int whileLoop(int n)
{
    int res = 0;
    int i = 1;
    while (i <= n)
    {
        res += i;
        i++;
    }
    return res;
}
```

```python
def while_loop(n: int) -> int:
    """while循环"""
    res = 0
    i = 1
    while i <= n:
        res += i
        i += 1
    return res
```

两次更新

```c++
/* while循环（两次更新） */
int whileLoopII(int n)
{
    int res = 0;
    int i = 1;
    while (i <= n)
    {
        res += i;
        i++;
        i *= 2;
    }
    return res;
}
```

```python
def while_loop_ii(n: int) -> int:
    """while 循环（两次更新）"""
    res = 0
    i = 1
    while i <= n:
        res += i
        i += 1
        i *= 2
    return res
```

### 双层循环

循环里嵌套一个循环

```c++
/* while 循环（两次更新）*/
int whileLoopII(int n)
{
    int res = 0;
    int i = 1;
    while (i <= n)
    {
        res += i;
        i += 1;
        i *= 2;
    }
    return res;
}

/* 双层 for 循环 */
std::string nestedForLoop(int n)
{
    std::string res = "";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 需要手动将非字符串变量转为字符串变量
            res += "(" + std::to_string(i) + ", " + std::to_string(j) + ")";
            if (i != n || j != n) // check if it is a last iteration
            {
                res += ", ";
            }
            // std::string str1 = "(" + std::to_string(i);
            // std::string str2 = ", ";
            // std::string str3 = std::to_string(j) + "), ";

            // res += (str1 + str2 + str3);
        }
    }
    return res;
}

/*
 * std::stringstream可以减少内存分配和拷贝的次数，因为它会在内部维护一个缓冲区
 * 而不是每次都分配新的内存空间进行字符串拼接。
 * 使用<<操作符可以直接向std::stringstream中添加数据，使得代码更加清晰易读。
 * std::stringstream可以方便地进行不同类型的数据转换，例如将整数、浮点数等转换为字符串。
 */
std::string nestedForLoopII(int n)
{
    std::stringstream res;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            res << "(" << i << ", " << j << ")";
            if (i != n || j != n) // check if it is a last iteration
            {
                res << ", ";
            }
        }
    }
    return res.str();
}
```

每添加一次嵌套循环，都是一次升维，将使时间复杂度提高一个维度

## 递归

递归通过函数调用自身来解决问题

递：程序不断深入地调用自身，通常传入更小或更简化的参数，直到达到“终止条件”

归：触发“终止条件”后，程序从最深层的递归函数开始逐层返回，汇聚每一层的结果

递归三个要素：

1. 终止条件：用于决定什么时候由“递”转“归”

2. 递归调用：对应“递”，函数调用自身，通常输入更小或更简化的参数

3. 返回结果：对应“归”，将当前递归层级的结果返回至上一层

```python
def recur(n: int) -> int:
    """递归"""
    # 终止条件
    if n == 1:
        return 1
    # 递：递归调用
    res = recur(n - 1)
    # 归：返回结果
    return n + res
```

```c++
/* 递归 */
int recur(int n)
{
    if (n == 1)
        return 1;

    int res = recur(n - 1);

    return n + res;
}
```

迭代：“自下而上”地解决问题。从最基础的步骤开始，然后不断重复或累加这些步骤，直到任务完成

递归：“自上而下”地解决问题。将原问题分解为更小的子问题，这些子问题和原问题具有相同的形式。接下来将子问题继续分解为更小的子问题，直到基本情况时停止（**基本情况的解是已知的**）

### 调用栈

递归函数每次调用自身时，系统都会为新开启的函数分配内存，以存储局部变量、调用地址和其他信息等。这将导致两方面的结果:

- 函数的上下文数据都存储在称为“栈帧空间”的内存区域中，直至函数返回后才会被释放。因此，**递归通常比迭代更加耗费内存空间**

- 递归调用函数会产生额外的开销。因此**递归通常比循环的时间效率更低**

过深的递归可能导致栈溢出错误

### 尾递归

如果函数在返回前的最后一步才进行递归调用，则该函数可以被编译器或解释器优化，使其在空间效率上与迭代相当。这种情况被称为尾递归（tail recursion）

> 尾：返回前的最后一步

- 普通递归：当函数返回到上一层级的函数后，需要继续执行代码，因此系统需要保存上一层调用的上下文。

- 尾递归：递归调用是函数返回前的最后一个操作，这意味着函数返回到上一层级后，无须继续执行其他操作，因此系统无须保存上一层函数的上下文。

```c++
/* 尾递归 */
int tailRecur(int n, int res)
{
    if (n == 0)
        return res;
    return tailRecur(n - 1, res + n);
}
```

```python
def tail_recur(n, res):
    """尾递归"""
    if n == 0:
        return res
    return tail_recur(n - 1, res + n)
```

个人想法：尾递归达到返回条件时，已经计算得到最后结果了，在归的过程中，结果的值是不改变的（每层返回以后不再进行任何操作）

普通递归和尾递归求和过程不太一样：

- 普通递归：求和操作是在“归”的过程中执行的，每层返回后都要再执行一次求和操作。
- 尾递归：求和操作是在“递”的过程中执行的，“归”的过程只需层层返回。

注：尾递归形式应该是递归调用的结果直接返回，而不经过其他计算

### 递归树

当处理分治相关的算法问题，可以考虑使用递归，思路更加直观、代码更加易读。

斐波那契数列：0, 1, 1, 2, 3, 5, 8, 13, ... 求该数列的第 n 个数字

设斐波那契数列的第 n 个数字为 $f(n)$, 易得两个结论：

- 数列的前两个数字为 $f(1) = 0$ 和 $f(2) = 1$

- 数列中的每个数字是前两个数字的和，即$f(n) = f(n-1) + f(n-2)$

按照递推关系进行递归调用，将前两个数字作为终止条件

```c++
/* 斐波那契数列：递归 */
int fib(int n)
{
    if (n == 1 || n == 2)
        return n - 1;

    int res = fib(n - 1) + fib(n - 2);

    return res;
}
```

```python
def fib(n: int) -> int:
    """ 斐波那契数列：递归 """
    if n == 1 or n == 2:
        return n - 1
    res = fib(n - 1) + fib(n - 2)

    return res
```

在函数内递归调用了两个函数，这意味着从一个调用产生了两个调用分支

这样不断递归调用下去，最终将产生一棵层数为$n$的递归树（recursion tree）

以上述递归函数为例，求和操作在递归的“归”阶段进行。这意味着最初被调用的函数实际上是最后完成其求和操作的，这种工作机制与栈的“先入后出”原则异曲同工。

事实上，“调用栈”和“栈帧空间”这类递归术语已经暗示了递归与栈之间的密切关系。

1. 递：当函数被调用时，系统会在“调用栈”上为该函数分配新的栈帧，用于存储函数的局部变量、参数、返回地址等数据。

2. 归：当函数完成执行并返回时，对应的栈帧会被从“调用栈”上移除，恢复之前函数的执行环境。

