.data
_str15_22:  .asciiz "\n"
_str15_7:  .asciiz "a[4]="
_str16_24:  .asciiz "\n"
_str16_7:  .asciiz "a[11]="
_str17_22:  .asciiz "\n"
_str17_7:  .asciiz "a[4]="
_str18_16:  .asciiz "\n"
_str18_7:  .asciiz "i="

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

		li $9 8
		add $10 $6 $9
		li $11 4
		mul $12 $6 $11
		addi $12 $12 0
		add $12 $12 $29
		sw $10 0($12)
		li $13 1
		add $14 $6 $13
		move $6 $14
		li $15 20
		blt $6 $15 _l2
_l4:

		b _end1
_end1:

		la $4 _str15_7
		li $2 4
		syscall
		li $16 4
		li $17 4
		mul $18 $17 $16
		addi $18 $18 0
		add $18 $18 $29
		lw $19 0($18)
		move $4 $19
		li $2 1
		syscall
		la $4 _str15_22
		li $2 4
		syscall
		la $4 _str16_7
		li $2 4
		syscall
		li $20 4
		li $21 11
		mul $22 $21 $20
		addi $22 $22 0
		add $22 $22 $29
		lw $23 0($22)
		move $4 $23
		li $2 1
		syscall
		la $4 _str16_24
		li $2 4
		syscall
		la $4 _str17_7
		li $2 4
		syscall
		li $24 4
		li $25 4
		mul $5 $25 $24
		addi $5 $5 0
		add $5 $5 $29
		lw $7 0($5)
		move $4 $7
		li $2 1
		syscall
		la $4 _str17_22
		li $2 4
		syscall
		la $4 _str18_7
		li $2 4
		syscall
		move $4 $6
		li $2 1
		syscall
		la $4 _str18_16
		li $2 4
		syscall
		li $2 10
		syscall
