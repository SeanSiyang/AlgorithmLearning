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

"""Driver Code"""
if __name__ == "__main__":
    n = 8
    print("输入数据大小 n = ", n)
    
    count = linear(n)
    print("常数阶的操作数量 = ", count)
    
    