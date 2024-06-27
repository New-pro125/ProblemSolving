mod = 1000000007
n, k = map(int, input().split())
arr = list(map(int, input().split()))

dp = [0] * (k + 1)
dp[0] = 1

for idx in range(n - 1, -1, -1):
    sums = [0] * (k + 5)
    sums[0] = dp[0]

    for i in range(1, k + 1):
        sums[i] = (sums[i - 1] + dp[i]) % mod

    new_dp = [0] * (k + 1)

    for remain in range(0, k + 1):
        l = max(0, remain - arr[idx])
        r = remain

        if l > 0:
            new_dp[remain] = (new_dp[remain] + sums[r] - sums[l - 1] + mod) % mod
        else:
            new_dp[remain] = (new_dp[remain] + sums[r] + mod) % mod

    dp = new_dp

print(dp[k])
