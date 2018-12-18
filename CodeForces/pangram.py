
n = int(input())
s = input()
ans = "YES"

sn = s.lower()
abc = map(chr,range(97,123))

if n == len(s):
    for i in abc:
        if i not in sn:
            ans = "NO"

print(ans)