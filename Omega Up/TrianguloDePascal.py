

dp = [[1],[1,1]]

def pascal():

    dp[0][0] = 1
    
    for i in range(1,40):
        line = [1]
        for j in range(len(dp[i])-1):
            line.extend([ dp[i][j] + dp[i][j + 1] ])

        line += [1]
        dp.append(line)    

pascal()

T = input()

while T > 0:
    ans = 0
    M = input()
    N = input()
    for i in range(M, N+1):
        for j in range(len(dp[i])):
            ans += dp[i][j]
    
    T = T - 1
    
    print ans

# print(dp)