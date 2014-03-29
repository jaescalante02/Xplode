#Xplode

*** Se decidió que se ignorará mayúsculas, confirmar ***

*** Se decidió permitir número variable de argumentos, no tenemos notacion ***

*** Posible pase de funciones como parametros (2da clase) ***

*** int[5:8][3:6] ***

*** sleep? ***

*** concat? i++, i--, solo instrucciones ***

        Version 1.0

Xplode es un compilador para los cursos de la cadena de Lenguajes de Programación de la
Univerisdad Simón Bolívar.

Xplode es un lenguaje imperativo fuertemente tipado. En su diseño se tomaron en cuenta peculiaridades de C/C++ y Pascal/Modula-2, entre otros,
en la búsqueda de ofrecer facilidades en torno al uso de Xplode, en base a experiencias previas.

Sin embargo, es necesario aclarar que no es ninguno de los lenguajes anteriormente señalados,
es un lenguaje simplificado que cumple ciertos parámetros obligatorios y 
en nuestro caso algunos extras, para acceder a otro nivel de expresividad.


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


Otros aspectos

Xplode entre sus características a tener en cuenta ignora el uso de mayúsculas,
es decir, el identificador FOO, FoO y foo se refieren a la misma variable, aplicando
lo mismo para todas las palabras reservadas.

Modos



Tipos
--------

* int
* char
* float
* arreglos
* types
* unions


##2 Gramática referencial

*** Por completar *** 

*version inicial*

La grámatica todavía presenta arreglos por lo que no se explicará en detalle en
esta versión, sin embargo copiamos la referencia al archivo xplode.y en donde se encuentra 
implementada.



##3 Estructura del programa

Un programa en Xplode se puede dividir en 3 secciones a las cuáles se deberán prestar 
atención.

1. Palabra de inicio: La cual es una señal de que es un programa en Xplode, además
de decidir en cual modo de ejecución se encuentra (ver sección 2).

2. Sección de definiciones: En este espacio se podrán definir los tipos, uniones,
variables globales, constantes y funciones que desea que existan en el programa.

3. Programa Principal: Sección que será llamada al iniciar la ejecución, iniciada por
un begin y finalizada en end.

##4 Alcance

##5 Tipos

Primitivos:

Son los tipos incluidos desde la implantacion del lenguaje.

Estos son int, bool, float y char.


Creados:

Xplode permite la definición de nuevos tipos dependiendo de las necesidades
del usuario.

types:

Representa una colección de tipos, los cuales pueden ser usados simultáneamente
con el operador de acceso '.'.

ej:

type foo{

int bar;
baz rom;

}



unions:

Representa una colección de uniones, los cuales **no** pueden ser usados simultáneamente
con el operador de acceso '.', es decir, solo se podrá mantener guardado el último
que posea una asignación.

ej:

union foo{

int bar;
baz rom;

}

procs:

Representa la firma de una función (ver sección 9), con su estructura
de devolución y parámetros. Usados para el pase de funciones como parámetros.

ej:

proc bool menorQue(person, person);

##6 Variables

##7 Arreglos

##8 Strings

write

##9 Funciones

...

2da clase


##10 Asignación

##11 Estructuras de control

if
else
while
for


##12 Expresiones



##13 Chequeos a tiempo de ejecución

Se espera que sea el menor número de verificaciones posibles

##14 Cosas que explotan!

Por ahora es díficil decirlo porque apenas hacemos los primeros chequeos.
