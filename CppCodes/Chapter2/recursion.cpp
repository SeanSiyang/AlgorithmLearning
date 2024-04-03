#include <iostream>

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

int main()
{
    int n = 5;
    int res = recur(5);
    int resTail = 0;
    resTail = tailRecur(5, resTail);

    printf("res = %d\n", res);
    printf("resTail = %d", resTail);

    return 0;
}