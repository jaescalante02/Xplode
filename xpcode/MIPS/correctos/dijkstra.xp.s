.data
_str12_7:  .asciiz "Introduzca el numero de nodos:\n"
_str29_7:  .asciiz "Introduzca el nodo fuente (0-indexed):\n"
_str32_7:  .asciiz "Introduzca el nodo destino (0-indexed):\n"
_str35_7:  .asciiz "Introduzca el numero de arcos:\n"
_str38_7:  .asciiz "Ahora debe introducir los arcos\n"
_str40_9:  .asciiz "Introduzca el fuente de un arco (0-indexed)\n"
_str42_9:  .asciiz "Introduzca el destino del arco (0-indexed)\n"
_str44_9:  .asciiz "Introduzca el costo del arco\n"
_str87_44:  .asciiz "\n"
_str87_7:  .asciiz "Camino de menor costo: "

.text

main:
_l1:

INIT:

		addi $29 $29 -10452
		la $4 _str12_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $5 $2
		move $6 $5
		li $7 0
		move $8 $7
		li $9 0
		move $10 $9
_whl1:

		blt $8 $6 _l2
_l3:

		b _end1
_l2:

		li $11 0
		move $10 $11
_whl2:

		blt $10 $6 _l4
_l5:

		b _end2
_l4:

		li $12 50
		mul $13 $8 $12
		add $14 $13 $10
		li $15 4
		mul $16 $14 $15
		li $17 10000000
		addi $16 $16 44
		add $16 $16 $29
		sw $17 4($16)
		li $18 1
		add $19 $10 $18
		move $10 $19
		blt $10 $6 _l4
_l6:

		b _end2
_end2:

		li $20 4
		mul $21 $8 $20
		li $22 10000000
		addi $21 $21 10044
		add $21 $21 $29
		sw $22 4($21)
		li $23 4
		mul $24 $8 $23
		li $25 0
		addi $24 $24 10244
		add $24 $24 $29
		sw $25 4($24)
		li $5 1
		add $7 $8 $5
		move $8 $7
		blt $8 $6 _l2
_l7:

		b _end1
_end1:

		la $4 _str29_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $9 $2
		move $11 $9
		la $4 _str32_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $12 $2
		move $13 $12
		la $4 _str35_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $14 $2
		move $15 $14
		li $16 0
		move $8 $16
		la $4 _str38_7
		li $2 4
		syscall
_whl3:

		blt $8 $15 _l8
_l9:

		b _end3
_l8:

		la $4 _str40_9
		li $2 4
		syscall
		li $2 5
		syscall
		move $17 $2
		move $18 $17
		la $4 _str42_9
		li $2 4
		syscall
		li $2 5
		syscall
		move $19 $2
		move $20 $19
		la $4 _str44_9
		li $2 4
		syscall
		li $2 5
		syscall
		move $21 $2
		move $22 $21
		li $23 50
		mul $24 $18 $23
		add $25 $24 $20
		li $5 4
		mul $7 $25 $5
		addi $7 $7 44
		add $7 $7 $29
		sw $22 4($7)
		li $9 1
		add $12 $8 $9
		move $8 $12
		blt $8 $15 _l8
_l10:

		b _end3
_end3:

		li $14 4
		mul $16 $11 $14
		li $17 0
		addi $16 $16 10044
		add $16 $16 $29
		sw $17 4($16)
		li $19 0
		move $8 $19
_whl4:

		blt $8 $6 _l11
_l12:

		b _end4
_l11:

		li $21 1
		neg $23 $21
		move $24 $23
		li $25 0
		move $5 $25
_whl5:

		blt $5 $6 _l13
_l14:

		b _end5
_l13:

_if1:

		li $7 4
		mul $9 $5 $7
		addi $9 $9 10244
		add $9 $9 $29
		lw $12 4($9)
		li $14 0
		beq $12 $14 _l15
_l16:

		b _els1
_l15:

_if2:

		li $16 1
		neg $17 $16
		beq $24 $17 _l17
_l18:

		b _els2
_l17:

		move $24 $5
		b _end6
_els2:

_if3:

		li $19 4
		mul $21 $5 $19
		addi $21 $21 10044
		add $21 $21 $29
		lw $23 4($21)
		li $25 4
		mul $7 $24 $25
		addi $7 $7 10044
		add $7 $7 $29
		lw $9 4($7)
		blt $23 $9 _l19
_l20:

		b _els3
_l19:

		move $24 $5
_els3:

_end6:

_els1:

		li $12 1
		add $14 $5 $12
		move $5 $14
		blt $5 $6 _l13
_l21:

		b _end5
_end5:

_if4:

		li $16 1
		neg $17 $16
		beq $24 $17 _l22
_l23:

		b _els4
_l22:

		b _end4
_l24:

_els4:

		li $19 0
		move $5 $19
		li $21 4
		mul $25 $24 $21
		li $7 1
		addi $25 $25 10244
		add $25 $25 $29
		sw $7 4($25)
_whl6:

		blt $5 $6 _l25
_l26:

		b _end7
_l25:

_if5:

		li $9 4
		mul $23 $5 $9
		addi $23 $23 10244
		add $23 $23 $29
		lw $12 4($23)
		li $14 0
		beq $12 $14 _l28
_l29:

		b _els5
_l28:

		li $16 4
		mul $17 $24 $16
		addi $17 $17 10044
		add $17 $17 $29
		lw $19 4($17)
		li $21 50
		mul $25 $24 $21
		add $7 $25 $5
		li $9 4
		mul $23 $7 $9
		addi $23 $23 44
		add $23 $23 $29
		lw $12 4($23)
		add $14 $19 $12
		li $16 4
		mul $17 $5 $16
		addi $17 $17 10044
		add $17 $17 $29
		lw $21 4($17)
		blt $14 $21 _l27
_l30:

		b _els5
_l27:

		li $25 4
		mul $7 $24 $25
		addi $7 $7 10044
		add $7 $7 $29
		lw $9 4($7)
		li $23 50
		mul $12 $24 $23
		add $19 $12 $5
		li $16 4
		mul $17 $19 $16
		addi $17 $17 44
		add $17 $17 $29
		lw $21 4($17)
		add $14 $9 $21
		li $25 4
		mul $7 $5 $25
		addi $7 $7 10044
		add $7 $7 $29
		sw $14 4($7)
_els5:

		li $23 1
		add $12 $5 $23
		move $5 $12
		blt $5 $6 _l25
_l31:

		b _end7
_end7:

		li $19 1
		add $16 $8 $19
		move $8 $16
		blt $8 $6 _l11
_l32:

		b _end4
_end4:

		la $4 _str87_7
		li $2 4
		syscall
		li $17 4
		mul $21 $13 $17
		addi $21 $21 10044
		add $21 $21 $29
		lw $9 4($21)
		move $4 $9
		li $2 1
		syscall
		la $4 _str87_44
		li $2 4
		syscall
		li $2 10
		syscall
