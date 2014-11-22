.data
_str39_30:  .asciiz "\n"
_str7_46:  .asciiz "\n"
_str7_7:  .asciiz "Llamada a la función exitosa a="

.text

main:
_l1:

INIT:

		addi $29 $29 -84
		li $5 0
		move $6 $5
_whl1:

		li $7 20
		blt $6 $7 _l2
_l3:

		b _end1
_l2:

		li $9 4
		mul $10 $6 $9
		addi $10 $10 0
		add $10 $10 $29
		sw $6 4($10)
		li $11 1
		add $12 $6 $11
		move $6 $12
		li $13 20
		blt $6 $13 _l2
_l4:

		b _end1
_end1:

		li $14 4
		li $15 2
		mul $16 $15 $14
		addi $16 $16 0
		add $16 $16 $29
		lw $17 4($16)
		move $4 $17
		li $2 1
		syscall
		li $18 4
		li $19 3
		mul $20 $19 $18
		addi $20 $20 0
		add $20 $20 $29
		lw $21 4($20)
		move $4 $21
		li $2 1
		syscall
		li $22 4
		li $23 11
		mul $24 $23 $22
		addi $24 $24 0
		add $24 $24 $29
		lw $25 4($24)
		move $4 $25
		li $2 1
		syscall
		li $5 4
		li $7 2
		mul $9 $7 $5
		addi $9 $9 0
		add $9 $9 $29
		lw $11 4($9)
		move $4 $11
		li $2 1
		syscall
		la $4 _str39_30
		li $2 4
		syscall
		li $2 10
		syscall
f:

		la $4 _str7_7
		li $2 4
		syscall
		move $4 $13
		li $2 1
		syscall
		la $4 _str7_46
		li $2 4
		syscall
_if1:

		li $15 2
		li $14 2
		beq $14 $15 _l5
_l6:

		b _els1
_l5:

_if2:

		li $18 3
		li $23 3
		beq $23 $18 _l7
_l8:

		b _els2
_l7:

		li $7 7
		move $5 $7
_els2:

_els1:

