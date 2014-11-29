.data
_str54_7:  .asciiz "Escriba el tamanio del arreglo\n"
_str59_7:  .asciiz "Escriba los elementos del arreglo\n"
_str67_7:  .asciiz "El arreglo ordenado es:\n"
_str72_14:  .asciiz " "
_str75_7:  .asciiz "\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -408
		la $4 _str54_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $5 $2
		move $6 $5
		li $7 0
		move $8 $7
		la $4 _str59_7
		li $2 4
		syscall
_whl1:

		blt $8 $6 _l2
_l3:

		b _end1
_l2:

		li $2 5
		syscall
		move $9 $2
		li $10 4
		mul $11 $8 $10
		addi $11 $11 8
		add $11 $11 $29
		sw $9 4($11)
		li $12 1
		add $13 $8 $12
		move $8 $13
		blt $8 $6 _l2
_l4:

		b _end1
_end1:

		li $14 1
		sub $15 $6 $14
		addi $16 $0 4
		add $16 $16 $29
		sw $8 4($16)
		addi $16 $0 0
		add $16 $16 $29
		sw $6 4($16)
		addi $29 $29 -4
		sw $15 4($29)
		li $16 0
		addi $29 $29 -4
		sw $16 4($29)
		addi $17 $0 212
		add $17 $17 $29
		sw $17 0($29)
		addi $29 $29 -4
		addi $17 $0 12
		add $17 $17 $29
		sw $17 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		la $17 sort
		jal $17
		lw $17 0($29)
		addi $29 $29 16
		la $4 _str67_7
		li $2 4
		syscall
		li $18 0
		move $19 $18
_whl2:

		addi $20 $0 0
		add $20 $20 $29
		lw $20 4($20)
		blt $19 $20 _l5
_l6:

		b _end2
_l5:

		li $21 4
		mul $22 $19 $21
		addi $22 $22 8
		add $22 $22 $29
		lw $23 4($22)
		move $4 $23
		li $2 1
		syscall
		la $4 _str72_14
		li $2 4
		syscall
		li $24 1
		add $25 $19 $24
		move $19 $25
		blt $19 $20 _l5
_l7:

		b _end2
_end2:

		la $4 _str75_7
		li $2 4
		syscall
		li $2 10
		syscall
sort:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 -16
_if1:

		addi $5 $0 12
		add $5 $5 $30
		lw $5 4($5)
		addi $7 $0 8
		add $7 $7 $30
		lw $7 4($7)
		bge $7 $5 _l8
_l9:

		b _els1
_l8:

		addi $10 $0 8
		add $10 $10 $30
		sw $7 4($10)
		addi $10 $0 12
		add $10 $10 $30
		sw $5 4($10)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els1:

		addi $10 $0 12
		add $10 $10 $30
		lw $10 4($10)
		addi $9 $0 8
		add $9 $9 $30
		lw $9 4($9)
		add $11 $9 $10
		li $12 2
		div $11 $12
		mflo $13
		move $14 $13
		addi $15 $0 0
		add $15 $15 $29
		sw $14 4($15)
		addi $15 $0 8
		add $15 $15 $30
		sw $9 4($15)
		addi $15 $0 12
		add $15 $15 $30
		sw $10 4($15)
		addi $29 $29 -4
		sw $14 4($29)
		addi $29 $29 -4
		sw $9 4($29)
		addi $15 $0 4
		add $15 $15 $30
		lw $15 4($15)
		sw $15 0($29)
		addi $29 $29 -4
		addi $15 $0 0
		add $15 $15 $30
		lw $15 4($15)
		sw $15 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		la $15 sort
		jal $15
		lw $15 0($29)
		addi $29 $29 16
		li $16 1
		addi $8 $0 0
		add $8 $8 $29
		lw $8 4($8)
		add $6 $8 $16
		addi $18 $0 0
		add $18 $18 $29
		sw $8 4($18)
		addi $18 $0 12
		add $18 $18 $30
		lw $18 4($18)
		addi $29 $29 -4
		sw $18 4($29)
		addi $29 $29 -4
		sw $6 4($29)
		addi $21 $0 4
		add $21 $21 $30
		lw $21 4($21)
		sw $21 0($29)
		addi $29 $29 -4
		addi $21 $0 0
		add $21 $21 $30
		lw $21 4($21)
		sw $21 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		la $21 sort
		jal $21
		lw $21 0($29)
		addi $29 $29 16
		addi $22 $0 8
		add $22 $22 $30
		lw $22 4($22)
		move $23 $22
		li $24 1
		addi $25 $0 0
		add $25 $25 $29
		lw $25 4($25)
		add $17 $25 $24
		move $19 $17
		move $20 $22
_whl3:

		blt $23 $25 _l11
_l12:

		b _end3
_l11:

		addi $7 $0 12
		add $7 $7 $30
		lw $7 4($7)
		blt $19 $7 _l10
_l13:

		b _end3
_l10:

_if2:

		li $5 4
		mul $11 $23 $5
		addi $13 $0 0
		add $13 $13 $30
		lw $13 4($13)
		add $11 $11 $13
		lw $12 0($11)
		li $13 4
		mul $14 $19 $13
		addi $10 $0 0
		add $10 $10 $30
		lw $10 4($10)
		add $14 $14 $10
		lw $9 0($14)
		blt $12 $9 _l14
_l15:

		b _els2
_l14:

		li $10 4
		mul $16 $23 $10
		addi $15 $0 0
		add $15 $15 $30
		lw $15 4($15)
		add $16 $16 $15
		lw $6 0($16)
		li $15 4
		mul $8 $20 $15
		addi $18 $0 4
		add $18 $18 $30
		lw $18 4($18)
		add $8 $8 $18
		sw $6 0($8)
		li $18 1
		add $24 $23 $18
		move $23 $24
		b _end4
_els2:

		li $17 4
		mul $5 $19 $17
		addi $13 $0 0
		add $13 $13 $30
		lw $13 4($13)
		add $5 $5 $13
		lw $11 0($5)
		li $13 4
		mul $14 $20 $13
		addi $9 $0 4
		add $9 $9 $30
		lw $9 4($9)
		add $14 $14 $9
		sw $11 0($14)
		li $9 1
		add $12 $19 $9
		move $19 $12
_end4:

		li $10 1
		add $16 $20 $10
		move $20 $16
		blt $23 $25 _l16
_l17:

		b _end3
_l16:

		blt $19 $7 _l10
_l18:

		b _end3
_end3:

_whl4:

		blt $23 $25 _l19
_l20:

		b _end5
_l19:

		li $15 4
		mul $6 $23 $15
		addi $18 $0 0
		add $18 $18 $30
		lw $18 4($18)
		add $6 $6 $18
		lw $8 0($6)
		li $18 4
		mul $24 $20 $18
		addi $17 $0 4
		add $17 $17 $30
		lw $17 4($17)
		add $24 $24 $17
		sw $8 0($24)
		li $17 1
		add $5 $23 $17
		move $23 $5
		li $13 1
		add $11 $20 $13
		move $20 $11
		blt $23 $25 _l19
_l21:

		b _end5
_end5:

_whl5:

		blt $19 $7 _l22
_l23:

		b _end6
_l22:

		li $14 4
		mul $9 $19 $14
		addi $10 $0 0
		add $10 $10 $30
		lw $10 4($10)
		add $9 $9 $10
		lw $12 0($9)
		li $10 4
		mul $16 $20 $10
		addi $15 $0 4
		add $15 $15 $30
		lw $15 4($15)
		add $16 $16 $15
		sw $12 0($16)
		li $15 1
		add $6 $19 $15
		move $19 $6
		li $18 1
		add $8 $20 $18
		move $20 $8
		blt $19 $7 _l22
_l24:

		b _end6
_end6:

		move $23 $22
_whl6:

		ble $23 $7 _l25
_l26:

		b _end7
_l25:

		li $24 4
		mul $17 $23 $24
		addi $13 $0 4
		add $13 $13 $30
		lw $13 4($13)
		add $17 $17 $13
		lw $5 0($17)
		li $13 4
		mul $11 $23 $13
		addi $14 $0 0
		add $14 $14 $30
		lw $14 4($14)
		add $11 $11 $14
		sw $5 0($11)
		li $14 1
		add $9 $23 $14
		move $23 $9
		ble $23 $7 _l25
_l27:

		b _end7
_end7:

		addi $10 $0 4
		add $10 $10 $29
		sw $23 4($10)
		addi $10 $0 12
		add $10 $10 $29
		sw $20 4($10)
		addi $10 $0 8
		add $10 $10 $29
		sw $19 4($10)
		addi $10 $0 0
		add $10 $10 $29
		sw $25 4($10)
		addi $10 $0 8
		add $10 $10 $30
		sw $22 4($10)
		addi $10 $0 12
		add $10 $10 $30
		sw $7 4($10)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
