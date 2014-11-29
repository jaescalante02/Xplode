	_str12_7 --> "Introduzca el numero de nodos:\n"
	_str29_7 --> "Introduzca el nodo fuente (0-indexed):\n"
	_str32_7 --> "Introduzca el nodo destino (0-indexed):\n"
	_str35_7 --> "Introduzca el numero de arcos:\n"
	_str38_7 --> "Ahora debe introducir los arcos\n"
	_str40_9 --> "Introduzca el fuente de un arco (0-indexed)\n"
	_str42_9 --> "Introduzca el destino del arco (0-indexed)\n"
	_str44_9 --> "Introduzca el costo del arco\n"
	_str87_44 --> "\n"
	_str87_7 --> "Camino de menor costo: "



# ------------------------------------------------------

#../xpcode/MIPS/correctos/dijkstra.xp

_l1:
INIT:
		ALLC 10452
		WR   _str12_7 9
		READ _t1 2
		:=   nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _t1
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 0
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 0

#WHILE situado en 17:1, termina en la etiqueta _end1

_whl1:
		LESS i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _l2

# ------------------------------------------------------
_l3:
		JUMP _end1

# ------------------------------------------------------
_l2:
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 0

#WHILE situado en 19:3, termina en la etiqueta _end2

_whl2:
		LESS j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _l4

# ------------------------------------------------------
_l5:
		JUMP _end2

# ------------------------------------------------------
_l4:
		MULI _t2 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 50
		ADDI _t3 _t2 j_4(4)(r->0)(arg->0)(tam=4)(numtp=2)
		MULI _t4 _t3 4
		[]:= ady_44(44)(r->0)(arg->0)(tam=4)(numtp=2) _t4 10000000
		ADDI _t5 j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) _t5
		LESS j_4(4)(r->0)(arg->0)(tam=4)(numtp=2) nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _l4

# ------------------------------------------------------
_l6:
		JUMP _end2

# ------------------------------------------------------
_end2:
		MULI _t6 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= costo_10044(10044)(r->0)(arg->0)(tam=4)(numtp=2) _t6 10000000
		MULI _t7 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= pick_10244(10244)(r->0)(arg->0)(tam=4)(numtp=2) _t7 0
		ADDI _t8 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t8
		LESS i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _l2

# ------------------------------------------------------
_l7:
		JUMP _end1

# ------------------------------------------------------
_end1:
		WR   _str29_7 9
		READ _t9 2
		:=   src_20(20)(r->0)(arg->0)(tam=4)(numtp=2) _t9
		WR   _str32_7 9
		READ _t10 2
		:=   dst_24(24)(r->0)(arg->0)(tam=4)(numtp=2) _t10
		WR   _str35_7 9
		READ _t11 2
		:=   arcs_28(28)(r->0)(arg->0)(tam=4)(numtp=2) _t11
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 0
		WR   _str38_7 9

#WHILE situado en 39:1, termina en la etiqueta _end3

_whl3:
		LESS i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) arcs_28(28)(r->0)(arg->0)(tam=4)(numtp=2) _l8

# ------------------------------------------------------
_l9:
		JUMP _end3

# ------------------------------------------------------
_l8:
		WR   _str40_9 9
		READ _t12 2
		:=   x_32(32)(r->0)(arg->0)(tam=4)(numtp=2) _t12
		WR   _str42_9 9
		READ _t13 2
		:=   y_36(36)(r->0)(arg->0)(tam=4)(numtp=2) _t13
		WR   _str44_9 9
		READ _t14 2
		:=   cost_40(40)(r->0)(arg->0)(tam=4)(numtp=2) _t14
		MULI _t15 x_32(32)(r->0)(arg->0)(tam=4)(numtp=2) 50
		ADDI _t16 _t15 y_36(36)(r->0)(arg->0)(tam=4)(numtp=2)
		MULI _t17 _t16 4
		[]:= ady_44(44)(r->0)(arg->0)(tam=4)(numtp=2) _t17 cost_40(40)(r->0)(arg->0)(tam=4)(numtp=2)
		ADDI _t18 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t18
		LESS i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) arcs_28(28)(r->0)(arg->0)(tam=4)(numtp=2) _l8

# ------------------------------------------------------
_l10:
		JUMP _end3

# ------------------------------------------------------
_end3:
		MULI _t19 src_20(20)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= costo_10044(10044)(r->0)(arg->0)(tam=4)(numtp=2) _t19 0
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 0

#WHILE situado en 53:1, termina en la etiqueta _end4

_whl4:
		LESS i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _l11

# ------------------------------------------------------
_l12:
		JUMP _end4

# ------------------------------------------------------
_l11:
		NEGI _t20 1
		:=   menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) _t20
		:=   tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) 0

#WHILE situado en 57:3, termina en la etiqueta _end5

_whl5:
		LESS tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _l13

# ------------------------------------------------------
_l14:
		JUMP _end5

# ------------------------------------------------------
_l13:

#IF situado en 58:5, termina en la etiqueta _els1

_if1:
		MULI _t21 tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t22 pick_10244(10244)(r->0)(arg->0)(tam=4)(numtp=2) _t21
		EQ   _t22 0 _l15

# ------------------------------------------------------
_l16:
		JUMP _els1

# ------------------------------------------------------
_l15:

#IF situado en 59:7, termina en la etiqueta _els2

_if2:
		NEGI _t23 1
		EQ   menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) _t23 _l17

# ------------------------------------------------------
_l18:
		JUMP _els2

# ------------------------------------------------------
_l17:
		:=   menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2)
		JUMP _end6

# ------------------------------------------------------

#ELSE situado en 62:11, termina en la etiqueta _end6

_els2:

#IF situado en 63:9, termina en la etiqueta _els3

_if3:
		MULI _t24 tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t25 costo_10044(10044)(r->0)(arg->0)(tam=4)(numtp=2) _t24
		MULI _t26 menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t27 costo_10044(10044)(r->0)(arg->0)(tam=4)(numtp=2) _t26
		LESS _t25 _t27 _l19

# ------------------------------------------------------
_l20:
		JUMP _els3

# ------------------------------------------------------
_l19:
		:=   menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2)
_els3:
_end6:
_els1:
		ADDI _t28 tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) _t28
		LESS tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _l13

# ------------------------------------------------------
_l21:
		JUMP _end5

# ------------------------------------------------------
_end5:

#IF situado en 72:3, termina en la etiqueta _els4

_if4:
		NEGI _t29 1
		EQ   menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) _t29 _l22

# ------------------------------------------------------
_l23:
		JUMP _els4

# ------------------------------------------------------
_l22:
		JUMP _end4

# ------------------------------------------------------
_l24:
_els4:
		:=   tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) 0
		MULI _t30 menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= pick_10244(10244)(r->0)(arg->0)(tam=4)(numtp=2) _t30 1

#WHILE situado en 77:3, termina en la etiqueta _end7

_whl6:
		LESS tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _l25

# ------------------------------------------------------
_l26:
		JUMP _end7

# ------------------------------------------------------
_l25:

#IF situado en 78:5, termina en la etiqueta _els5

_if5:
		MULI _t31 tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t32 pick_10244(10244)(r->0)(arg->0)(tam=4)(numtp=2) _t31
		EQ   _t32 0 _l28

# ------------------------------------------------------
_l29:
		JUMP _els5

# ------------------------------------------------------
_l28:
		MULI _t33 menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t34 costo_10044(10044)(r->0)(arg->0)(tam=4)(numtp=2) _t33
		MULI _t35 menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) 50
		ADDI _t36 _t35 tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2)
		MULI _t37 _t36 4
		:=[] _t38 ady_44(44)(r->0)(arg->0)(tam=4)(numtp=2) _t37
		ADDI _t39 _t34 _t38
		MULI _t40 tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t41 costo_10044(10044)(r->0)(arg->0)(tam=4)(numtp=2) _t40
		LESS _t39 _t41 _l27

# ------------------------------------------------------
_l30:
		JUMP _els5

# ------------------------------------------------------
_l27:
		MULI _t42 menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t43 costo_10044(10044)(r->0)(arg->0)(tam=4)(numtp=2) _t42
		MULI _t44 menor_10444(10444)(r->0)(arg->0)(tam=4)(numtp=2) 50
		ADDI _t45 _t44 tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2)
		MULI _t46 _t45 4
		:=[] _t47 ady_44(44)(r->0)(arg->0)(tam=4)(numtp=2) _t46
		ADDI _t48 _t43 _t47
		MULI _t49 tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= costo_10044(10044)(r->0)(arg->0)(tam=4)(numtp=2) _t49 _t48
_els5:
		ADDI _t50 tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) _t50
		LESS tmp_10448(10448)(r->0)(arg->0)(tam=4)(numtp=2) nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _l25

# ------------------------------------------------------
_l31:
		JUMP _end7

# ------------------------------------------------------
_end7:
		ADDI _t51 i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) _t51
		LESS i_0(0)(r->0)(arg->0)(tam=4)(numtp=2) nodos_12(12)(r->0)(arg->0)(tam=4)(numtp=2) _l11

# ------------------------------------------------------
_l32:
		JUMP _end4

# ------------------------------------------------------
_end4:
		WR   _str87_7 9
		MULI _t52 dst_24(24)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t53 costo_10044(10044)(r->0)(arg->0)(tam=4)(numtp=2) _t52
		WR   _t53 2
		WR   _str87_44 9
		EXIT

# ------------------------------------------------------

# ------------------------------------------------------
