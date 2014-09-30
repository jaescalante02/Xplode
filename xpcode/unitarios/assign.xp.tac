#../xpcode/unitarios/assign.xp
l1:
INIT:
l2:
		EQ   t1 1 1
		EQZ  t1 l4 

l3:
l5:
		GRET t2 6 8
		NEQZ t2 l6 

l8:
l9:
		NEQ  t3 1 0
		EQZ  t3 l11 

l10:
l12:
		LEQ  t4 8 4
		NEQZ t4 l13 

l15:
		JUMP l11  

l16:
		JUMP l9  

l17:
l18:
		LESS t5 2 0
		NEQZ t5 l19 

l21:
		JUMP l11  

l22:
l19:
l13:
		NEQ  t6 1 0
		NEQZ t6 l10 

l11:
		JUMP l2  

l23:
		JUMP l4  

l24:
l6:
		EQ   t7 1 1
		NEQZ t7 l3 

l4:

