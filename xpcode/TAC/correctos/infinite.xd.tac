	_str22_11 --> "Lei un numero"
	_str6_9 --> "Aca saco el promedio con la magia de next, length y la desconocida"



# ------------------------------------------------------
#../xpcode/TAC/correctos/infinite.xd
_l1:
INIT:
#WHILE situado en 18:3, termina en la etiqueta _end1
_whl1:
		JUMP _l2

# ------------------------------------------------------
_l2:
		READ _t1 2
		MULI _t2 i(20) 4
		[]:= a(0) _t2 _t1
		WR   _str22_11 9
#IF situado en 23:5, termina en la etiqueta _els1
_if1:
		MULI _t3 i(20) 4
		:=[] _t4 a(0) _t3
		NEGI _t5 1
		EQ   _t4 _t5 _l3

# ------------------------------------------------------
_l4:
		JUMP _els1

# ------------------------------------------------------
_l3:
		JUMP _end1

# ------------------------------------------------------
_l5:
_els1:
		MULI _t6 4 4
		:=[] _t7 a(0) _t6
		PARM _t7
		MULI _t8 3 4
		:=[] _t9 a(0) _t8
		PARM _t9
		MULI _t10 2 4
		:=[] _t11 a(0) _t10
		PARM _t11
		MULI _t12 1 4
		:=[] _t13 a(0) _t12
		PARM _t13
		MULI _t14 0 4
		:=[] _t15 a(0) _t14
		PARM _t15
		CALL _t16 prom 5
#IF situado en 26:5, termina en la etiqueta _els2
_if2:
		EQ   i(20) 4 _l6

# ------------------------------------------------------
_l7:
		JUMP _els2

# ------------------------------------------------------
_l6:
		:=   i(20) 0
_els2:
		ADDI _t17 i(20) 1
		:=   i(20) _t17
		JUMP _l2

# ------------------------------------------------------
_end1:
		EXIT

# ------------------------------------------------------
#FUNCTION situado en 3:1
prom:
		WR   _str6_9 9
		RET 

# ------------------------------------------------------

# ------------------------------------------------------
