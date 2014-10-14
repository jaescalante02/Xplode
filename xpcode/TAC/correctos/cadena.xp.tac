


# ------------------------------------------------------
#../xpcode/TAC/correctos/cadena.xp
_l1:
INIT:
		PARM porcodigo  
		PARM bases  
		PARM lenguajes  
		CALL _t1 comparar_cadenas 3
		WR   _t1 3 
		PARM porlab  
		PARM diseno  
		PARM lenguajes  
		CALL _t2 comparar_cadenas 3
		WR   _t2 3 
		EXIT   

# ------------------------------------------------------
#FUNCTION situado en 13:1
comparar_cadenas:
		PARM c2  
		PARM c1  
		CALL _t3 f 2
		RET  _t3  
		RET  0  

# ------------------------------------------------------
#FUNCTION situado en 20:1
porcodigo:
		:=[] _t4 c1 0
		:=[] _t5 c2 0
		>    _t6 _t4 _t5
		RET  _t6  
		RET  0  

# ------------------------------------------------------
#FUNCTION situado en 26:1
porlab:
		:=[] _t7 c1 4
		RET  _t7  
		RET  0  

# ------------------------------------------------------

# ------------------------------------------------------
