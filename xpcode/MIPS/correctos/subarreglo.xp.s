.data
_str11_7:  .asciiz "Escriba el tamano de la cadena\n"
_str13_7:  .asciiz "Escriba el tamano del posible substring\n"
_str16_7:  .asciiz "Escriba la primera cadena que desea saber si esta contenida en la segunda\n"
_str26_7:  .asciiz "Escriba la segunda cadena\n"
_str70_9:  .asciiz "\nSi esta contenida\n"
_str73_9:  .asciiz "\nNo esta contenida\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -2436
		la $4 _str11_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $5 $2
		move $6 $5
		la $4 _str13_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $7 $2
		move $8 $7
		la $4 _str16_7
		li $2 4
		syscall
		li $9 0
		move $10 $9
		li $11 0
		move $12 $11
_whl1:

		blt $10 $6 _l2
_l3:

		b _end1
_l2:

		li $2 12
		syscall
		move $13 $2
		li $14 4
		mul $15 $10 $14
		addi $15 $15 0
		add $15 $15 $29
		sw $13 4($15)
		li $16 1
		add $17 $10 $16
		move $10 $17
		blt $10 $6 _l2
_l4:

		b _end1
_end1:

		li $2 12
		syscall
		move $18 $2
		move $19 $18
		la $4 _str26_7
		li $2 4
		syscall
		move $21 $20
_whl2:

		blt $12 $8 _l5
_l6:

		b _end2
_l5:

		li $2 12
		syscall
		move $22 $2
		li $23 4
		mul $24 $12 $23
		addi $24 $24 1200
		add $24 $24 $29
		sw $22 4($24)
		li $25 1
		add $5 $12 $25
		move $12 $5
		blt $12 $8 _l5
_l7:

		b _end2
_end2:

		li $2 12
		syscall
		move $7 $2
		move $19 $7
		li $9 0
		move $11 $9
		li $14 0
		move $13 $14
		li $15 0
		move $16 $15
		li $17 0
		move $18 $17
_whl3:

		blt $11 $6 _l9
_l10:

		b _end3
_l9:

		li $23 0
		beq $18 $23 _l8
_l11:

		b _end3
_l8:

_if1:

		li $22 4
		mul $24 $11 $22
		addi $24 $24 0
		add $24 $24 $29
		lw $25 4($24)
		li $5 4
		li $7 0
		mul $9 $7 $5
		addi $9 $9 1200
		add $9 $9 $29
		lw $14 4($9)
		beq $25 $14 _l12
_l13:

		b _els1
_l12:

		move $16 $11
		li $15 0
		move $13 $15
_whl4:

		blt $13 $8 _l14
_l15:

		b _end4
_l14:

_if2:

		li $17 4
		mul $23 $16 $17
		addi $23 $23 0
		add $23 $23 $29
		lw $22 4($23)
		li $24 4
		mul $7 $13 $24
		addi $7 $7 1200
		add $7 $7 $29
		lw $5 4($7)
		bne $22 $5 _l16
_l17:

		b _els2
_l16:

		b _end4
_l18:

_els2:

		li $9 1
		add $14 $13 $9
		move $13 $14
		li $25 1
		add $15 $16 $25
		move $16 $15
		blt $13 $8 _l14
_l19:

		b _end4
_end4:

_if3:

		beq $13 $8 _l20
_l21:

		b _els3
_l20:

		li $17 1
		move $18 $17
_els3:

_els1:

		li $23 1
		add $24 $11 $23
		move $11 $24
		blt $11 $6 _l22
_l23:

		b _end3
_l22:

		li $7 0
		beq $18 $7 _l8
_l24:

		b _end3
_end3:

_if4:

		li $5 1
		beq $18 $5 _l25
_l26:

		b _els4
_l25:

		la $4 _str70_9
		li $2 4
		syscall
		b _end5
_els4:

		la $4 _str73_9
		li $2 4
		syscall
_end5:

		li $2 10
		syscall
