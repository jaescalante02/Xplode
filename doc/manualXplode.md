#Xplode

        Version 1.1

Xplode es un compilador para los cursos de la cadena de Lenguajes de Programación de la
Univerisdad Simón Bolívar.

Xplode es un lenguaje imperativo fuertemente tipado. En su diseño se tomaron en cuenta 
peculiaridades de C/C++ y Pascal/Modula-2, entre otros, en la búsqueda de ofrecer 
facilidades en torno al uso de Xplode, en base a experiencias previas.

Sin embargo, es necesario aclarar que no es ninguno de los lenguajes anteriormente señalados,
es un lenguaje simplificado que cumple ciertos parámetros obligatorios y en nuestro caso 
algunos extras, para acceder a otro nivel de expresividad.


##1. Consideraciones léxicas

###Símbolos "unitarios"

* ( : Paréntesis derecho. Diversos usos.
* ) : Paréntesis izquierdo. Diversos usos.
* { : Llave izquierda. Uso en instrucciones compuestas.
* } : Llave derecha. Uso en instrucciones compuestas.
* [ : Bracket izquierda. Relacionado con arreglos
* ] : Bracket derecha. Relacionado con arreglos
* ; : Punto y coma. Separador.
* , : Coma. Separador de parametros y argumentos.
* . : Punto. Acceder a los atributos de un type.
* ! : Signo de Exlamación. Negación lógica.
* \+ : Signo más. Suma
* \* : Asterisco. Multiplicación.
* \- : Signo menos. Resta. Menos unitario.
* / : Slash. División. 
* < : Menor que. 
* \> : Mayor que. 


###Simbolos no unitarios

* := : Asignacion.
* == : Equivalencia.
* != : Inequivalencia.
* && : Doble ampersand. Conjunción lógica.
* || : Disyunción.
* // : Comentario. Alcanze hasta el final de la línea.
* ** : Potencia.
* <= : Menor o igual que. 
* \>= : Mayor o igual que. 
* ... : Puntos suspensivos. Usado para funciones con numero variable de parametros. 


###Palabras reservadas (Versión Clásica)

####Instrucciones

* program : Inicio del archivo.
* begin : Inicio del main.
* end : Final del main.
* if : Inicio del if.
* else : Instrucción else de un if.
* while : Inicio de iteración intedeterminada.
* for : Inicio de iteración determinada.
* type : Declaración de tipos. 
* union : Declaración de unions.
* proc : Declaración de la fima de funciones.
* function : Declaración de funciones.
* void : Usado para funciones que no retornan un valor.
* let : Declaración de variables.
* sleep : Detiene la ejecución por un número entero de segundos.
* return : Retorna el valor de una función.
* break : Salida incodicional de una iteración.
* continue : Salto a la siguiente iteración.
* exit : Termina la ejecución del programa.


####Valores

* true
* false
* enteros
* flotantes
* string


####Otros

* var : Diferencia paso por referencia y por valor *** Caso de los arreglos, verificacion extraña ***
* read : Lee por teclado y asigna en una variable.
* write : Escribe por salida estándar.


###Otros aspectos

Xplode entre sus características a tener en cuenta ignora el uso de mayúsculas,
es decir, el identificador FOO, FoO y foo se refieren a la misma variable, aplicando
lo mismo para todas las palabras reservadas.


####Modos

En Xplode se le dará la posibilidad al usuario de usar dos grupos de tokens diferentes.
Si la primera palabra del programa es _program_ se ejecutará con palabras que recuerdan
al uso cotidiano de los lenguajes de programación, mientras tanto si inicia con _xplodegram_,
se hará el análisis léxico con un grupo de palabras que recuerdan explosiones, explosivos, etc.
Está sección ya esta implementada, se logró generalizar el parser para ambos casos,
sim embargo las palabras claves de la version xplodegram no han sido decididas por lo 
que se insta al uso de la versión clasica.


###Tipos

* int
* bool
* char
* float
* arreglos
* types
* unions


##2. Gramática referencial

###Program
    start
      :  x_PROGRAM main 
      |  x_PROGRAM definition_list main 
    
    main
      : init_block x_BEGIN statement_list x_END  
      | init_block x_BEGIN declaration_list statement_list x_END 

###Definitions  
    definition_list
      : definition 
      | definition_list definition 
      | definition_list error 
      
    definition
      : def_union 
      | def_proc x_SEMICOLON 
      | def_type 
      | def_function 
      | declaration x_SEMICOLON 
      
    def_union
      : x_UNION x_ID x_LBRACE attribute_list x_RBRACE 
      
    def_type 
      :  x_TYPE x_ID x_LBRACE attribute_list x_RBRACE 
       
    attribute_list
      : type x_ID x_SEMICOLON 
      | attribute_list type x_ID x_SEMICOLON 
      
    def_proc
      : x_PROC function_type x_ID x_LPAR proc_type_list x_RPAR 
      
    proc_type_list
      : type 
      | proc_type_list x_COMMA type    
      
    def_function  
      : x_FUNCTION function_type x_ID x_LPAR x_RPAR block 
      | x_FUNCTION function_type x_ID x_LPAR function_parameters x_RPAR block 
      
    function_type
      : primitive_type 
      | x_VOID 
       
    function_parameters 
      : function_pars param_type x_ID x_COMMA x_EXTEND    
      | function_pars x_VAR param_type x_ID x_COMMA x_EXTEND 
      | function_pars param_type x_ID 
      | function_pars x_VAR param_type x_ID 
      | param_type x_ID 
      | x_VAR param_type x_ID 
      
    function_pars
      : param_type x_ID x_COMMA 
      | x_VAR param_type x_ID x_COMMA  //falta var 
      | function_pars param_type x_ID x_COMMA 
      | function_pars x_VAR param_type x_ID x_COMMA  //falta var
      
    param_type 
      : primitive_type 
      | x_ID 
      | param_type x_LBRACKET x_RBRACKET  
     
    primitive_type
      :  x_INT 
      | x_CHAR  
      | x_BOOL  
      | x_FLOAT 
      
    type 
      : primitive_type 
      | x_ID 
      | type x_LBRACKET INTEGER x_RBRACKET 
    
###Block  
    block  
      : init_block x_LBRACE declaration_list statement_list x_RBRACE 
      | init_block x_LBRACE statement_list x_RBRACE 
      | init_block declaration_list statement_list x_RBRACE 
      | init_block statement_list x_RBRACE 
    
###Declaration  
    declaration
      : x_LET declaration_type declaration_id_list  
    
    declaration_type
      : type   
    
    declaration_id_list
      : x_ID  
      | declaration_id_list x_COMMA x_ID 
        
    declaration_list
      : declaration x_SEMICOLON 
      | declaration  
      | declaration_list declaration x_SEMICOLON 
      | declaration_list declaration  

###Statements  

    statement
      : statement_simple 
      | statement_compound 
      
    statement_list
      : statement x_SEMICOLON 
      | statement_simple  
      | statement_compound 
      | statement_list statement x_SEMICOLON 
      | statement_list statement_simple 
      | statement_list statement_compound 
      
    statement_simple
      : statement_assign 
      | statement_read 
      | statement_write 
      | statement_sleep 
      | statement_function 
      | statement_break 
      | statement_continue 
      | statement_return 
      | statement_exit
      
    statement_compound
      : statement_for 
      | statement_while 
      | statement_if 
      
    statement_for
      : x_FOR x_LPAR for_init x_SEMICOLON for_condition x_SEMICOLON for_increment x_RPAR block
      | x_FOR error block 
      
    for_init
      : statement_assign   
    
    for_condition
      : expression 
      
    for_increment
      : statement_assign 
      
    statement_while
      : x_WHILE x_LPAR while_condition x_RPAR block 
      | x_WHILE error block 
      
    while_condition
      : expression 
      
    statement_if
      : x_IF x_LPAR if_condition x_RPAR block 
      | x_IF x_LPAR if_condition x_RPAR block statement_else 
      | x_IF error block 
      
    if_condition
      : expression 
      
    statement_else
      : x_ELSE block 
     
    statement_assign
      : variable x_ASSIGN expression 
      | variable error 
      
    statement_read
      : x_READ x_LPAR variable x_RPAR 
      
    statement_write
      : x_WRITE x_LPAR write_list x_RPAR 
      
    write_list
      : expression  
      | write_list x_COMMA expression 
      
    statement_sleep
      : x_SLEEP x_LPAR expression x_RPAR 
          
    statement_function
      : function 
      
    statement_break
      : x_BREAK 
      
    statement_continue
      : x_CONTINUE 
      
    statement_return
      : x_RETURN expression 
      
    statement_exit
      : x_EXIT x_LPAR x_RPAR 

###Expressions  
    expression
      : expression_unary  
      | expression x_PLUS expression 
      | expression x_MINUS expression 
      | expression x_MULT expression 
      | expression x_DIV expression 
      | expression x_POWER expression 
      | expression x_AND expression 
      | expression x_OR expression   
      | expression x_LESS expression 
      | expression x_LESSEQ expression 
      | expression x_GREATER expression 
      | expression x_GREATEREQ expression 
      | expression x_EQ expression 
      | expression x_NEQ expression 
      
    expression_unary
      : constant 
      | variable 
      | function 
      | expression_cast 
      | x_MINUS expression %prec x_UMINUS 
      | x_NOT expression 
      | x_LPAR expression x_RPAR 
      
    expression_cast
      : x_CTOI x_LPAR expression x_RPAR 
      | x_ITOC x_LPAR expression x_RPAR 
      | x_ITOF x_LPAR expression x_RPAR 
      | x_FTOI x_LPAR expression x_RPAR 
      
    constant
      : INTEGER 
      | FLOAT 
      | STRING  
      | CHAR   
      | x_TRUE 
      | x_FALSE 
      
    variable
      : variable_id  else 
      | variable x_DOT variable_id 
      
    variable_id
      : x_ID 
      | variable_id x_LBRACKET expression x_RBRACKET 
      
    function
      : x_ID x_LPAR function_arguments x_RPAR 
      | x_ID x_LPAR x_RPAR 
      
    function_arguments
      : expression 
      | function_arguments x_COMMA expression 



##3. Estructura del programa

Un programa en Xplode se puede dividir en 3 secciones a las cuáles se deberán prestar 
atención.

1. Palabra de inicio: La cual es una señal de que es un programa en Xplode, además
de decidir en cual modo de ejecución se encuentra (ver sección 2).

2. Sección de definiciones: En este espacio se podrán definir los tipos, uniones,
variables globales, constantes y funciones que desea que existan en el programa.

3. Programa Principal: Sección que será llamada al iniciar la ejecución, iniciada por
un begin y finalizada en end.


##4. Alcance

En Xplode el alcance es estático permitiendo niveles de anidamiento.
El anidamiento se define como cualquier bloque rodeado por llaves ('{' '}').
En estos se permite variables solapadas (ver sección 6) aunque no se permitirá
utilizar el nombre de definiciones para ningún otro uso, excepto que sean varibles
globales.

Para tomar en cuenta:

* Las variables deben ser declaradas, siempre al inicio del bloque y se mantendrán
vivas únicamente en ese alcance.

* Todas las definiciones son alcanzables desde cualquier punto del programa, incluso
  antes de ser definidas.
  

##5. Tipos

* Primitivos:

Son los tipos incluidos desde la implantacion del lenguaje.

Estos son `int`, `bool`, `float` y `char`.


* Creados:

Xplode permite la definición de nuevos tipos dependiendo de las necesidades
del usuario.

`types`

Representa una colección de tipos, los cuales pueden ser usados simultáneamente
con el operador de acceso '.'.

	type foo{

	int bar;
	baz rom;

	}

	...

	let foo f;
	f.bar = 3;
	...


`unions`

Representa una colección de uniones, los cuales **no** pueden ser usados simultáneamente
con el operador de acceso '.', es decir, solo se podrá mantener guardado el último
que posea una asignación.

	union foo{
	int bar;
	baz rom;
	}

	...
	let foo f;
	f.baz = 'a';
	f.rom = 3;
	// error
	// write(f.baz) 
	write(f.rom);
	...

`procs`

Representa la firma de una función (ver sección 9), con su estructura
de devolución y parámetros. Usados para el pase de funciones como parámetros.

	proc bool menorQue(person, person);
	function void sortPerson(menorQue f, person[] p);


##6. Variables

Una variable podrá ser cualquier identificador declarada con cualquier tipo válido.
Esto incluye arreglos y tipos definidos por el usuario. 

1. Variables solapadas: Se permite este tipo de variables, es decir, que si
dentro del cuerpo de una función existe una variable "foo" declarada
y más adelante dentro de la misma función existe un bloque que declara una
variable "foo", es esta la que tiene validez dentro de este bloque, ocultando el
valor de la primera variable foo, hasta que culmine dicho bloque. 

Hay excepciones a esta definición de variable solapada en Xplode. No se permite
solapar los nombres de variables en los siguientes casos: funciones, tipos,
uniones y procs. Puesto que estos se declaran unicamente en las sección de definiciones. 

2. Variables locales: Son las variables declaradas en la lista de parámetros
   formales o cuerpo de una función.

3. Variables globales: Son las variables declaradas fuera de alcances locales.

A continuación se incluyen los valores por defecto para las variables declaradas
bajo los siguientes tipos primitivos:

* `int`: 0
* `float`: 0.0
* `char`: ''
* `bool`: false

Esto ocurre ya que no se permite escribir líneas como:

	int a := 3;

Lo correcto en Xplode es declarar la variable a como un entero y en otra línea
asignarle el valor 3. 


##7. Arreglos

Un arreglo en Xplode esta compuesto por una cantidad positiva de elementos de un 
tipo válido en concreto, indexados linealmente desde el 0, con un número constante de 
elementos.

Los arreglos podrán pasarse como párametro de una función bajo el modo de referencia,
esto indica que podrán ser modificados y serán guardadas estas modificaciones al
salir de dicha función.

Estos también como una de sus características principales, son de asociación 
profunda, es decir, deberán ser asignados uno a uno (ver sección 10).

##8. Strings

Los strings en Xplode son una cadena de caracteres rodeados de comillas dobles y 
escritos en una sola línea que podran imprimirse al estar como parámetro en
la función write. A su vez se pueden asignar a un arreglo de caracteres.

	let char[12] xp;
	xp := " is awesome!";
	write("Xplode");
	write(xp);
	

##9. Funciones

###Definición

En Xplode la definición de las funciones recoge los parámetros en un orden específico
y referencial para la hora de su invocación y su tipo de retorno.

De la misma forma tendrá la rutina a ejecutar encerradas entre llaves con las mismas
instrucciones, sintaxis y alcance.

Sus parámetros tendrán la especificación de como son pasados, siendo las opciones
por valor o por referencia, esta última con un token var previo al tipo.

###Invocación

Se invocarán con una expresión del tipo especificado en el orden especificado y retornando
el tipo especifícado, toda especificación en su definición.

	bar(2*8 + 43, orr, 'w', menorQue).

Nota: Las funciones con tipo de devolución `void` serán tomadas como instrucciones.

###Funciones de número de parámetros variables

Xplode permite funciones con número de parámetros variables especificándose de la
siguiente forma:

	function foo(char a, int b, ...){ *instrucciones* }

Esta notación significa que a foo en su invocación le ingresará más de un tipo `int`.

Posibles invocaciones:

	foo('a',1), foo('a',1,2,3), foo('a',1,2,5,57,8,9,42).

####To-Do:

Para el manejo de está lista finita se tiene pensado el uso de los tokens
NEXT y LENGTH, teniendo como efecto obtener el siguiente en la lista o el tamaño
de la misma respectivamente, sin embargo esto no esta implementado aún.

###Funciones de segunda clase o pase de funciones como parámetros

El pase de funciones como parámetros se hará de la forma común, usando las definiciones
procs (ver sección 5), que pasan a ser un tipo y se podrá asignar una función al mismo
dentro del alcance de la función que usa el proc.


##10. Asignación

Efectúa una copia por valor para los tipos básicos. La instrucción
`LValue := RValue ;` copia el valor del lado derecho en la dirección indicada en
el lado izquierdo.

1. Solo se permite la asignación de tipos primitivos, de manera profunda.
2. Un `LValue` debe ser una variable o una posición de un arreglo. 
3. Ambos lados de la asignación deben tener el mismo tipo.
4. Los parámetros formales de una función son considerados variables.

##11. Estructuras de control

Las estructuras de control de Xplode están basadas en las de C/Java (es decir,
if/else/while/for) y tienen un comportamiento similar. Sin embargo, debido a que en
Xplode el token `;` es un finalizador, su uso es opcional en estas instrucciones. Por ejemplo:

    if (guardia) { 
        ...
    } 
	if (guardia2) { 
        ...
    } ;
    
Otro ejemplo:
    
    if (guardia) {
        ...
    } else {
        ...
    } ;
	if (guardia2) { 
        ...
    } ;

Ambos casos son válidos.
	
1. Las expresiones condicionales de las declaraciones `if` y `while` deben ser de tipo
   `bool`.
2. Una declaración de tipo `break` o `continue` sólo pueden aparecer en el
   cuerpo de ciclos `while` o `for`.
3. El valor de una declaración `return` (en caso de ser funciones que retornen
   algún tipo no vacío) deben ser del mismo tipo especificado en la firma de la
   función. 
4. Las cláusulas `if` y `else` deben ser precedidas por una instrucción
   de tipo bloque. Esta puede contener a su vez más instrucciones.
5. La variable de iteración en un ciclo acotado `for` no puede ser utilizada como
   `Lvalue`, así como no puede ser pasada por referencia en funciones que se
   encuentren en el cuerpo del ciclo.
6. La variable de iteración de un ciclo acotado `for` debe ser de un valor de
   tipo `int`.

##12. Expresiones

1. Ambos operandos en las operaciones (`+`, `-`, `*`, `/`, `<`, `>`, `<=` y `>=`)
   deben ser ambos enteros o flotantes, pero del mismo tipo.
2. Las operaciones (`<`, `>`, `<=` y `>=`) devuelven un valor de tipo `bool`.
3. El operador menos unario `-` aplica sobre enteros y flotantes y devuelve el
   mismo tipo del operando.
4. Ambos operandos deben ser del mismo tipo para las operaciones de igualdad 
   (`==`, `!=`), ya sea `int`, `float`, `bool` o `char`. El resultado de la operación será de 
   tipo `bool`.
5. Los operandos para las expresiones booleanas  (`!`, `&&` y `||`) aceptan sólo 
   argumentos de tipo `bool` y devuelven un valor del tipo `bool`.
6. Las operaciones booleanas `||` y `&&` no se evalúan completamente.
   Existe el corto circuito.
7. La conversión de tipos está limitada a: `int` <-> `float` y `int` <-> `char`.
   (`itof`, `ftoi`, `ctoi`, `itoc`).

A continuación se presentan, de menor a mayor, los operadores con sus 
precedencias:

    %nonassoc '==' '!=' (equivalencia, inequivalencia)
    %nonassoc '<' '<=' '>=' '>' (menor que, menor o igual que, mayor o igual que, mayor que)
    %left && '||' (conjunción, disyunción)
    %left '!' (negación)
    %left '+' - (suma, resta)
    %left '*' / (multiplicación, división)
    %left '**' (potencia)
    %left '-' (menos unario)

##13 Chequeos a tiempo de ejecución

Se espera que sea el menor número de verificaciones posibles.

Las existentes hasta el momento se enumeran a continuación:

* Comprobación del índice de un arreglo.
* Acceso correcto al campo de un union.
* División entre 0.
* Overflow.

##14 Cosas que explotan!

*  Error léxico.
*  Uso de variable no declarada.
*  Redeclaración de una variable en el mismo bloque.
*  Errores de tipos. (expresiones, asignacion, parámetros, condición del if/while/for,...)
*  Conversión inválida de tipos.
*  Acceso a campos invalidos de un type.
*  Uso del break/continue fuera de una iteración.
*  Uso del return fuera de una función.
*  Errores de ejecución. (Ver sección anterior) 

##15 Ideas explosivas

* Permitir concat de strings/arreglo de caracteres.
* Azúcar sintáctica. `i++`  `i--` (Solo instrucciones)
* Establecer mensajes de error relacionado con explociones.

