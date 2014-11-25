.data
_str19_19:  .asciiz "]="
_str19_31:  .asciiz "\n"
_str19_7:  .asciiz "fact["
_str8_7:  .asciiz "Escriba el numero al cual quiere saber el factorial:\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -12
		la $4 _str8_7
		li $2 4
		syscall
		li $2 5
		syscall
		move $5 $2
		move $6 $5
		li $7 1
		move $8 $7
		li $9 1
		move $10 $9
_whl1:

		ble $8 $6 _l2
_l3:

		b _end1
_l2:

		mul $11 $10 $8
		move $10 $11
		li $12 1
		add $13 $8 $12
		move $8 $13
		ble $8 $6 _l2
_l4:

		b _end1
_end1:

		la $4 _str19_7
		li $2 4
		syscall
		move $4 $6
		li $2 1
		syscall
		la $4 _str19_19
		li $2 4
		syscall
		move $4 $10
		li $2 1
		syscall
		la $4 _str19_31
		li $2 4
		syscall
		li $2 10
		syscall
