# Generate all cyclic permutations of a list

def cyclic_permutations(lst):
    yield lst
    for k in range(1, len(lst)):
        p = lst[k:] + lst[:k]
        if p == lst:
            break
        yield p


n, m = map(int,input().split())
s = input()
c = []
cyclic = []
mini = 1000001
count = 0

for p in cyclic_permutations(s):
    cyclic.append(p)

#print(cyclic)
    
for i in range(m):
  c.append(input())
  for j in range(0,len(cyclic)):
    if c[i] in cyclic[j]:
     if len(c[i]) < mini:
       mini = len(c[i])
       #s = c[i]
       count += 1

if count == 0:
  print(0,end='\n')
else:
  print(mini,end='\n')
  #print(s)
