n = int(input())

for i in range(n):
    s = input()
    vet = list(map(float, input().split()))
    
    if len(vet) == 1:
        ans = vet[0] / 2
        
    elif len(vet) == 2:
        ans = sum(vet) / 2
        
    elif len(vet) == 3:
        ans = sum(vet) / 3
        
    else:
        ans = (sum(vet) - min(vet)) / 3
    
    print(s + ':', '%.1f' % ans)