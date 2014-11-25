	_str11_37 --> "\n"
	_str11_9 --> "La funcion devuelve: "



# ------------------------------------------------------

#../xpcode/MIPS/correctos/segundaclase.xp

_l1:
INIT:
		ALLC 12
		BFUN
		PARF cuadrado(0)(r->0)(arg->0)(tam=4)(numtp=8)
		CALL _t1 prueba(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t1 4
		BFUN
		PARF cubo(0)(r->0)(arg->0)(tam=4)(numtp=8)
		CALL _t2 prueba(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t2 4
		BFUN
		PARF fib(0)(r->0)(arg->0)(tam=4)(numtp=8)
		CALL _t3 prueba(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t3 4
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 6:1

prueba:
		ALLF 4
		BFUN
		PARM 6 2 0
		CALL _t4 f(0)(r->1)(arg->1)(tam=4)(numtp=8) 1
		EFUN _t4 4
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t4
		WR   _str11_9 9
		WR   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str11_37 9
		RET 

# ------------------------------------------------------

#FUNCTION situado en 15:1

cuadrado:
		ALLF 0
		MULI _t5 i_0(0)(r->0)(arg->1)(tam=4)(numtp=2) i_0(0)(r->0)(arg->1)(tam=4)(numtp=2)
		RET  _t5
		RET  0

# ------------------------------------------------------

#FUNCTION situado en 21:1

cubo:
		ALLF 0
		MULI _t6 j_0(0)(r->0)(arg->1)(tam=4)(numtp=2) j_0(0)(r->0)(arg->1)(tam=4)(numtp=2)
		MULI _t7 _t6 j_0(0)(r->0)(arg->1)(tam=4)(numtp=2)
		RET  _t7
		RET  0

# ------------------------------------------------------

#FUNCTION situado en 27:1

fib:
		ALLF 8

#IF situado en 31:3, termina en la etiqueta _els1

_if1:
		LESS num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 2 _l2

# ------------------------------------------------------
_l3:
		JUMP _els1

# ------------------------------------------------------
_l2:
		RET  1
_els1:
		SUBI _t8 num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1
		BFUN
		PARM _t8 2 0
		CALL _t9 fib(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t9 4
		:=   j_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t9
		SUBI _t10 num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 2
		BFUN
		PARM _t10 2 0
		CALL _t11 fib(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t11 4
		:=   k_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t11
		ADDI _t12 k_4(4)(r->0)(arg->0)(tam=4)(numtp=2) j_0(0)(r->0)(arg->0)(tam=4)(numtp=2)
		RET  _t12
		RET  0

# ------------------------------------------------------

# ------------------------------------------------------
