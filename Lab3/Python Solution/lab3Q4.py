def max_profit(C, weights, profits):
    dp = [0] * (C + 1)

    for c in range(1, C+1):
        for i in range(len(weights)):
            if weights[i] <= c:
                dp[c] = max(dp[c], dp[c - weights[i]] + profits[i])
    return dp[C]

# First test case
weights1 = [4, 6, 8]
profits1 = [7, 6, 9]
C = 14
print("P(14) for first set:", max_profit(C, weights1, profits1))

# Second test case
weights2 = [5, 6, 8]
profits2 = [7, 6, 9]
print("P(14) for second set:", max_profit(C, weights2, profits2))