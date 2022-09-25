n = int(input())
eleito = True
for i in range(n):
    if i==0:
        bobo = int(input())
    else:
        outro = int(input())
        if outro > bobo:
            eleito = False
if(eleito):
    print("S")
else:
    print("N")
