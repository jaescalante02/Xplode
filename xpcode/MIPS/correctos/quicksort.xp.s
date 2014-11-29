.data
_str47_7:  .asciiz "Escriba el tamanio del arreglo\n"
_str52_7:  .asciiz "Escriba los elementos del arreglo\n"
_str59_7:  .asciiz "Arreglo ordenado:\n"
_str61_14:  .asciiz " "
_str67_7:  .asciiz "Arreglo ordenado:\n"
_str69_14:  .asciiz " "
_str72_7:  .asciiz "\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -408
		la $4 _str47_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $5 $2
		move $6 $5
		li $7 0
		move $8 $7
		la $4 _str52_7
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

		li $14 0
		move $8 $14
		la $4 _str59_7
		li $2 4
		syscall
_whl2:

		blt $8 $6 _l5
_l6:

		b _end2
_l5:

		li $15 4
		mul $16 $8 $15
		addi $16 $16 8
		add $16 $16 $29
		lw $17 4($16)
		move $4 $17
		li $2 1
		syscall
		la $4 _str61_14
		li $2 4
		syscall
		li $18 1
		add $19 $8 $18
		move $8 $19
		blt $8 $6 _l5
_l7:

		b _end2
_end2:

		li $20 1
		sub $21 $6 $20
		addi $22 $0 4
		add $22 $22 $29
		sw $8 4($22)
		addi $22 $0 0
		add $22 $22 $29
		sw $6 4($22)
		addi $22 $0 12
		add $22 $22 $29
		sw $22 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		sw $21 4($29)
		li $22 0
		addi $29 $29 -4
		sw $22 4($29)
		addi $29 $29 -4
		la $23 quicksort
		jal $23
		lw $23 0($29)
		addi $29 $29 12
		li $24 0
		move $25 $24
		la $4 _str67_7
		li $2 4
		syscall
_whl3:

		addi $5 $0 0
		add $5 $5 $29
		lw $5 4($5)
		blt $25 $5 _l8
_l9:

		b _end3
_l8:

		li $7 4
		mul $10 $25 $7
		addi $10 $10 8
		add $10 $10 $29
		lw $9 4($10)
		move $4 $9
		li $2 1
		syscall
		la $4 _str69_14
		li $2 4
		syscall
		li $11 1
		add $12 $25 $11
		move $25 $12
		blt $25 $5 _l8
_l10:

		b _end3
_end3:

		la $4 _str72_7
		li $2 4
		syscall
		li $2 10
		syscall
quicksort:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 -16
_if1:

		addi $13 $0 0
		add $13 $13 $30
		lw $13 4($13)
		addi $14 $0 4
		add $14 $14 $30
		lw $14 4($14)
		ble $14 $13 _l11
_l12:

		b _els1
_l11:

		addi $15 $0 0
		add $15 $15 $30
		sw $13 4($15)
		addi $15 $0 4
		add $15 $15 $30
		sw $14 4($15)
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
		move $18 $17
		addi $19 $0 4
		add $19 $19 $30
		lw $19 4($19)
		move $20 $19
		li $21 4
		mul $22 $19 $21
		addi $6 $0 8
		add $6 $6 $30
		lw $6 4($6)
		add $22 $22 $6
		lw $8 0($22)
		move $6 $8
_whl4:

		b _l13
_l13:

		li $24 1
		add $7 $18 $24
		move $18 $7
_whl5:

		li $10 4
		mul $9 $18 $10
		addi $12 $0 8
		add $12 $12 $30
		lw $12 4($12)
		add $9 $9 $12
		lw $11 0($9)
		blt $11 $6 _l14
_l15:

		b _end5
_l14:

		li $12 1
		add $23 $18 $12
		move $18 $23
		li $25 4
		mul $5 $18 $25
		addi $14 $0 8
		add $14 $14 $30
		lw $14 4($14)
		add $5 $5 $14
		lw $13 0($5)
		blt $13 $6 _l14
_l16:

		b _end5
_end5:

		li $14 1
		sub $15 $20 $14
		move $20 $15
_whl6:

		li $17 4
		mul $21 $20 $17
		addi $8 $0 8
		add $8 $8 $30
		lw $8 4($8)
		add $21 $21 $8
		lw $22 0($21)
		bgt $22 $6 _l17
_l18:

		b _end6
_l17:

		li $8 1
		sub $24 $20 $8
		move $20 $24
		li $7 4
		mul $10 $20 $7
		addi $11 $0 8
		add $11 $11 $30
		lw $11 4($11)
		add $10 $10 $11
		lw $9 0($10)
		bgt $9 $6 _l17
_l19:

		b _end6
_end6:

_if2:

		bge $18 $20 _l20
_l21:

		b _els2
_l20:

		b _end4
_l22:

_els2:

		li $11 4
		mul $12 $18 $11
		addi $25 $0 8
		add $25 $25 $30
		lw $25 4($25)
		add $12 $12 $25
		lw $23 0($12)
		move $25 $23
		li $5 4
		mul $13 $20 $5
		addi $15 $0 8
		add $15 $15 $30
		lw $15 4($15)
		add $13 $13 $15
		lw $14 0($13)
		li $15 4
		mul $17 $18 $15
		addi $21 $0 8
		add $21 $21 $30
		lw $21 4($21)
		add $17 $17 $21
		sw $14 0($17)
		li $21 4
		mul $22 $20 $21
		addi $8 $0 8
		add $8 $8 $30
		lw $8 4($8)
		add $22 $22 $8
		sw $25 0($22)
		b _l13
_end4:

		li $8 4
		mul $24 $18 $8
		addi $10 $0 8
		add $10 $10 $30
		lw $10 4($10)
		add $24 $24 $10
		lw $7 0($24)
		move $25 $7
		li $10 4
		mul $9 $19 $10
		addi $12 $0 8
		add $12 $12 $30
		lw $12 4($12)
		add $9 $9 $12
		lw $11 0($9)
		li $12 4
		mul $23 $18 $12
		addi $5 $0 8
		add $5 $5 $30
		lw $5 4($5)
		add $23 $23 $5
		sw $11 0($23)
		li $5 4
		mul $13 $19 $5
		addi $15 $0 8
		add $15 $15 $30
		lw $15 4($15)
		add $13 $13 $15
		sw $25 0($13)
		addi $15 $0 0
		add $15 $15 $29
		sw $18 4($15)
		addi $15 $0 4
		add $15 $15 $29
		sw $20 4($15)
		addi $15 $0 0
		add $15 $15 $30
		sw $16 4($15)
		addi $15 $0 4
		add $15 $15 $30
		sw $19 4($15)
		addi $15 $0 8
		add $15 $15 $29
		sw $6 4($15)
		addi $15 $0 12
		add $15 $15 $29
		sw $25 4($15)
		addi $15 $0 8
		add $15 $15 $30
		lw $15 4($15)
		sw $15 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		sw $20 4($29)
		addi $29 $29 -4
		sw $16 4($29)
		addi $29 $29 -4
		la $15 quicksort
		jal $15
		lw $15 0($29)
		addi $29 $29 12
		li $14 1
		addi $17 $0 0
		add $17 $17 $29
		lw $17 4($17)
		add $21 $17 $14
		addi $22 $0 0
		add $22 $22 $29
		sw $17 4($22)
		addi $22 $0 8
		add $22 $22 $30
		lw $22 4($22)
		sw $22 0($29)
		addi $29 $29 -4
		addi $22 $0 4
		add $22 $22 $30
		lw $22 4($22)
		addi $29 $29 -4
		sw $22 4($29)
		addi $29 $29 -4
		sw $21 4($29)
		addi $29 $29 -4
		la $8 quicksort
		jal $8
		lw $8 0($29)
		addi $29 $29 12
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
