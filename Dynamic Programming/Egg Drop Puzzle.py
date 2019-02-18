import sys
floors = 51
eggs = 11
dp = [ [0 for x in range(eggs)] for x in range(floors)]
for i in range(1,floors):
    for j in range(1,eggs):
        if j==1: #if there is only one egg
            dp[i][j] = i
            continue
        dp[i][j] = sys.maxsize
        for k in range(1,i+1):
            eggBreak = dp[k-1][j-1]
            eggNotBreak = dp[i-k][j]
            dp[i][j] = min(1+max(eggBreak,eggNotBreak),dp[i][j])

for _ in range(int(input())):
    n,k = map(int,input().split())
    print(dp[k][n])