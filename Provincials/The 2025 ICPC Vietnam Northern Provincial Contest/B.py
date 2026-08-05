from math import gcd

t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    if(n > k):
        print(0, 1)
        continue
    pos = (k - n + 1) * ((k + 1) ** (n - 1))
    res = k ** n
    if(pos == 0): print(0, 1)
    else:
        now = gcd(pos, res)
        print(pos // now, res // now)
