.data
_str10_16:  .asciiz "i="
_str10_25:  .asciiz "\n"
_str10_7:  .asciiz "j="

.text

main:
_l1:

INIT:

		addi $29 $29 -4
		move $6 $5
		li $7 0
		move $8 $7
		la $4 _str10_7
		li $2 4
		syscall
		la $4 _str10_16
		li $2 4
		syscall
		la $4 _str10_25
		li $2 4
		syscall
		li $2 10
		syscall
