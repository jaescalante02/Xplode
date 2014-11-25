.data
_str23_25:  .asciiz " es: "
_str23_37:  .asciiz "\n\n"
_str23_7:  .asciiz "La raiz de "
_str8_7:  .asciiz "Escriba el valor al que le quiere conocer su raiz\n\n"

.text

main:
_l1:

INIT:

		addi $29 $29 -16
		la $4 _str8_7
		li $2 4
		syscall
		li $2 6
		syscall
		mov.s $f1 $f0
		mov.s $f2 $f1
		li.s $f3 1.0
		mov.s $f4 $f3
		li $5 1
		move $6 $5
_whl1:

		li $7 100
		ble $6 $7 _l2
_l3:

		b _end1
_l2:

		div.s $f5 $f2 $f4
		add.s $f6 $f4 $f5
		li.s $f7 0.5
		mul.s $f8 $f7 $f6
		mov.s $f9 $f8
		mov.s $f4 $f9
		li $8 1
		add $9 $6 $8
		move $6 $9
		li $10 100
		ble $6 $10 _l2
_l4:

		b _end1
_end1:

		la $4 _str23_7
		li $2 4
		syscall
		mov.s $f12 $f2
		li $2 2
		syscall
		la $4 _str23_25
		li $2 4
		syscall
		mov.s $f12 $f4
		li $2 2
		syscall
		la $4 _str23_37
		li $2 4
		syscall
		li $2 10
		syscall
