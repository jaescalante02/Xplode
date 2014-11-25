	_str19_19 --> "]="
	_str19_31 --> "\n"
	_str19_7 --> "fact["
	_str8_7 --> "Escriba el numero al cual quiere saber el factorial:\n"



# ------------------------------------------------------

#../xpcode/MIPS/correctos/factorial_iterativo.xp

_l1:
INIT:
		ALLC 12
		WR   _str8_7 9
		READ _t1 2
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t1
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   fact_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 1

#WHILE situado en 13:1, termina en la etiqueta _end1

_whl1:
		LEQ  i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _l2

# ------------------------------------------------------
_l3:
		JUMP _end1

# ------------------------------------------------------
_l2:
		MULI _t2 fact_8(8)(r->0)(arg->0)(tam=4)(numtp=2) i_0(0)(r->0)(arg->0)(tam=4)(numtp=2)
		:=   fact_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t2
		ADDI _t3 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t3
		LEQ  i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _l2

# ------------------------------------------------------
_l4:
		JUMP _end1

# ------------------------------------------------------
_end1:
		WR   _str19_7 9
		WR   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str19_19 9
		WR   fact_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str19_31 9
		EXIT

# ------------------------------------------------------

# ------------------------------------------------------
