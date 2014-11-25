	_str58_27 --> "\n"
	_str58_7 --> "menor="
	_str62_27 --> "\n"
	_str62_7 --> "mayor="



# ------------------------------------------------------

#../xpcode/MIPS/correctos/foldr.xp

_l1:
INIT:
		ALLC 128
		:=   j_120(120)(r->0)(arg->0)(tam=4)(numtp=2) 0

#WHILE situado en 49:1, termina en la etiqueta _end1

_whl1:
		LESS j_120(120)(r->0)(arg->0)(tam=4)(numtp=2) 30 _l2

# ------------------------------------------------------
_l3:
		JUMP _end1

# ------------------------------------------------------
_l2:
		READ _t1 2
		MULI _t2 j_120(120)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= a_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t2 _t1
		ADDI _t3 j_120(120)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   j_120(120)(r->0)(arg->0)(tam=4)(numtp=2) _t3
		LESS j_120(120)(r->0)(arg->0)(tam=4)(numtp=2) 30 _l2

# ------------------------------------------------------
_l4:
		JUMP _end1

# ------------------------------------------------------
_end1:
		BFUN
		PARF a_0(0)(r->0)(arg->0)(tam=120)(numtp=6)
		PARF menor(0)(r->0)(arg->0)(tam=4)(numtp=8)
		PARM 30 2 8
		PARM 0 2 12
		CALL _t4 foldr(0)(r->0)(arg->0)(tam=4)(numtp=8) 4
		EFUN _t4 16
		:=   respuesta_124(124)(r->0)(arg->0)(tam=4)(numtp=2) _t4
		WR   _str58_7 9
		WR   respuesta_124(124)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str58_27 9
		BFUN
		PARF a_0(0)(r->0)(arg->0)(tam=120)(numtp=6)
		PARF mayor(0)(r->0)(arg->0)(tam=4)(numtp=8)
		PARM 30 2 8
		PARM 0 2 12
		CALL _t5 foldr(0)(r->0)(arg->0)(tam=4)(numtp=8) 4
		EFUN _t5 16
		:=   respuesta_124(124)(r->0)(arg->0)(tam=4)(numtp=2) _t5
		WR   _str62_7 9
		WR   respuesta_124(124)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str62_27 9
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 5:1

menor:
		ALLF 0

#IF situado en 7:3, termina en la etiqueta _els1

_if1:
		LESS a_0(0)(r->0)(arg->1)(tam=4)(numtp=2) b_4(4)(r->0)(arg->1)(tam=4)(numtp=2) _l5

# ------------------------------------------------------
_l6:
		JUMP _els1

# ------------------------------------------------------
_l5:
		RET  a_0(0)(r->0)(arg->1)(tam=4)(numtp=2)
_els1:
		RET  b_4(4)(r->0)(arg->1)(tam=4)(numtp=2)
		RET  0

# ------------------------------------------------------

#FUNCTION situado en 17:1

mayor:
		ALLF 0

#IF situado en 19:3, termina en la etiqueta _els2

_if2:
		GRET a_0(0)(r->0)(arg->1)(tam=4)(numtp=2) b_4(4)(r->0)(arg->1)(tam=4)(numtp=2) _l7

# ------------------------------------------------------
_l8:
		JUMP _els2

# ------------------------------------------------------
_l7:
		RET  a_0(0)(r->0)(arg->1)(tam=4)(numtp=2)
_els2:
		RET  b_4(4)(r->0)(arg->1)(tam=4)(numtp=2)
		RET  0

# ------------------------------------------------------

#FUNCTION situado en 29:1

foldr:
		ALLF 0

#IF situado en 31:1, termina en la etiqueta _els3

_if3:
		EQ   tam_4(4)(r->0)(arg->1)(tam=4)(numtp=2) index_0(0)(r->0)(arg->1)(tam=4)(numtp=2) _l9

# ------------------------------------------------------
_l10:
		JUMP _els3

# ------------------------------------------------------
_l9:
		SUBI _t6 tam_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 1
		MULI _t7 _t6 4
		:=[] _t8 arr_12(12)(r->1)(arg->1)(tam=4)(numtp=2) _t7
		RET  _t8
_els3:
		ADDI _t9 index_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1
		BFUN
		PARF arr_12(12)(r->1)(arg->1)(tam=-4)(numtp=6)
		PARF f(8)(r->1)(arg->1)(tam=4)(numtp=8)
		PARM tam_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 2 8
		PARM _t9 2 12
		CALL _t10 foldr(0)(r->0)(arg->0)(tam=4)(numtp=8) 4
		EFUN _t10 16
		MULI _t11 index_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 4
		:=[] _t12 arr_12(12)(r->1)(arg->1)(tam=4)(numtp=2) _t11
		BFUN
		PARM _t10 2 0
		PARM _t12 2 4
		CALL _t13 f(8)(r->1)(arg->1)(tam=4)(numtp=8) 2
		EFUN _t13 8
		RET  _t13
		RET  0

# ------------------------------------------------------

# ------------------------------------------------------
