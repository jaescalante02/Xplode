#../xpcode/unitarios/assign.xp
l1:
INIT:
		MUL  t1 3 16
		ADD  t2 t1 2
		:=[] t3 x t2
		:=   y t3 
suma:
		ADD  t4 x y
		RET  t4  
resta:
		:=   x 1 
		RET    

