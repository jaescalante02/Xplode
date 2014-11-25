.data
_str28_7:  .asciiz "Escriba el primer argumento:\n"
_str30_7:  .asciiz "Escriba el segundo argumento:\n"
_str33_19:  .asciiz " , "
_str33_29:  .asciiz " )="
_str33_46:  .asciiz "\n"
_str33_7:  .asciiz "ack("

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
		la $4 _str30_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $7 $2
		move $8 $7
		la $4 _str33_7
		li $2 4
		syscall
		move $4 $6
		li $2 1
		syscall
		la $4 _str33_19
		li $2 4
		syscall
		move $4 $8
		li $2 1
		syscall
		la $4 _str33_29
		li $2 4
		syscall
		addi $9 $0 0
		add $9 $9 $29
		sw $6 4($9)
		addi $9 $0 4
		add $9 $9 $29
		sw $8 4($9)
		addi $29 $29 -4
		sw $8 4($29)
		addi $29 $29 -4
		sw $6 4($29)
		addi $29 $29 -4
		la $9 ack
		jal $9
		lw $9 0($29)
		addi $29 $29 8
		move $4 $9
		li $2 1
		syscall
		la $4 _str33_46
		li $2 4
		syscall
		li $2 10
		syscall
ack:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 -4
_if1:

		li $10 0
		addi $11 $0 0
		add $11 $11 $30
		lw $11 4($11)
		beq $11 $10 _l2
_l3:

		b _els1
_l2:

		li $12 1
		addi $13 $0 4
		add $13 $13 $30
		lw $13 4($13)
		add $14 $13 $12
		sw $14 0($30)
		addi $15 $0 0
		add $15 $15 $30
		sw $11 4($15)
		addi $15 $0 4
		add $15 $15 $30
		sw $13 4($15)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els1:

_if2:

		li $15 0
		addi $16 $0 4
		add $16 $16 $30
		lw $16 4($16)
		beq $16 $15 _l4
_l5:

		b _els2
_l4:

		li $17 1
		addi $18 $0 0
		add $18 $18 $30
		lw $18 4($18)
		sub $19 $18 $17
		addi $20 $0 0
		add $20 $20 $30
		sw $18 4($20)
		addi $20 $0 4
		add $20 $20 $30
		sw $16 4($20)
		li $20 1
		addi $29 $29 -4
		sw $20 4($29)
		addi $29 $29 -4
		sw $19 4($29)
		addi $29 $29 -4
		la $21 ack
		jal $21
		lw $21 0($29)
		addi $29 $29 8
		sw $21 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els2:

		li $22 1
		addi $23 $0 4
		add $23 $23 $30
		lw $23 4($23)
		sub $24 $23 $22
		addi $25 $0 4
		add $25 $25 $30
		sw $23 4($25)
		addi $29 $29 -4
		sw $24 4($29)
		addi $25 $0 0
		add $25 $25 $30
		lw $25 4($25)
		addi $29 $29 -4
		sw $25 4($29)
		addi $29 $29 -4
		la $5 ack
		jal $5
		lw $5 0($29)
		addi $29 $29 8
		move $7 $5
		li $6 1
		addi $8 $0 0
		add $8 $8 $30
		lw $8 4($8)
		sub $9 $8 $6
		addi $10 $0 0
		add $10 $10 $30
		sw $8 4($10)
		addi $10 $0 0
		add $10 $10 $29
		sw $7 4($10)
		addi $29 $29 -4
		sw $7 4($29)
		addi $29 $29 -4
		sw $9 4($29)
		addi $29 $29 -4
		la $10 ack
		jal $10
		lw $10 0($29)
		addi $29 $29 8
		sw $10 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
		sw $12 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
