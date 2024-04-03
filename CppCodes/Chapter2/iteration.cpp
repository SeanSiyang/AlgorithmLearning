#include <iostream>

/*for 循环*/
int forLoop(int n)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += i;
    }
    return res;
}

int main()
{
    int res = 0;
    res = forLoop(5);
    printf("%d", res);
    return 0;
}