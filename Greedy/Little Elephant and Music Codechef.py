for T in range(int(input())):
    n = int(input())
    a = []
    b = []
    d = {}
    ind = {}
    visited = [True for x in range(n)]
    for i in range(n):
        x,y = map(int,input().split())
        a.append(x)
        b.append(y)
        if x not in d:
            d[x] = []
        d[x].append(y)
        if x not in ind:
            ind[x] = {}
        if y not in ind[x]:
            ind[x][y] = []
        ind[x][y].append(i)
    mins = []
    for keys in d:
        y = min(d[keys])
        mins.append(y)
        visited[ind[keys][y][0]] = False
    mins.sort()
    sweetness = 0
    unique = 0
    for i in range(len(mins)):
        sweetness += (mins[i]*(i+1))
        unique += 1
    for i in range(n):
        if visited[i]:
            sweetness += (b[i]*unique)
    print(sweetness)    
    