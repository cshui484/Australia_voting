#! /usr/bin/python

import random
from random import sample

case = 3
c = 5
b = 5
name = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
names = list(name)
blist = [ str(x) for x in range(1, c+1) ]

print case

for tc in range(case):
	print
	print b

	for i in range(c):
		print names[i]

	for i in range(b):
		ballot = sample(blist, c)
		print ' '.join(ballot)
	
