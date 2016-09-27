# http://br.spoj.com/problems/CONSEC12/

input()

lc = None
l = input().split()
m = 0
am = 0

for c in l:
    if c == lc:
        am += 1
    else:
        lc = c
        am = 1
    if am > m:
        m = am

print(m)
