# http://br.spoj.com/problems/PAR/

c = 1
n = int(input())
while n is not 0:
	print('Teste {}'.format(c))
	p1, p2 = input(), input()
	for x in range(n):
		n1, n2 = map(int, input().split())
		print(p1 if (n1 + n2) % 2 == 0 else p2)
	print()
	n = int(input())
	c += 1
