#Xplode

        Version 1.0



*** Se decidió que se ignorará mayúsculas, confirmar ***

*** Se decidió permitir número variable de argumentos, no tenemos notacion ***

*** Posible pase de funciones como parametros (2da clase) ***

*** Posible parámetros desordenados ***

*** int[5:8][3:6] ***

*** sleep? ***

*** concat? i++, i--, solo instrucciones ***

##1 Consideraciones léxicas

Símbolos "unitarios"
--------------------

* ( : Paréntesis derecho. Diversos usos.
* ) : Paréntesis izquierdo. Diversos usos.
* { : Llave izquierda. 
* } : Llave derecha
* [ : Bracket izquierda. Relacionado con arreglos
* ] : Bracket derecha. Relacionado con arreglos
* ; : Punto y coma. Separador
* . : Punto. Acceder a los atributos de un type.
* !
* +
* *
* -
* /

Simbolos no unitarios
----------------------

* := : Asignacion
* ==
* !=
* &&
* ||





Palabras reservadas
--------------------

Instrucciones
-------------

* program : Inicio del archivo
* begin : Inicio del main
* end : Final del main
* if 
* else
* while
* ?repeat?
* ?loop?
* for
* type
* union
* function *** Valorar por implementacion del parser ***
* return
* break
* continue
* exit

Valores
-------

* void
* true
* false
* enteros
* flotantes *** ?Con coma o con punto? ***
* String *** revisar regex rangex ***


Otros
------

* var : diferencia paso por referencia y por valor *** Caso de los arreglos, verificacion extraña ***
* // : comentario
* read
* write
* string(2)
* int("2")
* float(2)
* ?length?


Tipos
--------

* int
* char
* float
* arreglos
* types
* unions

ejemplo de un arreglo:    int[]   

*** ?multidimensional?.
como manejar rango variables
//quizas como matlab int[-4:8][15:30]
?notacion diferente en declaracion? 
?posible new? ***



##2 Gramática referencial

*** Por completar *** 

*version inicial*

grammar: 

       x_PROGRAM declaraciones main;

declaraciones: 

       // empty
       | declaraciones declaracion;
       
declaracion:

       decl_functions
       | types
       | decl_procs;
       | unions;

bloque: // al principio o donde sea? valorar

       declaraciones instrucciones;

instrucciones:

       instrucciones instruccion;

instruccion: 

       | asignacion
       | condicional
       | determinada
       | indeterminada
       | x_EXIT x_SEMICOLON;

asignacion: leftside x_ASSIGN expresion;

leftside: 
       x_ID
       | leftside x_DOT x_ID;

expresion:

       x_LPAR expresion x_RPAR
       | x_NOT expresion
       | x_MINUS expresion
       | expresion x_PLUS expresion
       | expresion x_MINUS expresion
       | expresion x_MULT expresion
       | expresion x_DIV expresion
       | expresion x_POWER expresion
       | expresion x_ASSIGN expresion
       | expresion x_EQ expresion
       | expresion x_NEQ expresion
       | expresion x_AND expresion
       | expresion x_OR expresion;

condicional: //conversar sobre poner el elif de nuevo

       x_IF expresion x_LBRACE bloque x_RBRACE;
       | x_IF expresion x_LBRACE bloque x_RBRACE x_ELSE x_LBRACE bloque x_RBRACE;

determinada: x_FOR x_LPAR expresion x_COMMA expresion x_COMMA expresion x_RPAR x_LBRACE bloque x_RBRACE;

indeterminada: x_WHILE expresion x_LBRACE bloque x_RBRACE;

decl_functions:

       x_FUNCTION tipo x_ID x_LPAR argumentos x_RPAR x_LBRACE bloque x_RBRACE;

decl_procs:

      x_PROC tipo x_ID x_LPAR tipos_proc x_RPAR;

tipos_proc:
  
     | list_tipos_proc tipo;

list_tipos_proc:

     | list_tipos_proc tipo x_COMMA;

tipos: 
 
       x_INT
       | x_CHAR
       | x_FLOAT
       | x_ID
       | tipos x_LBRACKET x_NUMBER x_RBRACKET;

types:

      x_TYPE x_ID x_LBRACE atributos x_RBRACE;

unions:

      x_UNION x_ID x_LBRACE atributos x_RBRACE;

atributos: 

      tipo x_ID x_SEMICOLON
      | atributos tipo x_ID x_SEMICOLON; 


main:

       x_BEGIN bloque x_END;


##3 Estructura del programa

*** Por completar ***

