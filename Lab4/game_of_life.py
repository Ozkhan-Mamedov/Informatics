file = "life.txt"
field = []
field2 = []

def numNear (r,c):
	N = 0
	for a in range (r-1, r+2):
		for b in range (c-1, c+2):
			if a == r and b == c:
				continue
			if field[a][b] == '*':
				N += 1
	return N

F = open ("file.txt", "r")
for line in F:
	L = []
	L2 = []
	for a in line:
		if a == '\r' or a == '\n':
			continue
		L.append (a)
		L2.append (a)
	field.append(L)
	field2.append(L2)
F.close()

for a in field:
	s = ""
	for b in a:
		s += b;
	print (s)

for a in range (1, len(field)-1):
	for b in range (1, len(field[a])-1):
		n = numNear (a,b)
		field2[a][b] = str (n)
		#

print ("\n")
for a in field2:
	s = ""
	for b in a:
		s += b;
	print (s)

#for a in range (1, len(field)-1): 16x16
#	for b in range (1, len(field[a])-1):
#		field [a][b] = field2 [a][b]