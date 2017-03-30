import math

ans = int(input ("Nachalnaya sistema koordinat. \n 1)Pryamougolnaya 2)Cilindricheskaya 3)Sfericheskaya \n"))
x=0.0
y=0.0
z=0.0
r=0.0
fi=0.0
h=0.0
theta=0.0

def pr_to_cil (a, b, c) :
	r = round((a ** 2 + b ** 2) ** 0.5, 2)
	print ('r=', r)
	arctang = b/a
	fi = round(math.atan (arctang), 2)
	print ("fi=", fi)
	h = round(c, 2)
	print ("h=", h)
	return 0;

def pr_to_sf (a, b, c) :
	r = round((a ** 2 + b ** 2 + c ** 2) ** 0.5, 2)
	print ("r=", r)
	fi = round(math.acos (c/((a ** 2 + b ** 2 + c ** 2) ** 0.5)), 2)
	print ("fi=", fi)
	arctang = b / a
	theta = round(math.atan (arctang), 2)
	print ("theta=", theta)
	return 0;

def cil_to_pr (a, b, c) :
	x = round(a * math.cos(b), 2)
	print ("x=", x)
	y = round(a * math.sin(b), 2)
	print ("y=", y)
	z = round(c, 2)
	print ("z=", z)
	return 0;

def cil_to_sf (a, b, c) :
	r = round((a ** 2 + c ** 2) ** 0.5, 2)
	print ("r=", r)
	arctang = a / c
	fi = round(math.atan (arctang), 2)
	print ("fi=", fi)
	theta = round(b, 2)
	print ("theta=", theta)
	return 0;

def sf_to_pr (a, b, c) :
	x = round(a * math.sin (b) * math.cos (c), 2)
	print ("x=", x)
	y = round(a * math.sin (b) * math.sin (c), 2)
	print ("y=", y)
	z = round(a * math.cos (c), 2)
	print ("z=", z)
	return 0;

def sf_to_cil (a, b, c) :
	r = round(a * math.sin (b), 2)
	print ("r=", r)
	fi = round (c, 2)
	print ("fi=", fi)
	h = round(a * math.cos (b), 2)
	print ("h=", h)
	return 0;

if ans == 1 :
	print ("Vi vibrali pryamougolnuyu sistemu koordinat")
	x, y, z = input ("Vvedite koordinati:\n")
	print ("Perevod v cilindricheskuyu sistemu koordinat")
	pr_to_cil (x, y, z)
	print ("Perevod v sfericheskuyu sistemu koordinat")
	pr_to_sf (x, y, z)

if ans == 2 :
	print ("Vi vibrali cilindricheskuyu sistemu koordinat")
	r, fi, h = input ("Vvedite koordinati:\n")
	print ("Perevod v pryamougolnuyu sistemu koordinat")
	cil_to_pr (r, fi, h)
	print ("Perevod v sfericheskuyu sistemu koordinat")
	cil_to_sf (r, fi, h)

if ans ==3 :
	print ("Vi vibrali sfericheskuyu sistemu koordinat")
	r, fi, theta = input ("Vvedite koordinati:\n")
	print ("Perevod v pryamougolnuyu sistemu koordinat")
	sf_to_pr (r, fi, theta)
	print ("Perevod v cilindricheskuyu sistemu koordinat")
	sf_to_cil (r, fi, theta)