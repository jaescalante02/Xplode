.data
_str28_7:  .asciiz "Escriba el valor al cual quiere saber su factorial:\n"
_str31_19:  .asciiz "]="
_str31_34:  .asciiz "\n"
_str31_7:  .asciiz "fact["

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
		la $4 _str31_7
		li $2 4
		syscall
		move $4 $6
		li $2 1
		syscall
		la $4 _str31_19
		li $2 4
		syscall
		addi $7 $0 4
		add $7 $7 $29
		sw $6 4($7)
		addi $29 $29 -4
		sw $6 4($29)
		addi $29 $29 -4
		la $7 fact
		jal $7
		lw $7 0($29)
		addi $29 $29 4
		move $4 $7
		li $2 1
		syscall
		la $4 _str31_34
		li $2 4
		syscall
		li $2 10
		syscall
fact:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 -4
_if1:

		li $8 0
		addi $9 $0 0
		add $9 $9 $30
		lw $9 4($9)
		beq $9 $8 _l2
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

_if2:

		li $11 1
		addi $12 $0 0
		add $12 $12 $30
		lw $12 4($12)
		beq $12 $11 _l4
_l5:

		b _els2
_l4:

		li $13 1
		sw $13 0($30)
		addi $14 $0 0
		add $14 $14 $30
		sw $12 4($14)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els2:

		li $14 1
		addi $15 $0 0
		add $15 $15 $30
		lw $15 4($15)
		sub $16 $15 $14
		addi $17 $0 0
		add $17 $17 $30
		sw $15 4($17)
		addi $29 $29 -4
		sw $16 4($29)
		addi $29 $29 -4
		la $17 fact
		jal $17
		lw $17 0($29)
		addi $29 $29 4
		move $18 $17
		addi $19 $0 0
		add $19 $19 $30
		lw $19 4($19)
		mul $20 $19 $18
		sw $20 0($30)
		addi $21 $0 0
		add $21 $21 $29
		sw $18 4($21)
		addi $21 $0 0
		add $21 $21 $30
		sw $19 4($21)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
		sw $21 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
