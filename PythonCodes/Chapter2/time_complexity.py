def constant(n: int) -> int:
    """常数阶"""
    count = 0
    size = 100000
    for _ in range(size):
        count += 1
    
    return count

def linear(n: int) -> int:
    """线性阶"""
    count = 0
    for _ in range(n):
        count += 1
    return count

def quadratic(n: int) -> int:
    """平方阶"""
    count = 0 # 计数器
    for i in range(n):
        for j in range(n):
            count += 1
    return count

def bubble_sort(nums: list[int]) -> int:
    """平方阶（冒泡排序）"""
    count = 0 # 计数器
    for i in range(len(nums) - 1, 0, -1):
        for j in range(i):
            if nums[j] > nums[j + 1]:
                temp: int = nums[j]
                nums[j] = nums[j+1]
                nums[j + 1] = temp
                count += 3
    
    return count
             
def exponential(n: int) -> int:
    """指数阶（循环实现）"""
    count = 0
    base = 1
    for _ in range(n):
        for _ in range(base):
            count += 1
        base *= 2
    
    return count   

def exp_recur(n: int) -> int:
    """指数阶（递归实现）"""
    if n == 1:
        return 1
    return exp_recur(n - 1) + exp_recur(n - 1) + 1

def logarithmic(n: int) -> int:
    """对数阶（循环实现）"""
    count = 0
    while n > 1:
        n = n / 2
        count += 1
    
    return count

"""Driver Code"""
if __name__ == "__main__":
    n = 3
    print("输入数据大小 n = ", n)
    
    count = logarithmic(n)
    print("常数阶的操作数量 = ", count)
    
    