def f(x):
    return (3 * x * x + x) // 2
    
def search (x):
    lo, hi = 0, int(1e18)
    
    while lo < hi:
        mid = (lo + hi) // 2
        val = f(mid)
        
        if val <= x:
            lo = mid + 1
            
        else:
            hi = mid
            
    return lo

t = int(input())

for i in range(t):
    c = int(input())
    print(search(c) - 1)