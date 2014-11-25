.data
_str11_7:  .asciiz "true\n"
_str15_7:  .asciiz "false\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -4
_if1:

		b _els1
_l2:

		la $4 _str11_7
		li $2 4
		syscall
		b _end1
_els1:

		la $4 _str15_7
		li $2 4
		syscall
_end1:

		li $2 10
		syscall
