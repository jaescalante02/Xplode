.data
_str25_24:  .asciiz "]="
_str25_38:  .asciiz "\n"
_str25_7:  .asciiz "fibonacci["

.text

main:
_l1:

INIT:

		addi $29 $29 -12
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
		lw $8 0($29)
		addi $29 $29 4
		move $4 $8
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
		addi $29 $29 -12
_if1:

		li $9 2
		addi $10 $0 0
		add $10 $10 $30
		lw $10 4($10)
		blt $10 $9 _l2
_l3:

		b _els1
_l2:

		li $11 1
		sw $11 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els1:

		li $12 1
		addi $13 $0 0
		add $13 $13 $30
		lw $13 4($13)
		sub $14 $13 $12
		addi $29 $29 -4
		sw $14 4($29)
		addi $29 $29 -4
		la $15 fib
		jal $15
		lw $16 0($29)
		addi $29 $29 4
		move $17 $16
		addi $18 $0 0
		add $18 $18 $29
		sw $17 4($18)
		li $18 2
		addi $19 $0 0
		add $19 $19 $30
		lw $19 4($19)
		sub $20 $19 $18
		addi $29 $29 -4
		sw $20 4($29)
		addi $29 $29 -4
		la $21 fib
		jal $21
		lw $22 0($29)
		addi $29 $29 4
		move $23 $22
		addi $24 $0 0
		add $24 $24 $29
		lw $24 4($24)
		add $25 $23 $24
		sw $25 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
		sw $5 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
