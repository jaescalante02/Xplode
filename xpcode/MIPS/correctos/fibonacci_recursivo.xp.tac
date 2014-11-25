	_str25_24 --> "]="
	_str25_38 --> "\n"
	_str25_7 --> "fibonacci["



# ------------------------------------------------------

#../xpcode/MIPS/correctos/fibonacci_recursivo.xp

_l1:
INIT:
		ALLC 8
		READ _t1 2
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t1
		WR   _str25_7 9
		WR   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str25_24 9
		BFUN
		PARM j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 2 0
		CALL _t2 fib(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t2 4
		WR   _t2 2
		WR   _str25_38 9
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 3:1

fib:
		ALLF 8

#IF situado en 7:3, termina en la etiqueta _els1

_if1:
		LESS num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 2 _l2

# ------------------------------------------------------
_l3:
		JUMP _els1

# ------------------------------------------------------
_l2:
		RET  1
_els1:
		SUBI _t3 num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1
		BFUN
		PARM _t3 2 0
		CALL _t4 fib(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t4 4
		:=   j_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t4
		SUBI _t5 num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 2
		BFUN
		PARM _t5 2 0
		CALL _t6 fib(0)(r->0)(arg->0)(tam=4)(numtp=8) 1
		EFUN _t6 4
		:=   k_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t6
		ADDI _t7 k_4(4)(r->0)(arg->0)(tam=4)(numtp=2) j_0(0)(r->0)(arg->0)(tam=4)(numtp=2)
		RET  _t7
		RET  0

# ------------------------------------------------------

# ------------------------------------------------------
