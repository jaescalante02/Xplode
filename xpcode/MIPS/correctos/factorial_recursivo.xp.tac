	_str28_7 --> "Escriba el valor al cual quiere saber su factorial:\n"
	_str31_19 --> "]="
	_str31_34 --> "\n"
	_str31_7 --> "fact["



# ------------------------------------------------------

#../xpcode/MIPS/correctos/factorial_recursivo.xp

_l1:
INIT:
		ALLC 8
		WR   _str28_7 9
		READ _t1 2
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t1
		WR   _str31_7 9
		WR   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str31_19 9
		BFUN
		PARM j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 2 0
		CALL _t2 fact(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t2 4
		WR   _t2 2
		WR   _str31_34 9
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 3:1

fact:
		ALLF 4

#IF situado en 6:3, termina en la etiqueta _els1

_if1:
		EQ   num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 0 _l2

# ------------------------------------------------------
_l3:
		JUMP _els1

# ------------------------------------------------------
_l2:
		RET  1
_els1:

#IF situado en 12:3, termina en la etiqueta _els2

_if2:
		EQ   num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1 _l4

# ------------------------------------------------------
_l5:
		JUMP _els2

# ------------------------------------------------------
_l4:
		RET  1
_els2:
		SUBI _t3 num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1
		BFUN
		PARM _t3 2 0
		CALL _t4 fact(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t4 4
		:=   j_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t4
		MULI _t5 num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) j_0(0)(r->0)(arg->0)(tam=4)(numtp=2)
		RET  _t5
		RET  0

# ------------------------------------------------------

# ------------------------------------------------------
