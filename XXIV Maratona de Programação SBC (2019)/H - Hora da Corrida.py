import math

v,n = input().split(' ')
v,n = int(v), int(n)
tot = v*n

for i in range(10,100,10):
    if i!=90:
        print(math.ceil((tot*i)/100),end=' ')
    else:
        print(math.ceil((tot*i)/100))
