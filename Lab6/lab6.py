field = []

def findPath (r, c):
    p = []
    if field[r][c] == ' ':
        p.append( [r,c] )
        field[r][c] = '_'
        if c == len(field[0])-1:
        	return p 
    else:
    	return p

    up = findPath(r-1,c)  #алгорит движения по лабиринту
    if len(up)>0:
    	for a in up:
    		p.append(a)
    	return p 

    down = findPath (r+1, c)
    if len(down)>0:
    	for a in down:
    		p.append(a)
    	return p

    left = findPath (r, c-1)
    if len(left)>0:
    	for a in left:
    		p.append(a)
    	return p

    right = findPath (r, c+1)
    if len(right)>0:
    	for a in right:
    		p.append(a)
    	return p

    p = []
    return p

F = open ("C:\Documents and Settings\RL1-61\Рабочий стол\mamedov\Lab6\maze.txt")
for line in F:
    L = []
    for a in line:
        if a=='\r' or a == '\n':
            continue
        L.append (a)
    field.append(L)
F.close ()

for a in field:
    s = ""
    for b in a:
        s += b
    print (s)


field [1][0] = "_" #задаем начальное положение
p = findPath (1,1) 
print (p)

for a in range (len(field)):
	for b in range (len(field[a])):
		field[1][0] = '.'
		if field[a][b] == '-':
			field[a][b] = ' '

for pnew in p:
	field [pnew[0]][pnew[1]] = "."

for a in field:
    s = ""
    for b in a:
        s += b
    print (s)
