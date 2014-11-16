.data
_str4_7:  .asciiz "Hello world!\n"

.text

main:
_l1:

INIT:

		la $4 _str4_7
		li $2 4
		syscall
		li $2 10
		syscall
