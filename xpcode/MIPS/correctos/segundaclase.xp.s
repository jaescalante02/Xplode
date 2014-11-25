.data
_str11_37:  .asciiz "\n"
_str11_9:  .asciiz "La funcion devuelve: "

.text

main:
_l1:

INIT:

		addi $29 $29 -12
		la $5 cuadrado
		sw $5 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		la $5 prueba
		jal $5
		lw $5 0($29)
		addi $29 $29 4
		la $6 cubo
		sw $6 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		la $6 prueba
		jal $6
		lw $6 0($29)
		addi $29 $29 4
		la $7 fib
		sw $7 0($29)
		addi $29 $29 -4
		addi $29 $29 -4
		la $7 prueba
		jal $7
		lw $7 0($29)
		addi $29 $29 4
		li $2 10
		syscall
prueba:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 -4
		li $8 6
		addi $29 $29 -4
		sw $8 4($29)
		addi $9 $0 0
		add $9 $9 $30
		lw $9 4($9)
		addi $29 $29 -4
		jal $9
		lw $10 0($29)
		addi $29 $29 4
		move $11 $10
		la $4 _str11_9
		li $2 4
		syscall
		move $4 $11
		li $2 1
		syscall
		la $4 _str11_37
		li $2 4
		syscall
		addi $12 $0 0
		add $12 $12 $29
		sw $11 4($12)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
cuadrado:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 0
		addi $12 $0 0
		add $12 $12 $30
		lw $12 4($12)
		mul $13 $12 $12
		sw $13 0($30)
		addi $14 $0 0
		add $14 $14 $30
		sw $12 4($14)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
		sw $14 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
cubo:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 0
		addi $15 $0 0
		add $15 $15 $30
		lw $15 4($15)
		mul $16 $15 $15
		mul $17 $16 $15
		sw $17 0($30)
		addi $18 $0 0
		add $18 $18 $30
		sw $15 4($18)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
		sw $18 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
fib:

		addi $29 $29 -4
		sw $31 4($29)
		addi $29 $29 -4
		sw $30 4($29)
		addi $30 $29 12
		addi $29 $29 -8
_if1:

		li $19 2
		addi $20 $0 0
		add $20 $20 $30
		lw $20 4($20)
		blt $20 $19 _l2
		addi $21 $0 0
		add $21 $21 $30
		sw $20 4($21)
_l3:

		b _els1
_l2:

		li $21 1
		sw $21 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
_els1:

		li $22 1
		addi $23 $0 0
		add $23 $23 $30
		lw $23 4($23)
		sub $24 $23 $22
		addi $25 $0 0
		add $25 $25 $30
		sw $23 4($25)
		addi $29 $29 -4
		sw $24 4($29)
		addi $29 $29 -4
		la $25 fib
		jal $25
		lw $25 0($29)
		addi $29 $29 4
		move $5 $25
		li $6 2
		addi $7 $0 0
		add $7 $7 $30
		lw $7 4($7)
		sub $8 $7 $6
		addi $9 $0 0
		add $9 $9 $29
		sw $5 4($9)
		addi $9 $0 0
		add $9 $9 $30
		sw $7 4($9)
		addi $29 $29 -4
		sw $8 4($29)
		addi $29 $29 -4
		la $9 fib
		jal $9
		lw $9 0($29)
		addi $29 $29 4
		move $10 $9
		addi $11 $0 0
		add $11 $11 $29
		lw $11 4($11)
		add $13 $10 $11
		sw $13 0($30)
		addi $12 $0 0
		add $12 $12 $29
		sw $11 4($12)
		addi $12 $0 4
		add $12 $12 $29
		sw $10 4($12)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
		sw $12 0($30)
		lw $31 -4($30)
		move $29 $30
		lw $30 -8($30)
		jr $31
