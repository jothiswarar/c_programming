def prime(a):
    if n<=1:
        return False
    for i in range(a-1,1,-1):
        if a%i==0:
            return False
    return True
n=int(input("Enter n:"))
a=list()
j=2
while(len(a)<n):
    if prime(j):
        a.append(j)
    j+=1
print(a)
