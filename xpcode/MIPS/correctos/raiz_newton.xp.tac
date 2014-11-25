	_str23_25 --> " es: "
	_str23_37 --> "\n\n"
	_str23_7 --> "La raiz de "
	_str8_7 --> "Escriba el valor al que le quiere conocer su raiz\n\n"



# ------------------------------------------------------

#../xpcode/MIPS/correctos/raiz_newton.xp

_l1:
INIT:
		ALLC 16
		WR   _str8_7 9
		READ _t1 5
		:=   y_8(8)(r->0)(arg->0)(tam=4)(numtp=5) _t1
		:=   x_0(0)(r->0)(arg->0)(tam=4)(numtp=5) 1.0
		:=   i_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 1

#WHILE situado en 15:1, termina en la etiqueta _end1

_whl1:
		LEQ  i_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 100 _l2

# ------------------------------------------------------
_l3:
		JUMP _end1

# ------------------------------------------------------
_l2:
		DIVF _t2 y_8(8)(r->0)(arg->0)(tam=4)(numtp=5) x_0(0)(r->0)(arg->0)(tam=4)(numtp=5)
		ADDF _t3 x_0(0)(r->0)(arg->0)(tam=4)(numtp=5) _t2
		MULF _t4 0.5 _t3
		:=   nuevox_4(4)(r->0)(arg->0)(tam=4)(numtp=5) _t4
		:=   x_0(0)(r->0)(arg->0)(tam=4)(numtp=5) nuevox_4(4)(r->0)(arg->0)(tam=4)(numtp=5)
		ADDI _t5 i_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _t5
		LEQ  i_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 100 _l2

# ------------------------------------------------------
_l4:
		JUMP _end1

# ------------------------------------------------------
_end1:
		WR   _str23_7 9
		WR   y_8(8)(r->0)(arg->0)(tam=4)(numtp=5) 5
		WR   _str23_25 9
		WR   x_0(0)(r->0)(arg->0)(tam=4)(numtp=5) 5
		WR   _str23_37 9
		EXIT

# ------------------------------------------------------

# ------------------------------------------------------
