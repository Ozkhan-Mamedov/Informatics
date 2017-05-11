from random import random, seed
from time import time

seed(time())

def isSorted(mas_arg):
	a = 1
	for i in range (len(mas_arg)-1):
		if mas_arg[i] > mas_arg[i+1]:
			a = 0
	if (a==0):
		return False
	else:
		return True

def printArray (mas_print):
	print (mas_print[:10])

def create (mas_rng):
	for i in range (len(mas_rng)-1):
		mas_rng[i] = random() * N
	return mas_rng

size = 1000
mas = []
for i in range (size):
	value = ( random () ) // 0.001
	mas.append(value)
print (mas[:10])
t1 = time ()
target = []
for j in range (size):
	counter = 0
	for k in range (len(mas)):
		if (mas[counter] > mas[k]):
			counter = k
	target.append(mas[counter])
	del mas[counter]
t2 = time ()
t = t2 - t1
print (t)
printArray (target)
print (isSorted(target))