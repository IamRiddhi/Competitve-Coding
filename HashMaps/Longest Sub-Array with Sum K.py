def maxLen(n, a, k):
    dict = {}
    pre = []
    prev = 0
    dict[0] = -1
    maxLength = 0
    for i in range(n):
      x = prev + a[i]
      if x-k in dict:
          maxLength = max(i-dict[x-k],maxLength)
      if x not in dict:
          dict[x] = i
      prev = x
    return maxLength
    
for T in range(int(input())):
    (n,k) = map(int,input().split())
    a = list(map(int,input().split()))
    print(maxLen(n,a,k))