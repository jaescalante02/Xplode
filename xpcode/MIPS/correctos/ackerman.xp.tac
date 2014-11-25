	_str28_7 --> "Escriba el primer argumento:\n"
	_str30_7 --> "Escriba el segundo argumento:\n"
	_str33_19 --> " , "
	_str33_29 --> " )="
	_str33_46 --> "\n"
	_str33_7 --> "ack("



# ------------------------------------------------------

#../xpcode/MIPS/correctos/ackerman.xp

_l1:
INIT:
		ALLC 8
		WR   _str28_7 9
		READ _t1 2
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t1
		WR   _str30_7 9
		READ _t2 2
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t2
		WR   _str33_7 9
		WR   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str33_19 9
		WR   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str33_29 9
		BFUN
		PARM j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 2 0
		PARM i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 2 4
		CALL _t3 ack(0)(r->0)(arg->0)(tam=0)(numtp=8) 2
		EFUN _t3 8
		WR   _t3 2
		WR   _str33_46 9
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 3:1

ack:
		ALLF 4

#IF situado en 6:3, termina en la etiqueta _els1

_if1:
		EQ   m_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 0 _l2

# ------------------------------------------------------
_l3:
		JUMP _els1

# ------------------------------------------------------
_l2:
		ADDI _t4 n_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 1
		RET  _t4
_els1:

#IF situado en 12:3, termina en la etiqueta _els2

_if2:
		EQ   n_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 0 _l4

# ------------------------------------------------------
_l5:
		JUMP _els2

# ------------------------------------------------------
_l4:
		SUBI _t5 m_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1
		BFUN
		PARM 1 2 0
		PARM _t5 2 4
		CALL _t6 ack(0)(r->0)(arg->0)(tam=0)(numtp=8) 2
		EFUN _t6 8
		RET  _t6
_els2:
		SUBI _t7 n_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 1
		BFUN
		PARM _t7 2 0
		PARM m_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 2 4
		CALL _t8 ack(0)(r->0)(arg->0)(tam=0)(numtp=8) 2
		EFUN _t8 8
		:=   r1_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t8
		SUBI _t9 m_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1
		BFUN
		PARM r1_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 2 0
		PARM _t9 2 4
		CALL _t10 ack(0)(r->0)(arg->0)(tam=0)(numtp=8) 2
		EFUN _t10 8
		RET  _t10
		RET  0

# ------------------------------------------------------

# ------------------------------------------------------
