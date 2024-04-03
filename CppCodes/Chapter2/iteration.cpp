#include <iostream>
#include <sstream>

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

/* while 循环 */
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

int main()
{
    // int res = 0;
    std::string res = "";
    res = nestedForLoopII(5);
    // printf("%s", res);
    printf("%s", res.c_str());
    // std::cout << res;
    return 0;
}