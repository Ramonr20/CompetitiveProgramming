from sys import stdin

def readInt():
    return int(stdin.readline())

ans = 0
dlls = [100, 20, 10, 5, 1]

N = readInt()

for dll in dlls:
    if N >= dll:
        ans += (N//dll)
        N -= (N//dll) * dll

print(ans)