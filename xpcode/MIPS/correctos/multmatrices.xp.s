.data
_str10_7:  .asciiz "Escriba la dimension de una matriz cuadrada\n"
_str14_7:  .asciiz "Escriba la primera matriz\n"
_str25_7:  .asciiz "Escriba la segunda matriz\n"
_str53_7:  .asciiz "Matriz resultante:\n"
_str60_22:  .asciiz " "
_str63_9:  .asciiz "\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -30020
		la $4 _str10_7
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
		la $4 _str14_7
		li $2 4
		syscall
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

		li $2 5
		syscall
		move $12 $2
		li $13 50
		mul $14 $8 $13
		add $15 $14 $10
		li $16 4
		mul $17 $15 $16
		addi $17 $17 0
		add $17 $17 $29
		sw $12 4($17)
		li $18 1
		add $19 $10 $18
		move $10 $19
		blt $10 $6 _l4
_l6:

		b _end2
_end2:

		li $20 1
		add $21 $8 $20
		move $8 $21
		blt $8 $6 _l2
_l7:

		b _end1
_end1:

		li $22 0
		move $8 $22
		li $23 0
		move $10 $23
		la $4 _str25_7
		li $2 4
		syscall
_whl3:

		blt $8 $6 _l8
_l9:

		b _end3
_l8:

		li $24 0
		move $10 $24
_whl4:

		blt $10 $6 _l10
_l11:

		b _end4
_l10:

		li $2 5
		syscall
		move $25 $2
		li $5 50
		mul $7 $8 $5
		add $9 $7 $10
		li $11 4
		mul $13 $9 $11
		addi $13 $13 10000
		add $13 $13 $29
		sw $25 4($13)
		li $14 1
		add $15 $10 $14
		move $10 $15
		blt $10 $6 _l10
_l12:

		b _end4
_end4:

		li $16 1
		add $12 $8 $16
		move $8 $12
		blt $8 $6 _l8
_l13:

		b _end3
_end3:

		li $17 0
		move $8 $17
		li $18 0
		move $10 $18
		li $19 0
		move $20 $19
_whl5:

		blt $8 $6 _l14
_l15:

		b _end5
_l14:

		li $21 0
		move $10 $21
_whl6:

		blt $10 $6 _l16
_l17:

		b _end6
_l16:

		li $22 0
		move $23 $22
		li $24 0
		move $20 $24
_whl7:

		blt $20 $6 _l18
_l19:

		b _end7
_l18:

		li $5 50
		mul $7 $8 $5
		add $9 $7 $20
		li $11 4
		mul $25 $9 $11
		addi $25 $25 0
		add $25 $25 $29
		lw $13 4($25)
		li $14 50
		mul $15 $20 $14
		add $16 $15 $10
		li $12 4
		mul $17 $16 $12
		addi $17 $17 10000
		add $17 $17 $29
		lw $18 4($17)
		mul $19 $13 $18
		add $21 $23 $19
		move $23 $21
		li $22 1
		add $24 $20 $22
		move $20 $24
		blt $20 $6 _l18
_l20:

		b _end7
_end7:

		li $5 50
		mul $7 $8 $5
		add $9 $7 $10
		li $11 4
		mul $25 $9 $11
		addi $25 $25 20000
		add $25 $25 $29
		sw $23 4($25)
		li $14 1
		add $15 $10 $14
		move $10 $15
		blt $10 $6 _l16
_l21:

		b _end6
_end6:

		li $16 1
		add $12 $8 $16
		move $8 $12
		blt $8 $6 _l14
_l22:

		b _end5
_end5:

		la $4 _str53_7
		li $2 4
		syscall
		li $17 0
		move $8 $17
		li $18 0
		move $10 $18
_whl8:

		blt $8 $6 _l23
_l24:

		b _end8
_l23:

		li $13 0
		move $10 $13
_whl9:

		blt $10 $6 _l25
_l26:

		b _end9
_l25:

		li $19 50
		mul $21 $8 $19
		add $22 $21 $10
		li $24 4
		mul $5 $22 $24
		addi $5 $5 20000
		add $5 $5 $29
		lw $7 4($5)
		move $4 $7
		li $2 1
		syscall
		la $4 _str60_22
		li $2 4
		syscall
		li $9 1
		add $11 $10 $9
		move $10 $11
		blt $10 $6 _l25
_l27:

		b _end9
_end9:

		la $4 _str63_9
		li $2 4
		syscall
		li $25 1
		add $14 $8 $25
		move $8 $14
		blt $8 $6 _l23
_l28:

		b _end8
_end8:

		li $2 10
		syscall
