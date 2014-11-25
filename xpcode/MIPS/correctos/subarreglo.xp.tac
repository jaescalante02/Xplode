	_str11_7 --> "Escriba el tamano de la cadena\n"
	_str13_7 --> "Escriba el tamano del posible substring\n"
	_str16_7 --> "Escriba la primera cadena que desea saber si esta contenida en la segunda\n"
	_str26_7 --> "Escriba la segunda cadena\n"
	_str70_9 --> "\nSi esta contenida\n"
	_str73_9 --> "\nNo esta contenida\n"



# ------------------------------------------------------

#../xpcode/MIPS/correctos/subarreglo.xp

_l1:
INIT:
		ALLC 2436
		WR   _str11_7 9
		READ _t1 2
		:=   tamt1_2428(2428)(r->0)(arg->0)(tam=4)(numtp=2) _t1
		WR   _str13_7 9
		READ _t2 2
		:=   tamt2_2432(2432)(r->0)(arg->0)(tam=4)(numtp=2) _t2
		WR   _str16_7 9
		:=   tam1_2420(2420)(r->0)(arg->0)(tam=4)(numtp=2) 0
		:=   tam2_2424(2424)(r->0)(arg->0)(tam=4)(numtp=2) 0

#WHILE situado en 19:1, termina en la etiqueta _end1

_whl1:
		LESS tam1_2420(2420)(r->0)(arg->0)(tam=4)(numtp=2) tamt1_2428(2428)(r->0)(arg->0)(tam=4)(numtp=2) _l2

# ------------------------------------------------------
_l3:
		JUMP _end1

# ------------------------------------------------------
_l2:
		READ _t3 4
		MULI _t4 tam1_2420(2420)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= cad1_0(0)(r->0)(arg->0)(tam=4)(numtp=4) _t4 _t3
		ADDI _t5 tam1_2420(2420)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   tam1_2420(2420)(r->0)(arg->0)(tam=4)(numtp=2) _t5
		LESS tam1_2420(2420)(r->0)(arg->0)(tam=4)(numtp=2) tamt1_2428(2428)(r->0)(arg->0)(tam=4)(numtp=2) _l2

# ------------------------------------------------------
_l4:
		JUMP _end1

# ------------------------------------------------------
_end1:
		READ _t6 4
		:=   aux_2400(2400)(r->0)(arg->0)(tam=4)(numtp=4) _t6
		WR   _str26_7 9
		READ _t7 6
		:=   cad2_1200(1200)(r->0)(arg->0)(tam=1200)(numtp=6) _t7

#WHILE situado en 29:1, termina en la etiqueta _end2

_whl2:
		LESS tam2_2424(2424)(r->0)(arg->0)(tam=4)(numtp=2) tamt2_2432(2432)(r->0)(arg->0)(tam=4)(numtp=2) _l5

# ------------------------------------------------------
_l6:
		JUMP _end2

# ------------------------------------------------------
_l5:
		READ _t8 4
		MULI _t9 tam2_2424(2424)(r->0)(arg->0)(tam=4)(numtp=2) 4
		[]:= cad2_1200(1200)(r->0)(arg->0)(tam=4)(numtp=4) _t9 _t8
		ADDI _t10 tam2_2424(2424)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   tam2_2424(2424)(r->0)(arg->0)(tam=4)(numtp=2) _t10
		LESS tam2_2424(2424)(r->0)(arg->0)(tam=4)(numtp=2) tamt2_2432(2432)(r->0)(arg->0)(tam=4)(numtp=2) _l5

# ------------------------------------------------------
_l7:
		JUMP _end2

# ------------------------------------------------------
_end2:
		READ _t11 4
		:=   aux_2400(2400)(r->0)(arg->0)(tam=4)(numtp=4) _t11
		:=   i_2404(2404)(r->0)(arg->0)(tam=4)(numtp=2) 0
		:=   j_2408(2408)(r->0)(arg->0)(tam=4)(numtp=2) 0
		:=   k_2412(2412)(r->0)(arg->0)(tam=4)(numtp=2) 0
		:=   res_2416(2416)(r->0)(arg->0)(tam=4)(numtp=2) 0

#WHILE situado en 41:1, termina en la etiqueta _end3

_whl3:
		LESS i_2404(2404)(r->0)(arg->0)(tam=4)(numtp=2) tamt1_2428(2428)(r->0)(arg->0)(tam=4)(numtp=2) _l9

# ------------------------------------------------------
_l10:
		JUMP _end3

# ------------------------------------------------------
_l9:
		EQ   res_2416(2416)(r->0)(arg->0)(tam=4)(numtp=2) 0 _l8

# ------------------------------------------------------
_l11:
		JUMP _end3

# ------------------------------------------------------
_l8:

#IF situado en 43:3, termina en la etiqueta _els1

_if1:
		MULI _t12 i_2404(2404)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t13 cad1_0(0)(r->0)(arg->0)(tam=4)(numtp=4) _t12
		MULI _t14 0 4
		:=[] _t15 cad2_1200(1200)(r->0)(arg->0)(tam=4)(numtp=4) _t14
		EQ   _t13 _t15 _l12

# ------------------------------------------------------
_l13:
		JUMP _els1

# ------------------------------------------------------
_l12:
		:=   k_2412(2412)(r->0)(arg->0)(tam=4)(numtp=2) i_2404(2404)(r->0)(arg->0)(tam=4)(numtp=2)
		:=   j_2408(2408)(r->0)(arg->0)(tam=4)(numtp=2) 0

#WHILE situado en 47:5, termina en la etiqueta _end4

_whl4:
		LESS j_2408(2408)(r->0)(arg->0)(tam=4)(numtp=2) tamt2_2432(2432)(r->0)(arg->0)(tam=4)(numtp=2) _l14

# ------------------------------------------------------
_l15:
		JUMP _end4

# ------------------------------------------------------
_l14:

#IF situado en 49:7, termina en la etiqueta _els2

_if2:
		MULI _t16 k_2412(2412)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t17 cad1_0(0)(r->0)(arg->0)(tam=4)(numtp=4) _t16
		MULI _t18 j_2408(2408)(r->0)(arg->0)(tam=4)(numtp=2) 4
		:=[] _t19 cad2_1200(1200)(r->0)(arg->0)(tam=4)(numtp=4) _t18
		NEQ  _t17 _t19 _l16

# ------------------------------------------------------
_l17:
		JUMP _els2

# ------------------------------------------------------
_l16:
		JUMP _end4

# ------------------------------------------------------
_l18:
_els2:
		ADDI _t20 j_2408(2408)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   j_2408(2408)(r->0)(arg->0)(tam=4)(numtp=2) _t20
		ADDI _t21 k_2412(2412)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   k_2412(2412)(r->0)(arg->0)(tam=4)(numtp=2) _t21
		LESS j_2408(2408)(r->0)(arg->0)(tam=4)(numtp=2) tamt2_2432(2432)(r->0)(arg->0)(tam=4)(numtp=2) _l14

# ------------------------------------------------------
_l19:
		JUMP _end4

# ------------------------------------------------------
_end4:

#IF situado en 57:5, termina en la etiqueta _els3

_if3:
		EQ   j_2408(2408)(r->0)(arg->0)(tam=4)(numtp=2) tamt2_2432(2432)(r->0)(arg->0)(tam=4)(numtp=2) _l20

# ------------------------------------------------------
_l21:
		JUMP _els3

# ------------------------------------------------------
_l20:
		:=   res_2416(2416)(r->0)(arg->0)(tam=4)(numtp=2) 1
_els3:
_els1:
		ADDI _t22 i_2404(2404)(r->0)(arg->0)(tam=4)(numtp=2) 1
		:=   i_2404(2404)(r->0)(arg->0)(tam=4)(numtp=2) _t22
		LESS i_2404(2404)(r->0)(arg->0)(tam=4)(numtp=2) tamt1_2428(2428)(r->0)(arg->0)(tam=4)(numtp=2) _l22

# ------------------------------------------------------
_l23:
		JUMP _end3

# ------------------------------------------------------
_l22:
		EQ   res_2416(2416)(r->0)(arg->0)(tam=4)(numtp=2) 0 _l8

# ------------------------------------------------------
_l24:
		JUMP _end3

# ------------------------------------------------------
_end3:

#IF situado en 69:1, termina en la etiqueta _els4

_if4:
		EQ   res_2416(2416)(r->0)(arg->0)(tam=4)(numtp=2) 1 _l25

# ------------------------------------------------------
_l26:
		JUMP _els4

# ------------------------------------------------------
_l25:
		WR   _str70_9 9
		JUMP _end5

# ------------------------------------------------------

#ELSE situado en 72:5, termina en la etiqueta _end5

_els4:
		WR   _str73_9 9
_end5:
		EXIT

# ------------------------------------------------------

# ------------------------------------------------------
