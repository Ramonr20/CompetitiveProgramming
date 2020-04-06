import sys

def gauss(n):
	return (n * (n + 1) // 2)

def main():

	N = int(sys.stdin.readline())
	l = 1
	r = 2
	a = 2
	b = N
	
	while l != r:
		m = (a + b) // 2	
		l = gauss(m)
		r = gauss(N) - l
		l -= m
		if l == r: 
			break
		if l < r:
			a = m + 1
		elif l > r:
			b = m - 1
			
	print("{} {}".format(m, N))

if __name__ == '__main__':
	main()
