	_str17_10 --> "\n"
	_str21_10 --> "\n"
	_str24_10 --> "\n"
	_str33_10 --> "\n"
	_str37_10 --> "\n"
	_str5_10 --> "\n"
	_str9_10 --> "\n"



# ------------------------------------------------------

#../xpcode/MIPS/correctos/referencia.xp

_l1:
INIT:
		ALLC 4
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 3
		WR   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str33_10 9
		BFUN
		PARF i_0(0)(r->0)(arg->0)(tam=4)(numtp=2)
		CALL _t1 prueba(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t1 4
		WR   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str37_10 9
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 3:1

prueba2:
		ALLF 0
		WR   a_0(0)(r->1)(arg->1)(tam=4)(numtp=2) 2
		WR   _str5_10 9
		:=   a_0(0)(r->1)(arg->1)(tam=4)(numtp=2) 7
		WR   a_0(0)(r->1)(arg->1)(tam=4)(numtp=2) 2
		WR   _str9_10 9
		RET 

# ------------------------------------------------------

#FUNCTION situado en 15:1

prueba:
		ALLF 0
		WR   b_0(0)(r->1)(arg->1)(tam=4)(numtp=2) 2
		WR   _str17_10 9
		:=   b_0(0)(r->1)(arg->1)(tam=4)(numtp=2) 5
		WR   b_0(0)(r->1)(arg->1)(tam=4)(numtp=2) 2
		WR   _str21_10 9
		BFUN
		PARF b_0(0)(r->1)(arg->1)(tam=4)(numtp=2)
		CALL _t2 prueba2(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t2 4
		WR   b_0(0)(r->1)(arg->1)(tam=4)(numtp=2) 2
		WR   _str24_10 9
		RET 

# ------------------------------------------------------

# ------------------------------------------------------
