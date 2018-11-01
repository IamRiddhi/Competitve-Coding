import sys
n,m = map(int,input().split())
mat = []
for i in range(n):
  a = list(map(int,input().split()))
  mat.append(a)
dp = [[0 for i in range(m)]for j in range(n)]
for i in range(n):
  for j in range(m):
    if i==0:
      dp[i][j] = 0
    else:
      dp[i][j] = dp[i-1][j]
      if mat[i][j] < mat[i-1][j]:
      	dp[i][j] = i
minimum = []
for i in range(n):
  minimum.append(min(dp[i]))
  
k = int(input())
for _ in range(k):
  l,r = map(int,input().split())
  l -= 1
  r -= 1
  if l>=minimum[r]:
    print("Yes")
  else:
    print("No")