#../xpcode/unitarios/assign.xp
1:
INIT:
		EQ   t1 4 4
		PARM 5  
		PARM 4  
		ASN  t2 k 
		ASN  t3 k 
		SUB  t4 t2 t3
		PARM t4  
		ASN  t5 k 
		ASN  t6 k 
		ADD  t7 t5 t6
		PARM t7  
		CALL t8 suma 4
		ADD  t9 t8 13
		ASN  t10 y 
		ASN  t10 t9 

