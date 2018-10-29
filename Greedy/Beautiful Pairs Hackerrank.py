n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
freqb = {}
for i in range(n):
    x = b[i]
    if x not in freqb:
        freqb[x] = 1
    else:
        freqb[x] += 1 
ache = 0
count1 = -1
for i in range(n):
    x = a[i]
    if x in freqb and freqb[x]>0:
        ache += 1
        freqb[x] -= 1
    else:
        count1 = 1 
print(ache+count1)