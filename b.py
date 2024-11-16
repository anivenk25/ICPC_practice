import concurrent.futures

MOD = 998244353

def solve_testcase(n):
    result = 0
    
    
    for i in range(1, n + 1):
        binary = bin(i)[2:]  
        for digit in binary:
            
            result = (result * 2 + int(digit)) 
            
    return result

def process_testcase(n):
    return int(bin(solve_testcase(n))[2:]) % MOD


t = int(input())  
numbers = list(map(int, input().split()))  


with concurrent.futures.ProcessPoolExecutor() as executor:
    
    results = executor.map(process_testcase, numbers)


for result in results:
    print(result)
