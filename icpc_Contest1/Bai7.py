def max_sum_of_remainders(N):
    return (N * (N - 1)) // 2

N = int(input().strip())
print(max_sum_of_remainders(N))
