.data
_str15_7:  .asciiz "Escriba los valores del primer vector:\n"
_str22_7:  .asciiz "Escriba los valores del segundo vector:\n"
_str36_39:  .asciiz "\n"
_str36_7:  .asciiz "El producto punto da: "
_str9_7:  .asciiz "Escriba la dimension del los vectores:\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -252
		la $4 _str9_7
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
		la $4 _str15_7
		li $2 4
		syscall
_whl1:

		blt $10 $6 _l2
_l3:

		b _end1
_l2:

		li $2 5
		syscall
		move $11 $2
		li $12 4
		mul $13 $10 $12
		addi $13 $13 12
		add $13 $13 $29
		sw $11 4($13)
		li $14 1
		add $15 $10 $14
		move $10 $15
		blt $10 $6 _l2
_l4:

		b _end1
_end1:

		li $16 0
		move $10 $16
		la $4 _str22_7
		li $2 4
		syscall
_whl2:

		blt $10 $6 _l5
_l6:

		b _end2
_l5:

		li $2 5
		syscall
		move $17 $2
		li $18 4
		mul $19 $10 $18
		addi $19 $19 132
		add $19 $19 $29
		sw $17 4($19)
		li $20 1
		add $21 $10 $20
		move $10 $21
		blt $10 $6 _l5
_l7:

		b _end2
_end2:

		li $22 0
		move $10 $22
_whl3:

		blt $10 $6 _l8
_l9:

		b _end3
_l8:

		li $23 4
		mul $24 $10 $23
		addi $24 $24 12
		add $24 $24 $29
		lw $25 4($24)
		li $7 4
		mul $9 $10 $7
		addi $9 $9 132
		add $9 $9 $29
		lw $12 4($9)
		mul $14 $25 $12
		add $16 $8 $14
		move $8 $16
		li $18 1
		add $20 $10 $18
		move $10 $20
		blt $10 $6 _l8
_l10:

		b _end3
_end3:

		la $4 _str36_7
		li $2 4
		syscall
		move $4 $8
		li $2 1
		syscall
		la $4 _str36_39
		li $2 4
		syscall
		li $2 10
		syscall
