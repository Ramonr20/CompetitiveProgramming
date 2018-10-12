import sys

def readline():
	return list(map(int, sys.stdin.readline().split()))

def main():
	
	T = int(input())
	for i in range(T):
		L, v, l, r = readline()
		
		vi = L // v
		
		l1 = l // v
		l2 = r // v

		train = l2 - l1
		if l % v == 0:
			train += 1
	
		print((vi - train))

if __name__ == '__main__':
	main()
