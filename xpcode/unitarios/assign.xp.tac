#../xpcode/unitarios/assign.xp
l1:
INIT:
		PARM y  
		CALL t1 resta 1
		EXIT   

# ------------------------------------------------------
#FUNCTION situado en 3:1
suma:
		ADD  t2 x y
		RET  t2  
		RET  0  

# ------------------------------------------------------
#FUNCTION situado en 7:1
resta:
		:=   x 1 
		RET  TRUE  
		RET  0  

# ------------------------------------------------------

# ------------------------------------------------------
