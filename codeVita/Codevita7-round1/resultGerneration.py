problemSet = {}
winnerF = {}
winnerP = {}
gamersR = {}

querys = []


def main():
	P = int(input())

	for i in range(P):
		pid, psco, ntc = input().split()

		problemSet[pid] = (int(psco), int(ntc))

	winners, submi = input().split()

	for i in range(int(submi)):
		sub = input().split()
		gamersR[sub[0]] = [0, 0.0]
		winnerP[sub[0]+sub[1]] = 0
		winnerF[sub[0]+sub[1]] = 0
		querys.append(sub)

	for submition in querys:
		uid = submition[0]
		pid = submition[1]
		
		result = submition[3:]

		ca = len([x for x in result if x == 'A'])

		score = (problemSet[pid][0] * ca) / problemSet[pid][1]

		if (ca < problemSet[pid][1]):
			if winnerP[uid+pid] < score:
				winnerP[uid+pid] = score
		else:
			if ((uid+pid) in winnerP):
				winnerP.pop(uid+pid)
			if winnerF[uid+pid] < score:
				winnerF[uid+pid] = score

		
	for idusr, points in winnerF.items():
		gamersR[idusr[0]][0] += points

	for idusr, points in winnerP.items():
		gamersR[idusr[0]][1] += points
	
	gF = {}
	gP = {}

	for uid, points in gamersR.items():
		if points[0] > 0:
			gF[uid] = points
		else:
			gP[uid] = points

	view1  = sorted(gF.items(), key=lambda kv: kv[1][0], reverse=True)
	view2  = sorted(gP.items(), key=lambda kv: kv[1][1], reverse=True)
	
	for  i, idusr in enumerate(view1):
		print("{} {} {} {:.2f}".format(i+1, idusr[0], idusr[1][0], idusr[1][1]))

	j = len(view1) + 1
	for  idusr in view2:
		print("{} {} {} {:.2f}".format(j, idusr[0], idusr[1][0], idusr[1][1]))
		j+=1
	
if __name__ == '__main__':
	main()

