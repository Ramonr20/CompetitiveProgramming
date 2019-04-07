import sys

def partir(stall):
	if (stall % 2 == 0):
		L = int((stall / 2) - 1)
		R = int(stall / 2)
	else:
		L = R = int(stall / 2)
	return L, R

T = int(sys.stdin.readline()) 

stalls = []
case = 1

for i in range(T):
	aux = sys.stdin.readline().split() 
	
	stall = int(aux[0])
	people = int(aux[1])
	
	if (stall == people):
		print("Case #{}: {} {}".format(case, 0, 0))
	else:
		L, R = partir(stall)
		people -= 1
		while (people != 0):
			stalls.append(L)
			stalls.append(R)
			
			choose = max(stalls)
			stalls.remove(choose)
			L, R = partir(choose)
			people -= 1
		print("Case #{}: {} {}".format(case, R, L))
	stalls = []
	case += 1
	
