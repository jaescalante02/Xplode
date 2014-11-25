.data
_str14_9:  .asciiz "Mover plato de "
_str16_9:  .asciiz " a "
_str18_9:  .asciiz "\n"
_str28_7:  .asciiz "Escriba el numero de platos iniciales, que se moveran del plato 1 al 2\n"
_str8_11:  .asciiz "Mover plato de "
_str8_35:  .asciiz " a "
_str8_47:  .asciiz "\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -8
		la $4 _str28_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $5 $2
		move $6 $5
		addi $7 $0 4
		add $7 $7 $29
		sw $6 4($7)
		li $7 3
		addi $29 $29 -4
		sw $7 4($29)
		li $8 2
		addi $29 $29 -4
		sw $8 4($29)
		li $9 1
		addi $29 $29 -4
		sw $9 4($29)
		addi $29 $29 -4
		sw $6 4($29)
		addi $29 $29 -4
		la $10 hanoi
		jal $10
		lw $10 0($29)
		addi $29 $29 16
		li $2 10
		syscall
hanoi:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 0
_if1:

		li $11 1
		addi $12 $0 0
		add $12 $12 $30
		lw $12 4($12)
		beq $12 $11 _l2
_l3:

		b _els1
_l2:

		la $4 _str8_11
		li $2 4
		syscall
		addi $13 $0 4
		add $13 $13 $30
		lw $13 4($13)
		move $4 $13
		li $2 1
		syscall
		la $4 _str8_35
		li $2 4
		syscall
		addi $14 $0 8
		add $14 $14 $30
		lw $14 4($14)
		move $4 $14
		li $2 1
		syscall
		la $4 _str8_47
		li $2 4
		syscall
		addi $15 $0 8
		add $15 $15 $30
		sw $14 4($15)
		addi $15 $0 4
		add $15 $15 $30
		sw $13 4($15)
		addi $15 $0 0
		add $15 $15 $30
		sw $12 4($15)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els1:

		li $15 1
		addi $16 $0 0
		add $16 $16 $30
		lw $16 4($16)
		sub $17 $16 $15
		addi $18 $0 0
		add $18 $18 $30
		sw $16 4($18)
		addi $18 $0 8
		add $18 $18 $30
		lw $18 4($18)
		addi $29 $29 -4
		sw $18 4($29)
		addi $19 $0 12
		add $19 $19 $30
		lw $19 4($19)
		addi $29 $29 -4
		sw $19 4($29)
		addi $20 $0 4
		add $20 $20 $30
		lw $20 4($20)
		addi $29 $29 -4
		sw $20 4($29)
		addi $29 $29 -4
		sw $17 4($29)
		addi $29 $29 -4
		la $21 hanoi
		jal $21
		lw $21 0($29)
		addi $29 $29 16
		la $4 _str14_9
		li $2 4
		syscall
		addi $22 $0 4
		add $22 $22 $30
		lw $22 4($22)
		move $4 $22
		li $2 1
		syscall
		la $4 _str16_9
		li $2 4
		syscall
		addi $23 $0 8
		add $23 $23 $30
		lw $23 4($23)
		move $4 $23
		li $2 1
		syscall
		la $4 _str18_9
		li $2 4
		syscall
		li $24 1
		addi $25 $0 0
		add $25 $25 $30
		lw $25 4($25)
		sub $7 $25 $24
		addi $8 $0 8
		add $8 $8 $30
		sw $23 4($8)
		addi $8 $0 4
		add $8 $8 $30
		sw $22 4($8)
		addi $8 $0 0
		add $8 $8 $30
		sw $25 4($8)
		addi $29 $29 -4
		sw $22 4($29)
		addi $29 $29 -4
		sw $23 4($29)
		addi $8 $0 12
		add $8 $8 $30
		lw $8 4($8)
		addi $29 $29 -4
		sw $8 4($29)
		addi $29 $29 -4
		sw $7 4($29)
		addi $29 $29 -4
		la $9 hanoi
		jal $9
		lw $9 0($29)
		addi $29 $29 16
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
