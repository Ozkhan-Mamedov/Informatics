from math import *
import matplotlib.pyplot as pp 

x = []
y = []
for a in range (0, 1000) :
	if 400<a<600 :
		x.append(1)
	else :
		x.append(0)
coeff = (0, 0, 0, 0, 0, 0, 0, 0, 0, 1)
def integr () :
	t=5
	h=[]
	for j in range (len(x)) :
		h.append ((1/t)*(1-exp(-j/t)))
		for i in range (0, len(coeff)) :
			y.append( h[i] * x [j-i] )
	h.insert(0, coeff)
	return y;
integr (x);
pp.plot(x)
pp.plot(y)
pp.show()