


# ------------------------------------------------------

#../xpcode/MIPS/correctos/unitarios.xp

_l1:
INIT:
		ALLC 80
		MULI _t1 7 4
		[]:= a_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t1 98
		MULI _t2 7 4
		:=[] _t3 a_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t2
		WR   _t3 2
		BFUN
		PARF a_0(0)(r->0)(arg->0)(tam=80)(numtp=6)
		CALL _t4 prueba(0)(r->0)(arg->0)(tam=0)(numtp=8) 1
		EFUN _t4 4
		MULI _t5 7 4
		:=[] _t6 a_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t5
		WR   _t6 2
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 3:1

prueba:
		ALLF 0
		MULI _t7 7 4
		:=[] _t8 b_0(0)(r->1)(arg->1)(tam=4)(numtp=2) _t7
		WR   _t8 2
		RET 

# ------------------------------------------------------

# ------------------------------------------------------
