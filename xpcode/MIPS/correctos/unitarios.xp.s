.data
_str20_13:  .asciiz "\n"
_str24_13:  .asciiz "\n"
_str5_13:  .asciiz "\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -104
		li $5 4
		li $6 7
		mul $7 $6 $5
		li $8 99
		addi $7 $7 0
		add $7 $7 $29
		sw $8 4($7)
		li $9 4
		li $10 7
		mul $11 $10 $9
		addi $11 $11 0
		add $11 $11 $29
		lw $12 4($11)
		move $4 $12
		li $2 1
		syscall
		la $4 _str20_13
		li $2 4
		syscall
		addi $13 $0 4
		add $13 $13 $29
		sw $13 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		la $13 prueba
		jal $13
		lw $13 0($29)
		addi $29 $29 4
		li $14 4
		li $15 7
		mul $16 $15 $14
		addi $16 $16 0
		add $16 $16 $29
		lw $17 4($16)
		move $4 $17
		li $2 1
		syscall
		la $4 _str24_13
		li $2 4
		syscall
		li $2 10
		syscall
prueba:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 0
		li $18 4
		li $19 7
		mul $20 $19 $18
		addi $22 $0 0
		add $22 $22 $30
		lw $22 4($22)
		add $20 $20 $22
		lw $21 0($20)
		move $4 $21
		li $2 1
		syscall
		la $4 _str5_13
		li $2 4
		syscall
		li $22 4
		li $23 7
		mul $24 $23 $22
		li $25 12
		addi $6 $0 0
		add $6 $6 $30
		lw $6 4($6)
		add $24 $24 $6
		sw $25 0($24)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
