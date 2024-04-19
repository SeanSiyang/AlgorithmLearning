#include <iostream>
#include <vector>

/* 常数阶 */
int constant(int n)
{
    int count = 0;
    int size = 100000;
    for (int i = 0; i < size; i++)
    {
        count++;
    }

    return count;
}

/* 线性阶 */
int linear(int n) // 输入数据大小为 n
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
    }
    return count;
}

/* 线性阶（遍历数组） */
int arrayTraversal(std::vector<int> &nums)
{
    int count = 0;
    for (int num : nums) // 输入数据大小为数组长度
    {
        count++;
    }
    return count;
}

/* 平方阶 */
int quadratic(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count++;
        }
    }
    return count;
}

/* 平方阶（冒泡排序） */
int bubbleSort(std::vector<int> &nums)
{
    int count = 0; // 计数器
    // 外循环：未排序区间为 [0, i]
    for (int i = nums.size() - 1; i > 0; i--)
    {
        // 内循环：将未排序区间 [0, i] 中的最大元素交换至该区间的最右端
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                count += 3;
            }
        }
    }
    return count;
}

/* 指数阶（循环实现）*/
int exponential(int n)
{
    int count = 0, base = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < base; j++)
        {
            count++;
        }
        base *= 2; // 每一层的个数都乘以 2
    }
    return count;
}

/* 指数阶（递归实现） */
int expRecur(int n)
{
    if (n == 1)
        return 1;
    return expRecur(n - 1) + expRecur(n - 1) + 1;
}

/* 对数阶（循环实现）*/
int logarighmic(int n)
{
    int count = 0;
    while (n > 1)
    {
        n = n / 2;
        count++;
    }
    return count;
}

int main()
{
    int count = exponential(8);
    std::cout << count << std::endl;
}
