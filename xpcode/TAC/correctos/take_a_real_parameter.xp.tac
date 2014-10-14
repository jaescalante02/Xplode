


# ------------------------------------------------------
#../xpcode/TAC/correctos/take_a_real_parameter.xp
_l1:
INIT:
		ADDI _t1 5 128
		:=[] _t2 yo _t1
		PARM _t2  
		ADDI _t3 5 0
		:=[] _t4 yo 0
		MULI _t5 _t4 2
		ADDI _t6 _t5 1
		MULI _t7 _t6 32
		ADDI _t8 _t7 _t3
		:=[] _t9 yo _t8
		PARM _t9  
		CALL _t10 wtf_this_parameters 2
		EXIT   

# ------------------------------------------------------
#FUNCTION situado en 3:1
wtf_this_parameters:
		RET    
		RET    

# ------------------------------------------------------

# ------------------------------------------------------
