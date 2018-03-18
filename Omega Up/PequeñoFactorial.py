
def factorial(f):
    x = 1
    if(f > 0):
        x = factorial(f-1)
        x = x * f

    return x 

D = int(input())
v = [int(input()) for i in range(D)]


for i in v:
    answ = factorial(i)
    print(answ)

