valores = {
    '1':2,
    '2':1,
    '4':0.25,
    '8':0.125,
    '16':0.0625
}

N = int(input())
s = input()

S = s.split(' ')

ans = 0
for i in S:
    ans += valores[i]

print(ans)
    