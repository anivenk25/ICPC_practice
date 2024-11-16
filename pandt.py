def min_cost_to_connect_points(test_cases):
    results = []
    for n, x, a in test_cases:
        # Combine x and a for sorting
        points = list(zip(x, a))
        points.sort()  # Sort by position x
        
        # Calculate the total cost
        total_cost = 0
        for i in range(1, n):
            # Cost of connecting points[i-1] and points[i]
            total_cost += min(points[i-1][1], points[i][1]) * (points[i][0] - points[i-1][0])
        
        results.append(total_cost)
    return results

# Input Reading
import sys
input = sys.stdin.read
data = input().split()
t = int(data[0])
index = 1
test_cases = []
for _ in range(t):
    n = int(data[index])
    index += 1
    x = list(map(int, data[index:index+n]))
    index += n
    a = list(map(int, data[index:index+n]))
    index += n
    test_cases.append((n, x, a))

# Solve and Output
results = min_cost_to_connect_points(test_cases)
print("\n".join(map(str, results)))

