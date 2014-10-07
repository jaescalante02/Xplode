#../xpcode/unitarios/assign.xp
l1:
INIT:
for1:
		:=   y 0 
		JUMP l3  

l2:
		ADD  t1 y 1
		:=   y t1 
l3:
		LESS y 3 l4

l5:
		LESS 1 2 l4

l4:
		WR   4 2 
		JUMP l2  

end1:
suma:
		ADD  t2 x y
		RET  t2  
resta:
		:=   x 1 
		RET    

