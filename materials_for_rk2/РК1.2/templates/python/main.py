import skirl
import math

ar = skirl.readArray("rli76_angles_fine.dmp")
if(ar):
    print("File contains " + str(len(ar)) + " lines, "  + str(len(ar[0])) + " samples each")
else:
    print("Unable to read array")
    exit(0)

Y=[]
G=[]
H=[]

for a in range(1438, 1475):
    for b in range(665, 696):
        re = ar[a][b][0]
        im = ar[a][b][1]
        amp = math.sqrt(re*re + im*im)
        Y.append(amp)

Y.sort()

for a in range (len(Y)-10,len(Y)):
    G.append(Y[a])

for i in range (0,10):
	for a in range(1438, 1475):
		for b in range(665, 696):
			re = ar[a][b][0]
			im = ar[a][b][1]
			amp = math.sqrt(re*re + im*im)
			if (amp == G[i]):
				H.append([a,b])

for i in range (0,10):
	print("Amplituda = " + str(G[9-i]) + " Coordinati = " + str(H[9-i]))