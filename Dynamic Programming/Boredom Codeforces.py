n = int(input())
a = list(map(int,input().split()))
freq = {}
unique = []
for i in range(n):
    x = a[i]
    if x in freq:
        freq[x] += 1
    else:
        freq[x] = 1
        unique.append(x)
n = len(unique)
unique.sort()
dp = [[0 for i in range(2)] for j in range(n)]
dp[0][0] = 0;
dp[0][1] = unique[0] * freq[unique[0]]
for i in range(1,n):
    x = unique[i]
    dp[i][0] = max(dp[i-1][0],dp[i-1][1])
    if x==unique[i-1]+1:
        dp[i][1] = (x*freq[x]) + dp[i-1][0]
    else:
        dp[i][1] = (x*freq[x]) + max(dp[i-1][0],dp[i-1][1])
print(max(dp[n-1][0],dp[n-1][1]))