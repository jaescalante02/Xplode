	_str11_7 --> "true\n"
	_str15_7 --> "false\n"



# ------------------------------------------------------

#../xpcode/MIPS/correctos/unitarios.xp

_l1:
INIT:
		ALLC 4

#IF situado en 9:1, termina en la etiqueta _els1

_if1:
		JUMP _els1

# ------------------------------------------------------
_l2:
		WR   _str11_7 9
		JUMP _end1

# ------------------------------------------------------

#ELSE situado en 13:6, termina en la etiqueta _end1

_els1:
		WR   _str15_7 9
_end1:
		EXIT

# ------------------------------------------------------

# ------------------------------------------------------
