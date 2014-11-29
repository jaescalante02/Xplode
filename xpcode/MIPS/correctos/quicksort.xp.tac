	_str47_7 --> "Escriba el tamanio del arreglo\n"
	_str52_7 --> "Escriba los elementos del arreglo\n"
	_str59_7 --> "Arreglo ordenado:\n"
	_str61_14 --> " "
	_str67_7 --> "Arreglo ordenado:\n"
	_str69_14 --> " "
	_str72_7 --> "\n"



# ------------------------------------------------------

#../xpcode/MIPS/correctos/quicksort.xp

_l1:
INIT:
		ALLC 408
		WR   _str47_7 9
		READ _t1 2
		:=   tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t1
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 0
		WR   _str52_7 9

#WHILE situado en 53:1, termina en la etiqueta _end1

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
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 0
		WR   _str59_7 9

#WHILE situado en 60:1, termina en la etiqueta _end2

_whl2:
		LESS i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l5

# ------------------------------------------------------
_l6:
		JUMP _end2

# ------------------------------------------------------
_l5:
		MULI _t5 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t6 x_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t5
		WR   _t6 2
		WR   _str61_14 9
		ADDI _t7 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t7
		LESS i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l5

# ------------------------------------------------------
_l7:
		JUMP _end2

# ------------------------------------------------------
_end2:
		SUBI _t8 tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		BFUN
		PARF x_8(8)(r->0)(arg->0)(tam=200)(numtp=6)
		PARM _t8 2 4
		PARM 0 2 8
		CALL _t9 quicksort(0)(r->0)(arg->0)(tam=4)(numtp=8) 3
		EFUN _t9 12
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 0
		WR   _str67_7 9

#WHILE situado en 68:1, termina en la etiqueta _end3

_whl3:
		LESS i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l8

# ------------------------------------------------------
_l9:
		JUMP _end3

# ------------------------------------------------------
_l8:
		MULI _t10 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t11 x_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t10
		WR   _t11 2
		WR   _str69_14 9
		ADDI _t12 i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t12
		LESS i_4(4)(r->0)(arg->0)(tam=4)(numtp=2) tam_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _l8

# ------------------------------------------------------
_l10:
		JUMP _end3

# ------------------------------------------------------
_end3:
		WR   _str72_7 9
		EXIT

# ------------------------------------------------------

#FUNCTION situado en 3:1

quicksort:
		ALLF 16

#IF situado en 6:3, termina en la etiqueta _els1

_if1:
		LEQ  n_4(4)(r->0)(arg->1)(tam=4)(numtp=2) m_0(0)(r->0)(arg->1)(tam=4)(numtp=2) _l11

# ------------------------------------------------------
_l12:
		JUMP _els1

# ------------------------------------------------------
_l11:
		RET 
_els1:
		SUBI _t13 m_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 1
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t13
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) n_4(4)(r->0)(arg->1)(tam=4)(numtp=2)
		MULI _t14 n_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 4
		:=[] _t15 a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t14
		:=   v_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _t15

#WHILE situado en 14:3, termina en la etiqueta _end4

_whl4:
		JUMP _l13

# ------------------------------------------------------
_l13:
		ADDI _t16 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t16

#WHILE situado en 17:5, termina en la etiqueta _end5

_whl5:
		MULI _t17 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t18 a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t17
		LESS _t18 v_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _l14

# ------------------------------------------------------
_l15:
		JUMP _end5

# ------------------------------------------------------
_l14:
		ADDI _t19 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t19
		MULI _t20 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t21 a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t20
		LESS _t21 v_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _l14

# ------------------------------------------------------
_l16:
		JUMP _end5

# ------------------------------------------------------
_end5:
		SUBI _t22 j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t22

#WHILE situado en 22:5, termina en la etiqueta _end6

_whl6:
		MULI _t23 j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t24 a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t23
		GRET _t24 v_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _l17

# ------------------------------------------------------
_l18:
		JUMP _end6

# ------------------------------------------------------
_l17:
		SUBI _t25 j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t25
		MULI _t26 j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t27 a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t26
		GRET _t27 v_8(8)(r->0)(arg->0)(tam=4)(numtp=2) _l17

# ------------------------------------------------------
_l19:
		JUMP _end6

# ------------------------------------------------------
_end6:

#IF situado en 25:5, termina en la etiqueta _els2

_if2:
		GEQ  i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _l20

# ------------------------------------------------------
_l21:
		JUMP _els2

# ------------------------------------------------------
_l20:
		JUMP _end4

# ------------------------------------------------------
_l22:
_els2:
		MULI _t28 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t29 a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t28
		:=   x_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _t29
		MULI _t30 j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t31 a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t30
		MULI _t32 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t32 _t31
		MULI _t33 j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t33 x_12(12)(r->0)(arg->0)(tam=4)(numtp=2)
		JUMP _l13

# ------------------------------------------------------
_end4:
		MULI _t34 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t35 a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t34
		:=   x_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _t35
		MULI _t36 n_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 4
		:=[] _t37 a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t36
		MULI _t38 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t38 _t37
		MULI _t39 n_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 4
		[]:= a_8(8)(r->1)(arg->1)(tam=4)(numtp=2) _t39 x_12(12)(r->0)(arg->0)(tam=4)(numtp=2)
		BFUN
		PARF a_8(8)(r->1)(arg->1)(tam=4)(numtp=6)
		PARM j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 2 4
		PARM m_0(0)(r->0)(arg->1)(tam=4)(numtp=2) 2 8
		CALL _t40 quicksort(0)(r->0)(arg->0)(tam=4)(numtp=8) 3
		EFUN _t40 12
		ADDI _t41 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		BFUN
		PARF a_8(8)(r->1)(arg->1)(tam=4)(numtp=6)
		PARM n_4(4)(r->0)(arg->1)(tam=4)(numtp=2) 2 4
		PARM _t41 2 8
		CALL _t42 quicksort(0)(r->0)(arg->0)(tam=4)(numtp=8) 3
		EFUN _t42 12
		RET 

# ------------------------------------------------------

# ------------------------------------------------------
