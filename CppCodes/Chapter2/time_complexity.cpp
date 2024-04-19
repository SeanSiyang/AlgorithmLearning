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

int main()
{
    int count = constant(10);
    std::cout << count << std::endl;
}
