.data
_str17_10:  .asciiz "\n"
_str21_10:  .asciiz "\n"
_str24_10:  .asciiz "\n"
_str33_10:  .asciiz "\n"
_str37_10:  .asciiz "\n"
_str5_10:  .asciiz "\n"
_str9_10:  .asciiz "\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -4
		li $5 3
		move $6 $5
		move $4 $6
		li $2 1
		syscall
		la $4 _str33_10
		li $2 4
		syscall
		addi $7 $0 0
		add $7 $7 $29
		sw $6 4($7)
		addi $7 $0 4
		add $7 $7 $29
		sw $7 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		la $7 prueba
		jal $7
		lw $7 0($29)
		addi $29 $29 4
		addi $8 $0 0
		add $8 $8 $29
		lw $8 4($8)
		move $4 $8
		li $2 1
		syscall
		la $4 _str37_10
		li $2 4
		syscall
		li $2 10
		syscall
prueba2:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 0
		addi $9 $0 0
		add $9 $9 $30
		lw $9 4($9)
		lw $9 0($9)
		move $4 $9
		li $2 1
		syscall
		la $4 _str5_10
		li $2 4
		syscall
		li $10 7
		move $9 $10
		move $4 $9
		li $2 1
		syscall
		la $4 _str9_10
		li $2 4
		syscall
		addi $11 $0 0
		add $11 $11 $30
		lw $11 4($11)
		sw $9 0($11)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
prueba:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 0
		addi $11 $0 0
		add $11 $11 $30
		lw $11 4($11)
		lw $11 0($11)
		move $4 $11
		li $2 1
		syscall
		la $4 _str17_10
		li $2 4
		syscall
		li $12 5
		move $11 $12
		move $4 $11
		li $2 1
		syscall
		la $4 _str21_10
		li $2 4
		syscall
		addi $13 $0 0
		add $13 $13 $30
		lw $13 4($13)
		sw $11 0($13)
		addi $13 $0 0
		add $13 $13 $30
		lw $13 4($13)
		sw $13 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		la $13 prueba2
		jal $13
		lw $13 0($29)
		addi $29 $29 4
		addi $14 $0 0
		add $14 $14 $30
		lw $14 4($14)
		lw $14 0($14)
		move $4 $14
		li $2 1
		syscall
		la $4 _str24_10
		li $2 4
		syscall
		addi $15 $0 0
		add $15 $15 $30
		lw $15 4($15)
		sw $14 0($15)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
