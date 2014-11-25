	_str54_7 --> "Escriba el tamanio del arreglo\n"
	_str59_7 --> "Escriba los elementos del arreglo\n"
	_str67_7 --> "El arreglo ordenado es:\n"
	_str72_14 --> " "
	_str75_7 --> "\n"



# ------------------------------------------------------

#../xpcode/MIPS/correctos/mergesort.xp

_l1:
INIT:
		ALLC 408
		WR   _str54_7 9
		READ _t1 2
		:=   tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t1
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 0
		WR   _str59_7 9

#WHILE situado en 60:1, termina en la etiqueta _end1

_whl1:
		LESS i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l2

# ------------------------------------------------------
_l3:
		JUMP _end1

# ------------------------------------------------------
_l2:
		READ _t2 2
		MULI _t3 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= x_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t3 _t2
		ADDI _t4 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t4
		LESS i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l2

# ------------------------------------------------------
_l4:
		JUMP _end1

# ------------------------------------------------------
_end1:
		SUBI _t5 tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		BFUN
		PARM _t5 2 0
		PARM 0 2 4
		PARF res_208(208)(r->0)(arg->0)(tam=200)(numtp=6)
		PARF x_8(8)(r->0)(arg->0)(tam=200)(numtp=6)
		CALL _t6 sort(0)(r->0)(arg->0)(tam=0)(numtp=8) 4
		EFUN _t6 16
		WR   _str67_7 9
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 0

#WHILE situado en 71:1, termina en la etiqueta _end2

_whl2:
		LESS i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l5

# ------------------------------------------------------
_l6:
		JUMP _end2

# ------------------------------------------------------
_l5:
		MULI _t7 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t8 x_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t7
		WR   _t8 2
		WR   _str72_14 9
		ADDI _t9 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t9
		LESS i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l5

# ------------------------------------------------------
_l7:
		JUMP _end2

# ------------------------------------------------------
_end2:
		WR   _str75_7 9
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 3:1

sort:
		ALLF 16

#IF situado en 6:3, termina en la etiqueta _els1

_if1:
		GEQ  x1_-8(-8)(r->0)(arg->1)(tam=4)(numtp=2) x2_-4(-4)(r->0)(arg->1)(tam=4)(numtp=2) _l8

# ------------------------------------------------------
_l9:
		JUMP _els1

# ------------------------------------------------------
_l8:
		RET 
_els1:
		ADDI _t10 x1_-8(-8)(r->0)(arg->1)(tam=4)(numtp=2) x2_-4(-4)(r->0)(arg->1)(tam=4)(numtp=2)
		DIVI _t11 _t10 2
		:=   mid_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t11
		BFUN
		PARM mid_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 2 0
		PARM x1_-8(-8)(r->0)(arg->1)(tam=4)(numtp=2) 2 4
		PARF res(-4)(r->1)(arg->1)(tam=-4)(numtp=6)
		PARF x(0)(r->1)(arg->1)(tam=-4)(numtp=6)
		CALL _t12 sort(0)(r->0)(arg->0)(tam=0)(numtp=8) 4
		EFUN _t12 16
		ADDI _t13 mid_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		BFUN
		PARM x2_-4(-4)(r->0)(arg->1)(tam=4)(numtp=2) 2 0
		PARM _t13 2 4
		PARF res(-4)(r->1)(arg->1)(tam=-4)(numtp=6)
		PARF x(0)(r->1)(arg->1)(tam=-4)(numtp=6)
		CALL _t14 sort(0)(r->0)(arg->0)(tam=0)(numtp=8) 4
		EFUN _t14 16
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) x1_-8(-8)(r->0)(arg->1)(tam=4)(numtp=2)
		ADDI _t15 mid_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t15
		:=   ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) x1_-8(-8)(r->0)(arg->1)(tam=4)(numtp=2)

#WHILE situado en 18:3, termina en la etiqueta _end3

_whl3:
		LEQ  i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) mid_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l11

# ------------------------------------------------------
_l12:
		JUMP _end3

# ------------------------------------------------------
_l11:
		LEQ  j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) x2_-4(-4)(r->0)(arg->1)(tam=4)(numtp=2) _l10

# ------------------------------------------------------
_l13:
		JUMP _end3

# ------------------------------------------------------
_l10:

#IF situado en 19:5, termina en la etiqueta _els2

_if2:
		MULI _t16 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t17 x_0(0)(r->1)(arg->1)(tam=4)(numtp=2) _t16
		MULI _t18 j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t19 x_0(0)(r->1)(arg->1)(tam=4)(numtp=2) _t18
		LESS _t17 _t19 _l14

# ------------------------------------------------------
_l15:
		JUMP _els2

# ------------------------------------------------------
_l14:
		MULI _t20 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t21 x_0(0)(r->1)(arg->1)(tam=4)(numtp=2) _t20
		MULI _t22 ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= res_-4(-4)(r->1)(arg->1)(tam=4)(numtp=2) _t22 _t21
		ADDI _t23 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t23
		JUMP _end4

# ------------------------------------------------------

#ELSE situado en 23:9, termina en la etiqueta _end4

_els2:
		MULI _t24 j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t25 x_0(0)(r->1)(arg->1)(tam=4)(numtp=2) _t24
		MULI _t26 ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= res_-4(-4)(r->1)(arg->1)(tam=4)(numtp=2) _t26 _t25
		ADDI _t27 j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t27
_end4:
		ADDI _t28 ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _t28
		LEQ  i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) mid_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l16

# ------------------------------------------------------
_l17:
		JUMP _end3

# ------------------------------------------------------
_l16:
		LEQ  j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) x2_-4(-4)(r->0)(arg->1)(tam=4)(numtp=2) _l10

# ------------------------------------------------------
_l18:
		JUMP _end3

# ------------------------------------------------------
_end3:

#WHILE situado en 30:3, termina en la etiqueta _end5

_whl4:
		LEQ  i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) mid_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l19

# ------------------------------------------------------
_l20:
		JUMP _end5

# ------------------------------------------------------
_l19:
		MULI _t29 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t30 x_0(0)(r->1)(arg->1)(tam=4)(numtp=2) _t29
		MULI _t31 ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= res_-4(-4)(r->1)(arg->1)(tam=4)(numtp=2) _t31 _t30
		ADDI _t32 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t32
		ADDI _t33 ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _t33
		LEQ  i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) mid_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l19

# ------------------------------------------------------
_l21:
		JUMP _end5

# ------------------------------------------------------
_end5:

#WHILE situado en 35:3, termina en la etiqueta _end6

_whl5:
		LEQ  j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) x2_-4(-4)(r->0)(arg->1)(tam=4)(numtp=2) _l22

# ------------------------------------------------------
_l23:
		JUMP _end6

# ------------------------------------------------------
_l22:
		MULI _t34 j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t35 x_0(0)(r->1)(arg->1)(tam=4)(numtp=2) _t34
		MULI _t36 ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= res_-4(-4)(r->1)(arg->1)(tam=4)(numtp=2) _t36 _t35
		ADDI _t37 j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t37
		ADDI _t38 ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   ind_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _t38
		LEQ  j_8(8)(r->0)(arg->0)(tam=4)(numtp=2) x2_-4(-4)(r->0)(arg->1)(tam=4)(numtp=2) _l22

# ------------------------------------------------------
_l24:
		JUMP _end6

# ------------------------------------------------------
_end6:
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) x1_-8(-8)(r->0)(arg->1)(tam=4)(numtp=2)

#WHILE situado en 42:3, termina en la etiqueta _end7

_whl6:
		LEQ  i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) x2_-4(-4)(r->0)(arg->1)(tam=4)(numtp=2) _l25

# ------------------------------------------------------
_l26:
		JUMP _end7

# ------------------------------------------------------
_l25:
		MULI _t39 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t40 res_-4(-4)(r->1)(arg->1)(tam=4)(numtp=2) _t39
		MULI _t41 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= x_0(0)(r->1)(arg->1)(tam=4)(numtp=2) _t41 _t40
		ADDI _t42 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t42
		LEQ  i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) x2_-4(-4)(r->0)(arg->1)(tam=4)(numtp=2) _l25

# ------------------------------------------------------
_l27:
		JUMP _end7

# ------------------------------------------------------
_end7:
		RET 

# ------------------------------------------------------

# ------------------------------------------------------
