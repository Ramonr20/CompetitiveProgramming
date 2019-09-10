from sys import stdin

def readInt():
    return int(stdin.readline())

dlls = [100, 20, 10, 5, 1]
ans = 0

N = readInt()

for dll in dlls:
    if N >= dll:
        ans += (N//dll)
        N -= (N//dll) * dll

print(ans)