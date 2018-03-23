
T = int(input())
ans = 0

for i in range(T):
    s = str(input())
    if s == "report":
        print(ans)
    else:
        d, m = s.split(" ")
        ans += int(m)