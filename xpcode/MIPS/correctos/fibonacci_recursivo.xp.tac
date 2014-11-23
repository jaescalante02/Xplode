	_str25_24 --> "]="
	_str25_38 --> "\n"
	_str25_7 --> "fibonacci["



# ------------------------------------------------------

#../xpcode/MIPS/correctos/fibonacci_recursivo.xp

_l1:
INIT:
		ALLC 
		READ _t1 
		:=   j_4(4)(r->0)(arg->0)(tam=4) _t1
		WR   _str25_7 
		WR   j_4(4)(r->0)(arg->0)(tam=4) 
		WR   _str25_24 
		PARM j_4(4)(r->0)(arg->0)(tam=4)  
		CALL _t2 fib 
		DLLC _t2 
		WR   _t2 
		WR   _str25_38 
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 3:1

fib:
		ALLF 

#IF situado en 7:3, termina en la etiqueta _els1

_if1:
		LESS num_0(0)(r->0)(arg->1)(tam=4) 2 _l2

# ------------------------------------------------------
_l3:
		JUMP _els1

# ------------------------------------------------------
_l2:
		RET  1
_els1:
		SUBI _t3 num_0(0)(r->0)(arg->1)(tam=4) 1
		PARM _t3  
		CALL _t4 fib 
		DLLC _t4 
		:=   j_0(0)(r->0)(arg->0)(tam=4) _t4
		SUBI _t5 num_0(0)(r->0)(arg->1)(tam=4) 2
		PARM _t5  
		CALL _t6 fib 
		DLLC _t6 
		:=   k_4(4)(r->0)(arg->0)(tam=4) _t6
		ADDI _t7 k_4(4)(r->0)(arg->0)(tam=4) j_0(0)(r->0)(arg->0)(tam=4)
		RET  _t7
		RET  0

# ------------------------------------------------------

# ------------------------------------------------------
