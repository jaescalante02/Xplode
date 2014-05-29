* Tanto en src como en doc existen makefiles para compilar, con sus respectivos make clean.
* En xpcode existen casos de prueba.

  * Unitarios: Los que usábamos diariamente, sujetos a cambio para probar.
  * Correctos: Programas que mostrarán el reultado esperado.
  * Incorrectos: Verifican errores.

* Corrida ./xplode -a -t nombreArchivo
  * -t Imprime tabla de simbolos
  * -a Imprime ast
  
* Ambos flags son opcionales y van antes del nombre del archivo.
   
