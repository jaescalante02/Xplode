	_str15_7 --> "Escriba los valores del primer vector:\n"
	_str22_7 --> "Escriba los valores del segundo vector:\n"
	_str36_39 --> "\n"
	_str36_7 --> "El producto punto da: "
	_str9_7 --> "Escriba la dimension del los vectores:\n"



# ------------------------------------------------------

#../xpcode/MIPS/correctos/vectores.xp

_l1:
INIT:
		ALLC 252
		WR   _str9_7 9
		READ _t1 2
		:=   dimension_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t1
		:=   punto_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 0
		:=   i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 0
		WR   _str15_7 9

#WHILE situado en 16:1, termina en la etiqueta _end1

_whl1:
		LESS i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) dimension_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l2

# ------------------------------------------------------
_l3:
		JUMP _end1

# ------------------------------------------------------
_l2:
		READ _t2 2
		MULI _t3 i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= x_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _t3 _t2
		ADDI _t4 i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t4
		LESS i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) dimension_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l2

# ------------------------------------------------------
_l4:
		JUMP _end1

# ------------------------------------------------------
_end1:
		:=   i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 0
		WR   _str22_7 9

#WHILE situado en 23:1, termina en la etiqueta _end2

_whl2:
		LESS i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) dimension_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l5

# ------------------------------------------------------
_l6:
		JUMP _end2

# ------------------------------------------------------
_l5:
		READ _t5 2
		MULI _t6 i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= x2_132(132)(r->0)(arg->0)(tam=4)(numtp=2) _t6 _t5
		ADDI _t7 i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t7
		LESS i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) dimension_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l5

# ------------------------------------------------------
_l7:
		JUMP _end2

# ------------------------------------------------------
_end2:
		:=   i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 0

#WHILE situado en 30:1, termina en la etiqueta _end3

_whl3:
		LESS i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) dimension_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l8

# ------------------------------------------------------
_l9:
		JUMP _end3

# ------------------------------------------------------
_l8:
		MULI _t8 i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t9 x_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _t8
		MULI _t10 i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t11 x2_132(132)(r->0)(arg->0)(tam=4)(numtp=2) _t10
		MULI _t12 _t9 _t11
		ADDI _t13 punto_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t12
		:=   punto_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t13
		ADDI _t14 i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t14
		LESS i_8(8)(r->0)(arg->0)(tam=4)(numtp=2) dimension_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l8

# ------------------------------------------------------
_l10:
		JUMP _end3

# ------------------------------------------------------
_end3:
		WR   _str36_7 9
		WR   punto_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 2
		WR   _str36_39 9
		EXIT

# ------------------------------------------------------

# ------------------------------------------------------
