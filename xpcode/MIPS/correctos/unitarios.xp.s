.data
_str8_50:  .asciiz " "
_str8_59:  .asciiz "\n"
_str8_7:  .asciiz "Imprime el resultado de 7+8 y 8-7: "

.text

main:
_l1:

INIT:

		addi $29 $29 -8
		li $6 7
		move $5 $6
		li $8 8
		move $7 $8
		la $4 _str8_7
		li $2 4
		syscall
		add $9 $5 $7
		move $4 $9
		li $2 1
		syscall
		la $4 _str8_50
		li $2 4
		syscall
		sub $10 $7 $5
		move $4 $10
		li $2 1
		syscall
		la $4 _str8_59
		li $2 4
		syscall
		li $2 10
		syscall
