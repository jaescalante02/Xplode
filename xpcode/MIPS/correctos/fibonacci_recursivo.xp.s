.data
_str25_24:  .asciiz "]="
_str25_38:  .asciiz "\n"
_str25_7:  .asciiz "fibonacci["

.text

main:
_l1:

INIT:

		addi $29 $29 -8
		li $2 5
		syscall
		move $5 $2
		move $6 $5
		la $4 _str25_7
		li $2 4
		syscall
		move $4 $6
		li $2 1
		syscall
		la $4 _str25_24
		li $2 4
		syscall
		addi $7 $0 4
		add $7 $7 $29
		sw $6 4($7)
		addi $29 $29 -4
		sw $6 4($29)
		addi $29 $29 -4
		la $7 fib
		jal $7
		lw $7 0($29)
		addi $29 $29 4
		move $4 $7
		li $2 1
		syscall
		la $4 _str25_38
		li $2 4
		syscall
		li $2 10
		syscall
fib:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 -8
_if1:

		li $8 2
		addi $9 $0 0
		add $9 $9 $30
		lw $9 4($9)
		blt $9 $8 _l2
_l3:

		b _els1
_l2:

		li $10 1
		sw $10 0($30)
		addi $11 $0 0
		add $11 $11 $30
		sw $9 4($11)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els1:

		li $11 1
		addi $12 $0 0
		add $12 $12 $30
		lw $12 4($12)
		sub $13 $12 $11
		addi $14 $0 0
		add $14 $14 $30
		sw $12 4($14)
		addi $29 $29 -4
		sw $13 4($29)
		addi $29 $29 -4
		la $14 fib
		jal $14
		lw $14 0($29)
		addi $29 $29 4
		move $15 $14
		li $16 2
		addi $17 $0 0
		add $17 $17 $30
		lw $17 4($17)
		sub $18 $17 $16
		addi $19 $0 0
		add $19 $19 $29
		sw $15 4($19)
		addi $19 $0 0
		add $19 $19 $30
		sw $17 4($19)
		addi $29 $29 -4
		sw $18 4($29)
		addi $29 $29 -4
		la $19 fib
		jal $19
		lw $19 0($29)
		addi $29 $29 4
		move $20 $19
		addi $21 $0 0
		add $21 $21 $29
		lw $21 4($21)
		add $22 $20 $21
		sw $22 0($30)
		addi $23 $0 0
		add $23 $23 $29
		sw $21 4($23)
		addi $23 $0 4
		add $23 $23 $29
		sw $20 4($23)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
		sw $23 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
