#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353

// ... existing code ...

long long solve_testcase(int n) {
    long long result = 0;
    
    // Process each number from 1 to n
    for (int i = 1; i <= n; i++) {
        // For each digit in binary representation of i
        int num = i;
        while (num > 0) {
            // Shift left (multiply by 2) and add the next binary digit
            result = (result * 2 + num % 2) % MOD;
            num /= 2;
        }
    }
    
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    
    // Process each test case
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", solve_testcase(n));
    }
    
    return 0;
}