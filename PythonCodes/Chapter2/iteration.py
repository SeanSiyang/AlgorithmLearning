def for_loop(n: int) -> int:
    """for 循环"""
    res = 0
    # range(a, b) ==> a, a+1, ..., b-1
    for i in range(1, n + 1):
        res += i
    return res

if __name__ == "__main__":
    n = 5
    res = for_loop(n)
    print(f"\nfor 循环的求和结果 res = {res}")