#include <iostream>
#include <stack>

/* 递归：在归的过程中进行计算 */
int recur(int n)
{
    // 终止条件
    if (n == 1)
        return 1;
    // 递：递归调用
    int res = recur(n - 1);
    // 归：返回结果
    return n + res;
}

/* 尾递归：在递的过程中进行计算 */
int tailRecur(int n, int res)
{
    // 终止条件
    if (n == 0)
        return res; // 此时res已经计算好了

    // 尾递归调用
    return tailRecur(n - 1, res + n);
}

/* 斐波那契数列：递归 */
int fib(int n)
{
    // 终止条件：f(1) = 0, f(2) = 1
    if (n == 1 || n == 2)
        return n - 1;
    // 递归调用 f(n) = f(n - 1) + f(n - 2)
    int res = fib(n - 1) + fib(n - 2); // 当n为3的时候，就能触发终止了

    return res;
}

/* 斐波那契数列：尾递归 */
// 下面的实现有问题：尾递归形式应该是递归调用的结果直接返回，而不经过其他计算
// 应该把计算放在函数的参数里，而不是让两个函数的返回值进行计算
int tailFib(int n, int res)
{
    if (n == 1 || n == 2)
        return n - 1;
    return tailFib(n - 1, res) + tailFib(n - 2, res);
}

int tailFibII(int n, int a = 0, int b = 1)
{
    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    else
        return tailFibII(n - 1, b, a + b);
}

/* 使用迭代模拟递归 */
int forLoopRecur(int n)
{
    // 显示栈模拟系统调用栈
    std::stack<int> stack;
    int res = 0;
    // 递：递归调用
    for (int i = n; i > 0; i--)
    {
        stack.push(i);
    }

    // 归：返回结果
    while (!stack.empty())
    {
        res += stack.top();
        std::cout << "stack top(): " << stack.top() << std::endl;
        stack.pop();
    }

    return res;
}

int main()
{
    // int n = 5;
    // int res = recur(5);
    // int resTail = 0;
    // resTail = tailRecur(5, resTail);

    // printf("res = %d\n", res);
    // printf("resTail = %d", resTail);

    int n = 5;
    int res = 0;
    res = forLoopRecur(n);

    printf("res = %d\n", res);

    return 0;
}