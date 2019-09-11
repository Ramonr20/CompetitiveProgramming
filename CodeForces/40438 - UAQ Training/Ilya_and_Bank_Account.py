from sys import stdin

def readInt():
    return int(stdin.readline())

N = readInt()

if N < 0:
    a = int(str(N)[:-1])
    b = int(str(N)[:-2] + str(N)[-1:])
    print(a if a > b else b)
else:
    print(N)
    