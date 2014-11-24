.data
_str17_12:  .asciiz "\n"
_str17_25:  .asciiz "\n"
_str17_37:  .asciiz "\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -92
		li.s $f1 0.65
		mov.s $f2 $f1
_whl1:

		li $5 20
		addi $6 $0 0
		add $6 $6 $29
		lw $6 4($6)
		blt $6 $5 _l2
_l3:

		b _end1
_l2:

		li $7 4
		mul $8 $6 $7
		addi $8 $8 4
		add $8 $8 $29
		swc1 $f2 4($8)
		li $9 1
		add $10 $6 $9
		move $6 $10
		li.s $f3 1.0
		sub.s $f4 $f2 $f3
		mov.s $f2 $f4
		li $11 20
		blt $6 $11 _l2
_l4:

		b _end1
_end1:

		li $12 4
		li $13 3
		mul $14 $13 $12
		addi $14 $14 4
		add $14 $14 $29
		lwc1 $f5 4($14)
		mov.s $f12 $f5
		li $2 2
		syscall
		la $4 _str17_12
		li $2 4
		syscall
		li $15 4
		li $16 11
		mul $17 $16 $15
		addi $17 $17 4
		add $17 $17 $29
		lwc1 $f6 4($17)
		mov.s $f12 $f6
		li $2 2
		syscall
		la $4 _str17_25
		li $2 4
		syscall
		li $18 4
		li $19 4
		mul $20 $19 $18
		addi $20 $20 4
		add $20 $20 $29
		lwc1 $f7 4($20)
		mov.s $f12 $f7
		li $2 2
		syscall
		la $4 _str17_37
		li $2 4
		syscall
		li $2 10
		syscall
