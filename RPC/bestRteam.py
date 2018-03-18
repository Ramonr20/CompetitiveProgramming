
runners = {}
winners = [0, 0, 0, 0]


n = int(input())

for i in range(n):
    aux = str(raw_input())
    name, s, e = aux.split(" ")
    t = [s,e]
    runners[name] = t


timesS = list(runners.items())

timesS.sort(key=lambda x: x[1][0])

time = 999999999

for i  in range(n):
    timesE = timesS[:i] + timesS[i+1:]
    timesE.sort(key=lambda x: x[1][1])
    suma = ( float(timesS[i][1][0]) + float(timesE[0][1][1]) + float(timesE[1][1][1]) + float(timesE[2][1][1]) )
    if time > suma:
        time = suma
        winners[0] = timesS[i]
        winners[1] = timesE[0]
        winners[2] = timesE[1]
        winners[3] = timesE[2]

print(time)
for i in range(4):
    print("{} {} {}".format( winners[i][0], winners[i][1][0], winners[i][1][1]) )



