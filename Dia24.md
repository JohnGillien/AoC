Problema del Día 24 
Enunciado: El desafío consistía en resolver una serie de operaciones que se iban combinando unas con otras, partiendo de unos parámetros iniciales x… e y… con valores 0 o 1. El objetivo final es conseguir obtener los valores de las diferentes z…, para después, al ordenarlos, obtener un número binario que, al pasarlo a decimal, nos dé la solución del problema. 

Solución implementada: Se diseña una solución usando una estructura de árbol binario de ordenación y búsqueda. Tras varias ideas decidimos ordenar todos los nodos en un mismo árbol de manera alfabética 

Detalles técnicos: 

    Estructuras usadas: 

    TreeNode: Para definir la estructura del nodo de un árbol, con todas las variables necesarias. 

    Mejoras de eficiencia: 

    Al utilizar un árbol binario de búsqueda, ordenando los nodos alfabéticamente, resulta más sencillo buscar los operadores que se necesitan para una determinada operación. 

    Dificultades y soluciones: 

    Problemas con la definición de direcciones: Inicialmente, el recorrido no esta  definido de forma clara para todas las direcciones posibles, pero el uso de una lista con las direcciones permitió manejar todos los casos. 

    Manejo de datos duplicados: debemos asegurarnos de no visitar los mismos nodos múltiples veces, para ello, se usa una tabla hash que prevendrá esta duplicación. 

  Estrategia inicial descartada: 
 Se intentó abordar el problema realizando un árbol distinto para cada nodo z… de manera que hubiese tantos árboles como nodos z, pero resulto difícil de implementar . Para ello intenté analizar sobresaltados y sacar una solución a base de estos. Sin embargo, al revisar el problema más a fondo, me di cuenta de que esto no era necesario, ya que no existía una subestructura que pudiera resolverse de forma óptima mediante este enfoque. 

Motivo de descarte: La programación dinámica, al ser una solución que necesita dividir el problema en subproblemas y almacenar subresultados, introducía una complejidad innecesaria para este caso específico. En su lugar, una solución basada en tablas hash fue más eficiente y directa 	para resolver la tarea de verificar la unicidad y gestionar el estado de forma dinámica. Así, se 	optó por emplear hash en lugar de acumular y gestionar valores parciales. 
