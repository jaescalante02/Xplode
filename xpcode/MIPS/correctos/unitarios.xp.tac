	_str15_22 --> "\n"
	_str15_7 --> "a[4]="
	_str16_24 --> "\n"
	_str16_7 --> "a[11]="
	_str17_22 --> "\n"
	_str17_7 --> "a[4]="
	_str18_16 --> "\n"
	_str18_7 --> "i="



# ------------------------------------------------------

#../xpcode/MIPS/correctos/unitarios.xp

_l1:
INIT:
		ALLC 84
		:=   i_80(80) 0

#WHILE situado en 9:1, termina en la etiqueta _end1

_whl1:
		LESS i_80(80) 20 _l2

# ------------------------------------------------------
_l3:
		JUMP _end1

# ------------------------------------------------------
_l2:
		ADDI _t1 i_80(80) 8
		MULI _t2 i_80(80) 4
		[]:= a_0(0) _t2 _t1
		ADDI _t3 i_80(80) 1
		:=   i_80(80) _t3
		LESS i_80(80) 20 _l2

# ------------------------------------------------------
_l4:
		JUMP _end1

# ------------------------------------------------------
_end1:
		WR   _str15_7 9
		MULI _t4 4 4
		:=[] _t5 a_0(0) _t4
		WR   _t5 2
		WR   _str15_22 9
		WR   _str16_7 9
		MULI _t6 11 4
		:=[] _t7 a_0(0) _t6
		WR   _t7 2
		WR   _str16_24 9
		WR   _str17_7 9
		MULI _t8 4 4
		:=[] _t9 a_0(0) _t8
		WR   _t9 2
		WR   _str17_22 9
		WR   _str18_7 9
		WR   i_80(80) 2
		WR   _str18_16 9
		EXIT

# ------------------------------------------------------

# ------------------------------------------------------
