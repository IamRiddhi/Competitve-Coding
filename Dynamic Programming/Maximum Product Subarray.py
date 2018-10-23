for T in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    forward = []
    backward = [0 for x in range(n)]
    forward.append(a[0])
    backward[n-1] = a[n-1]
    for i in range(1,n):
        if forward[i-1]==0:
            forward.append(a[i])
        else:
            forward.append(forward[i-1]*a[i])
    for i in range(n-2,-1,-1):
        if backward[i+1]==0:
            backward[i] = a[i]
        else:
            backward[i] = a[i] * backward[i+1]
    maximum = max(forward[0],backward[n-1])
    for i in range(n-1):
        maximum = max(maximum,forward[i],backward[i+1],forward[i]*backward[i+1])
    print(maximum)