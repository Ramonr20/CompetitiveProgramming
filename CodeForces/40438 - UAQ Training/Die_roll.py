from sys import stdin

def readInts():
    return list(map(int, stdin.readline().split()))

def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b, a%b)

y, w = readInts()

maxi = max(y, w) - 1
dom = 6 - maxi
greatest = gcd(dom,6)

print('{}/{}'.format(dom//greatest, 6//greatest))
