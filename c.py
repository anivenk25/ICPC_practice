MOD = 998244353

def bin_exp(x, y, m):
    res = 1
    while y:
        if y & 1:
            res = (res * x) % m
        x = (x * x) % m
        y >>= 1
    return res

def solve_queries(y_values, max_y):
    # Precompute `v`
    v = [0] * 31
    v[2] = 4
    for i in range(3, 31):
        v[i] = (v[i - 1] * 2 + bin_exp(2, i, MOD)) % MOD

    # Precompute results for all Y up to max_y
    dp = [0] * (max_y + 1)
    dp[0] = 1  # Base case: 1 way to sum to 0
    
    for i in range(2, 31):
        for curr_sum in range(max_y, v[i] - 1, -1):
            dp[curr_sum] = (dp[curr_sum] + dp[curr_sum - v[i]]) % MOD

    # Answer each query
    results = [dp[y] for y in y_values]
    return results

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    y_values = list(map(int, data[1:t + 1]))
    
    max_y = max(y_values)
    results = solve_queries(y_values, max_y)
    
    # Print results
    sys.stdout.write("\n".join(map(str, results)) + "\n")

if __name__ == "__main__":
    main()

