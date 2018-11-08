a = list(map(int,input().split()))
n = a[0]
dict = {}
for i in range(1,n+1):
  if a[i] not in dict:
  	dict[a[i]] = 1
  else:
    dict[a[i]] += 1
  if -a[i] in dict:
    for j in range(dict[-a[i]]):
    	print(min(a[i],-a[i]),max(a[i],-a[i]),sep=" ")
    