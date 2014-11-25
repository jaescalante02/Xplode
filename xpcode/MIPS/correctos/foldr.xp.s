.data
_str58_27:  .asciiz "\n"
_str58_7:  .asciiz "menor="
_str62_27:  .asciiz "\n"
_str62_7:  .asciiz "mayor="

.text

main:
_l1:

INIT:

		addi $29 $29 -128
		li $5 0
		move $6 $5
_whl1:

		li $7 30
		blt $6 $7 _l2
_l3:

		b _end1
_l2:

		li $2 5
		syscall
		move $8 $2
		li $9 4
		mul $10 $6 $9
		addi $10 $10 0
		add $10 $10 $29
		sw $8 4($10)
		li $11 1
		add $12 $6 $11
		move $6 $12
		li $13 30
		blt $6 $13 _l2
_l4:

		b _end1
_end1:

		addi $14 $0 120
		add $14 $14 $29
		sw $6 4($14)
		addi $14 $0 4
		add $14 $14 $29
		sw $14 0($29)
		addi $29 $29 -4
		la $14 menor
		sw $14 0($29)
		addi $29 $29 -4
		li $14 30
		addi $29 $29 -4
		sw $14 4($29)
		li $15 0
		addi $29 $29 -4
		sw $15 4($29)
		addi $29 $29 -4
		la $16 foldr
		jal $16
		lw $16 0($29)
		addi $29 $29 16
		move $17 $16
		la $4 _str58_7
		li $2 4
		syscall
		move $4 $17
		li $2 1
		syscall
		la $4 _str58_27
		li $2 4
		syscall
		addi $18 $0 124
		add $18 $18 $29
		sw $17 4($18)
		addi $18 $0 4
		add $18 $18 $29
		sw $18 0($29)
		addi $29 $29 -4
		la $18 mayor
		sw $18 0($29)
		addi $29 $29 -4
		li $18 30
		addi $29 $29 -4
		sw $18 4($29)
		li $19 0
		addi $29 $29 -4
		sw $19 4($29)
		addi $29 $29 -4
		la $20 foldr
		jal $20
		lw $20 0($29)
		addi $29 $29 16
		move $21 $20
		la $4 _str62_7
		li $2 4
		syscall
		move $4 $21
		li $2 1
		syscall
		la $4 _str62_27
		li $2 4
		syscall
		li $2 10
		syscall
menor:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 0
_if1:

		addi $22 $0 4
		add $22 $22 $30
		lw $22 4($22)
		addi $23 $0 0
		add $23 $23 $30
		lw $23 4($23)
		blt $23 $22 _l5
_l6:

		b _els1
_l5:

		sw $23 0($30)
		addi $24 $0 0
		add $24 $24 $30
		sw $23 4($24)
		addi $24 $0 4
		add $24 $24 $30
		sw $22 4($24)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els1:

		addi $24 $0 4
		add $24 $24 $30
		lw $24 4($24)
		sw $24 0($30)
		addi $25 $0 4
		add $25 $25 $30
		sw $24 4($25)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
		sw $25 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
mayor:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 0
_if2:

		addi $5 $0 4
		add $5 $5 $30
		lw $5 4($5)
		addi $7 $0 0
		add $7 $7 $30
		lw $7 4($7)
		bgt $7 $5 _l7
_l8:

		b _els2
_l7:

		sw $7 0($30)
		addi $9 $0 0
		add $9 $9 $30
		sw $7 4($9)
		addi $9 $0 4
		add $9 $9 $30
		sw $5 4($9)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els2:

		addi $9 $0 4
		add $9 $9 $30
		lw $9 4($9)
		sw $9 0($30)
		addi $8 $0 4
		add $8 $8 $30
		sw $9 4($8)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
		sw $8 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
foldr:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 0
_if3:

		addi $10 $0 0
		add $10 $10 $30
		lw $10 4($10)
		addi $11 $0 4
		add $11 $11 $30
		lw $11 4($11)
		beq $11 $10 _l9
_l10:

		b _els3
_l9:

		li $12 1
		sub $13 $11 $12
		li $14 4
		mul $15 $13 $14
		addi $16 $0 12
		add $16 $16 $30
		lw $16 4($16)
		add $15 $15 $16
		lw $6 0($15)
		sw $6 0($30)
		addi $16 $0 0
		add $16 $16 $30
		sw $10 4($16)
		addi $16 $0 4
		add $16 $16 $30
		sw $11 4($16)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els3:

		li $16 1
		addi $18 $0 0
		add $18 $18 $30
		lw $18 4($18)
		add $19 $18 $16
		addi $17 $0 0
		add $17 $17 $30
		sw $18 4($17)
		addi $17 $0 12
		add $17 $17 $30
		lw $17 4($17)
		sw $17 0($29)
		addi $29 $29 -4
		addi $17 $0 8
		add $17 $17 $30
		lw $17 4($17)
		sw $17 0($29)
		addi $29 $29 -4
		addi $17 $0 4
		add $17 $17 $30
		lw $17 4($17)
		addi $29 $29 -4
		sw $17 4($29)
		addi $29 $29 -4
		sw $19 4($29)
		addi $29 $29 -4
		la $20 foldr
		jal $20
		lw $20 0($29)
		addi $29 $29 16
		li $21 4
		addi $23 $0 0
		add $23 $23 $30
		lw $23 4($23)
		mul $22 $23 $21
		addi $25 $0 12
		add $25 $25 $30
		lw $25 4($25)
		add $22 $22 $25
		lw $24 0($22)
		addi $25 $0 0
		add $25 $25 $30
		sw $23 4($25)
		addi $29 $29 -4
		sw $20 4($29)
		addi $29 $29 -4
		sw $24 4($29)
		addi $25 $0 8
		add $25 $25 $30
		lw $25 4($25)
		addi $29 $29 -4
		jal $25
		lw $7 0($29)
		addi $29 $29 8
		sw $7 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
		sw $5 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
