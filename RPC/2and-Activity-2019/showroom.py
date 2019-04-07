S = str(input())
E = int(input())

words = []
for i in range(E):
    words.append(input().split())

words = [ i for w in words for i in w]

P = int(input())

phrases = []

for i in range(P):
    phrases.append(str(input()))

flag = True

for phr in phrases:
    for wordry in words:
        if wordry in phr:
            print('YES')
            flag = True
            break
        else:
            flag = False
    if not flag:
        print('NO')