MOD = 998244353

def solve_testcase(n):
    result = 0
    for i in range(1, n + 1):
        # Length of binary representation
        binary_length = i.bit_length()
        # Shift result left and add the current number
        result = (result * (1 << binary_length) + i) % MOD
    return result

if __name__ == "__main__":
    t = int(input())  # Number of test cases
    numbers = list(map(int, input().split()))  # List of n values

    results = [solve_testcase(n) for n in numbers]
    for result in results:
        print(result)
