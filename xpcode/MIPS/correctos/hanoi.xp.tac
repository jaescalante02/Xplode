	_str14_9 --> "Mover plato de "
	_str16_9 --> " a "
	_str18_9 --> "\n"
	_str28_7 --> "Escriba el numero de platos iniciales, que se moveran del plato 1 al 2\n"
	_str8_11 --> "Mover plato de "
	_str8_35 --> " a "
	_str8_47 --> "\n"



# ------------------------------------------------------

#../xpcode/MIPS/correctos/hanoi.xp

_l1:
INIT:
		ALLC 8
		WR   _str28_7 9
		READ _t1 2
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t1
		BFUN
		PARM 3 2 0
		PARM 2 2 4
		PARM 1 2 8
		PARM j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 2 12
		CALL _t2 hanoi(0)(r->0)(arg->0)(tam=0)(numtp=8) 4
		EFUN _t2 16
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 3:1

hanoi:
		ALLF 0

#IF situado en 7:3, termina en la etiqueta _els1

_if1:
		EQ   num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1 _l2

# ------------------------------------------------------
_l3:
		JUMP _els1

# ------------------------------------------------------
_l2:
		WR   _str8_11 9
		WR   from_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 2
		WR   _str8_35 9
		WR   dest_8(8)(r->0)(arg->1)(tam=4)(numtp=2) 2
		WR   _str8_47 9
		RET 
_els1:
		SUBI _t3 num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1
		BFUN
		PARM dest_8(8)(r->0)(arg->1)(tam=4)(numtp=2) 2 0
		PARM by_12(12)(r->0)(arg->1)(tam=4)(numtp=2) 2 4
		PARM from_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 2 8
		PARM _t3 2 12
		CALL _t4 hanoi(0)(r->0)(arg->0)(tam=0)(numtp=8) 4
		EFUN _t4 16
		WR   _str14_9 9
		WR   from_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 2
		WR   _str16_9 9
		WR   dest_8(8)(r->0)(arg->1)(tam=4)(numtp=2) 2
		WR   _str18_9 9
		SUBI _t5 num_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1
		BFUN
		PARM from_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 2 0
		PARM dest_8(8)(r->0)(arg->1)(tam=4)(numtp=2) 2 4
		PARM by_12(12)(r->0)(arg->1)(tam=4)(numtp=2) 2 8
		PARM _t5 2 12
		CALL _t6 hanoi(0)(r->0)(arg->0)(tam=0)(numtp=8) 4
		EFUN _t6 16
		RET 

# ------------------------------------------------------

# ------------------------------------------------------
