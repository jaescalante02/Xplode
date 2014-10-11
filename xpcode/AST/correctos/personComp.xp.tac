#../xpcode/correctos/personComp.xp
l1:
INIT:
#IF situado en 37:3, termina en la etiqueta els1
if1:
		PARM b  
		PARM a  
		PARM personcomp  
		CALL t1 anotherComp 3
		NEQZ t1 l2 

# ------------------------------------------------------
l3:
		JUMP els1  

# ------------------------------------------------------
l2:
#IF situado en 38:5, termina en la etiqueta els2
if2:
		PARM c  
		PARM a  
		PARM personcomp  
		CALL t2 anotherComp 3
		NEQZ t2 l4 

# ------------------------------------------------------
l5:
		JUMP els2  

# ------------------------------------------------------
l4:
		PARM a  
		CALL t3 printPerson 1
		JUMP end1  

# ------------------------------------------------------
#ELSE situado en 40:12, termina en la etiqueta end1
els2:
		PARM c  
		CALL t4 printPerson 1
end1:
		JUMP end2  

# ------------------------------------------------------
#ELSE situado en 43:10, termina en la etiqueta end2
els1:
#IF situado en 44:5, termina en la etiqueta els3
if3:
		PARM c  
		PARM b  
		PARM personcomp  
		CALL t5 anotherComp 3
		NEQZ t5 l6 

# ------------------------------------------------------
l7:
		JUMP els3  

# ------------------------------------------------------
l6:
		PARM b  
		CALL t6 printPerson 1
		JUMP end3  

# ------------------------------------------------------
#ELSE situado en 46:12, termina en la etiqueta end3
els3:
		PARM c  
		CALL t7 printPerson 1
end3:
end2:
		EXIT   

# ------------------------------------------------------
#FUNCTION situado en 10:1
printPerson:
		WR   "Person Data is : " 9 
		RET    

# ------------------------------------------------------
#FUNCTION situado en 15:1
readPerson:
		:=[] t8 p 10
		READ t8 2 
		:=[] t9 p 14
		READ t9 5 
		:=[] t10 p 18
		READ t10 5 
		RET    

# ------------------------------------------------------
#FUNCTION situado en 22:1
personComp:
		:=[] t11 a 10
		:=[] t12 b 10
		<    t13 t11 t12
		RET  t13  
		RET  0  

# ------------------------------------------------------
#FUNCTION situado en 28:1
anotherComp:
		PARM b  
		PARM a  
		CALL t14 f 2
		RET  t14  
		RET  0  

# ------------------------------------------------------

# ------------------------------------------------------
