mod=1000000007
n,k=[int(i) for i in input().split()]
arr=[int(i) for i in input().split()]
dp=[]
for i in range(n+1):
    a=[]
    for j in range(k+1):
        a.append(0)
    dp.append(a)
dp[n][0]=1
for idx in range(n-1,-1,-1):
    sums=[0]*(k+5)
    sums[0]=dp[idx+1][0]
    for i in range(1,k+1):
        sums[i]=(sums[i-1]+dp[idx+1][i])%mod
    for remain in range(0,k+1):
        l=max(0,remain-arr[idx])
        r=remain
        if l>0:
            dp[idx][remain]=(dp[idx][remain]+sums[r]-sums[l-1]+mod)%mod
        else:
            dp[idx][remain]=(dp[idx][remain]+sums[r]+mod)%mod
print(dp[0][k])